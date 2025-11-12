#include<bits/stdc++.h>
using namespace std;
int main(){
//preopen("club.in","r",stdin);
//preopen("club.out","w",stdout);
int a,b,c=0,d=0,e=0,f=0,g=0,h=0;
int o1[100001],o2[100001],o3[100001];
cin>>a;
for(int i=0;i<a;i++){
cin>>b;
for(int j=0;j<b;j++){
cin>>o1[j]>>o2[j]>>o3[j];
}
}
if(b<=4){
for(int i=0;i<b;i++){
if(o1[i]<=o1[i+1]){
c=o1[i+1];
}
if(o2[i]<=o2[i+1]){
d=o2[i+1];
}
if(o3[i]<=o3[i+1]){
e=o3[i+1];
}
}
cout<<c+d+e;	
}
else{
for(int i=0;i<b;i++){
if(f=b/2){
for(int j=0;j<b;j++){
o1[j]=0;
}
}
if(g=b/2){
for(int j=0;j<b;j++){
o2[j]=0;
}
}
if(h=b/2){
for(int j=0;j<b;j++){
o3[j]=0;
}
}			
if(o1[i]<=o1[i+1]){
c=o1[i+1];f++;
}
if(o2[i]<=o2[i+1]){
d=o2[i+1];g++;
}
if(o3[i]<=o3[i+1]){
e=o3[i+1];h++;
}
}	
}
cout<<e+d+c;
return 0;
}

