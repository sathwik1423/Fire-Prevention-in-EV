#include <Servo.h>
Servo myservo;
int pos = 0;
void setup()
{
pinMode(11, OUTPUT);
pinMode(8, INPUT);
pinMode(A0, INPUT);
myservo.attach(9);
digitalWrite(11, LOW);
}
void loop()
{
int sensorValue = 0;
sensorValue = analogRead(A0);
delay(1000);
Serial.print("Temp:");
Serial.print(sensorValue/2);
Serial.print((char)223);
Serial.print("C\n");
if((sensorValue/2)>=46)
{
digitalWrite(11, HIGH);
//Serial.println("gsm");
Serial.println("AT+CMGF=1"); //To send SMS in Text Mode
delay(1000);
Serial.println("AT+CMGS=\"+916281042872\"\r"); // change to the phone number you using
delay(1000);
Serial.println("Alert! High Temperature detected\n");//the content of the message
delay(200);
Serial.print("Temp:");//the content of the message
delay(200);
Serial.print(sensorValue/2);
Serial.print((char)223);
Serial.print("C\n");
delay(200);
digitalWrite(11, LOW);
}
else if(digitalRead(8)==LOW)
{
digitalWrite(11, HIGH);
lcd.clear();
lcd.print("Slot Available");
lcd.clear();
lcd.print("Opening.....");
for (pos = 100; pos >= 0; pos -= 1)
{ // goes from 0 degrees to 180 degrees
// in steps of 1 degree
myservo.write(pos); // tell servo to go to position in variable 'pos'
delay(15);
}
delay(300);
lcd.clear();
lcd.print("Closing.....");
delay(1000);
for (pos = 0; pos <= 100; pos += 1)
{ // goes from 180 degrees to 0 degrees
myservo.write(pos); // tell servo to go to position in variable 'pos'
delay(15);
}
lcd.clear();
Serial.println("AT+CMGF=1"); //To send SMS in Text Mode
delay(1000);
Serial.println("AT+CMGS=\"+916281042872\"\r"); // change to the phone number you using
delay(1000);
Serial.println("Alert! Fire detected\n");//the content of the message
delay(200);
digitalWrite(11, LOW);
}
else
{
}
}
