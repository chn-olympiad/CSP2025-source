#include<bits>c++.h
using namespace std;
int main()
{
int a{}=[100010];
int b{}=[10010];
int s=0,x=0;
for(int=0;i<=100010;i++){
cin>>a[i];
}
for(int i=0;i<=100010;i++){
if(a[i]%1=>=1)
{
  for(int j=0;i<=100010;j++)
  b[j]=a[i];
}
}
for(int j=0;j<=100010;j++)
{
for(int i=0;i<=100010;i++){
if(b[j]>=b[i])
s=0;
}else{
b[j]=b[i];
}
}
for(int i=0;i<=100010;i++){
if(b[i]>=1){
s++;
}
}
for(int i=0;i<=100010;i++){
a+=b[i]*10*s;
}
cout<<a;
return 0;
}
