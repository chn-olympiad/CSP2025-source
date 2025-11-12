#include <bits/stdc++.h>
using namespace std;

int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
int n,k,a1,a2,a3,a4,x=0;
cin>>n>>k>>a1>>a2>>a3>>a4;
if(a1==k){
  x++;
}
if(a2==k){
  x++;
}
if(a3==k){
  x++;
}
if(a4==k){
  x++;
}
if((a1-a2==k)&&(a1>0,a2>0)){
  x++;
}
if((a1-a3==k)&&(a1>0,a3>0)){
  x++;
}
if((a1-a4==k)&&(a1>0,a4>0)){
  x++;
}
if((a2-a1==k)&&(a2>0,a1>0)){
  x++;
}
if((a2-a3==k)&&(a2>0,a3>0)){
  x++;
}
if((a2-a4==k)&&(a2>0,a4>0)){
  x++;
}
if((a3-a1==k)&&(a3>0,a1>0)){
  x++;
}
if((a3-a2==k)&&(a3>0,a2>0)){
  x++;
}
if((a3-a4==k)&&(a3>0,a4>0)){
  x++;
}

if((a4-a1==k)&&(a4>0,a1>0)){
  x++;
}
if((a4-a2==k)&&(a4>0,a2>0)){
  x++;
}
if((a4-a3==k)&&(a4>0,a3>0)){
  x++;
}
cout<<x;
return 0;
}
