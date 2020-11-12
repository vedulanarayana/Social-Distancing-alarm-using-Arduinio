const int trigPin = 12;
const int echoPin = 13;
const int buzzer = 8;
long duration;
int distanceCm, distanceInch;
void setup()
{
Serial.begin(9600); 
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(buzzer,OUTPUT);
}
void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;
distanceInch = duration*0.0133/2;
Serial.println("Distance: ");
Serial.println(distanceCm);
// Change the Distance according to requirement in cm 
if(distanceCm < 100)
{
   Serial.print("distance= ");  
   Serial.print(distanceCm);
   // change the buzzer frequency and duration
   tone(buzzer,600,500);
}
else 
{
  digitalWrite(buzzer,LOW);
}
}
