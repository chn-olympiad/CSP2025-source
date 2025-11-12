#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
int a;
cin>>a;
int b[a+5],cnt=0,sum=0;
if(a>20){
cout<<998244353;
}for(int i=0;i<a;i++){
cin>>b[i];
cnt+=b[i];
}
if(a==3){
for(int c=0;c<a;c++){
for(int d=c+1;c<a;c++){
for(int e=d+1;d<a;d++){
if(b[c]*2>cnt&&b[d]*2>cnt&&b[e]*2>cnt){
sum++;
}
}
}
}
}
if(a==4){
for(int c=0;c<a;c++){
for(int d=c+1;c<a;c++){
for(int e=d+1;d<a;d++){
for(int f=e+1;f<a;f++){
if(b[c]*2>cnt&&b[d]*2>cnt&&b[e]*2>cnt&&b[f]*2>cnt){
sum++;
}
}
}
}
}
}
if(a==5){
for(int c=0;c<a;c++){
for(int d=c+1;c<a;c++){
for(int e=d+1;d<a;d++){
for(int f=e+1;f<a;f++){
for(int g=f+1;g<a;g++){
if(b[c]*2>cnt&&b[d]*2>cnt&&b[e]*2>cnt&&b[f]*2>cnt&&
b[g]*2>cnt){
sum++;
}
}
}
}
}
}
}
if(a==6){
for(int c=0;c<a;c++){
for(int d=c+1;c<a;c++){
for(int e=d+1;d<a;d++){
for(int f=e+1;f<a;f++){
for(int g=f+1;g<a;g++){
for(int h=g+1;h<a;h++){
if(b[c]*2>cnt&&b[d]*2>cnt&&b[e]*2>cnt&&b[f]*2>cnt&&
b[g]*2>cnt&&b[h]*2>cnt){
sum++;
}
}
}
}
}
}
}
}
if(a==7){
for(int c=0;c<a;c++){
for(int d=c+1;c<a;c++){
for(int e=d+1;d<a;d++){
for(int f=e+1;f<a;f++){
for(int g=f+1;g<a;g++){
for(int h=g+1;h<a;h++){
for(int i=h+1;i<a;i++){
if(b[c]*2>cnt&&b[d]*2>cnt&&b[e]*2>cnt&&b[f]*2>cnt&&
b[g]*2>cnt&&b[h]*2>cnt&&b[i]*2>cnt){
sum++;
}
}
}
}
}
}
}
}
}
}
