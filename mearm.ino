#include <Servo.h>


//Joy Stick analog pins
#define x1 A0
#define y1 A1
#define x2 A2
#define y2 A3

Servo mS,rS,lS,cS; //middle Servo,right Servo,left Servo,claw Servo

void setup() {

  Serial.begin(9600);
  
  lS.attach(11);
  cS.attach(10);
  rS.attach(9);
  mS.attach(6);

  pinMode(x1,INPUT);
  pinMode(y1,INPUT);
  pinMode(x2,INPUT);
  pinMode(y2,INPUT);

  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(6,OUTPUT);

  mS.write(90);
  lS.write(90);
  rS.write(90);
  cS.write(90);
  

}


void loop(){

  
  setAngle(mS,y1);
  setAngle(rS,x1);
  setAngle(lS,y2);
  setAngle(cS,x2);

  
  

  delay(40);

}

void setAngle(Servo s,int joyD){

  int angle,val;

  angle = s.read();
  val = analogRead(joyD);
  
  
  val = map(val,0,1023,-5,5);


  if(joyD == x1 || joyD == x2){


  if(val<-1){

    angle -= 5;
    angle = max(0,angle);
    
  }
  else if(val > 0){
    
    angle +=5;
    angle = min(180,angle);
    
  }
    
    
  }
  else{


  if(val<-1){

    angle += 5;
    angle = min(180,angle);
    
  }
  else if(val > 0){
    
    angle -=5;
    angle = max(0,angle);
    
  }
    
    
  }


  Serial.println(angle);
  s.write(angle);
  
}



void testJoystick(){

  int y1Val,y2Val,x1Val,x2Val;

//TEST JOYSTICK
  //test middle servo
  y1Val = analogRead(y1);
  Serial.print("y1 0 to 1023 val: ");
  Serial.print(y1Val);
  y1Val = map(y1Val,0,1023,-5,5);
  Serial.print(",y1 -5 to 5: ");
  Serial.println(y1Val);
  //Result : 
  //default: y1 0 to 1023 val: 506,y1 -5 to 5: -1
  //up: y1 0 to 1023 val: 0,y1 -5 to 5: -5
  //down: y1 0 to 1023 val: 991,y1 -5 to 5: 4


  //test left servo
  x1Val = analogRead(x1);
  Serial.print("x1 0 to 1023 val: ");
  Serial.print(x1Val);
  x1Val = map(x1Val,0,1023,-5,5);
  Serial.print(",x1 -5 to 5: ");
  Serial.println(x1Val);
  //Result : 
  //default: x1 0 to 1023 val: 469,x1 -5 to 5: -1
  //right: x1 0 to 1023 val: 933,x1 -5 to 5: 4
  //left: x1 0 to 1023 val: 0,x1 -5 to 5: -5


  //test right servo
  y2Val = analogRead(y2);
  Serial.print("y2 0 to 1023 val: ");
  Serial.print(y2Val);
  y2Val = map(y2Val,0,1023,-6,6);
  Serial.print(",y1 -5 to 5: ");
  Serial.println(y2Val);
  //Result : 
  //default: y2 0 to 1023 val: 528,y2 -5 to 5: 0
  //up: y2 0 to 1023 val: 58,y2 -5 to 5: -5
  //down: y2 0 to 1023 val: 1018,y2 -5 to 5: 4



  //test claw servo
  x2Val = analogRead(x2);
  Serial.print("x2 0 to 1023 val: ");
  Serial.print(x2Val);
  x2Val = map(x2Val,0,1023,-5,5);
  Serial.print(",x2 -5 to 5: ");
  Serial.println(x2Val);
  //Result : 
  //default: x2 0 to 1023 val: 469,x2 -5 to 5: 0
  //right: x2 0 to 1023 val: 1023,x2 -5 to 5: 5
  //left: x2 0 to 1023 val: 90,x2 -5 to 5: -5
}
