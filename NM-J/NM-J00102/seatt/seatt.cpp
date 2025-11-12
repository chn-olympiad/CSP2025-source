#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
using namespace std;
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdin);
int m,n,x,z,y,b,c;
cin>>m>>n;
int a[m*n];
for(int i=0;i<n*m;i++){
    cin>>a[i];
}
x=a[0];
for(int i=0;i<n*m;i++){
    if(a[i]>a[i+1]){
      z=a[i+1];
      a[i+1]-a[i];
      a[i]=z;
    }
}
for(int i=0;i<n*m;i++){
    if(a[i]==x){
        y=i;
    break;
    }
}
b=y/n;
c=y%n;
cout<<b+1
if(c%2==0){
   cout<<n-c;
}
else{
    cout<<c;
}


return 0;
}
