#include<iostream>
using namespace std;

int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
long long n,m,a[n*m],h=0,z,w;
cin>>n>>m;
h=n*m;
for(int i=1;i<=h;i++){
    cin>>a[h];
}
if(a[0]=100){
    z=1;
    w=1;}
else(a[0]<100&&a[0]>=90);
  {
    z=1;
    w=100-a[0];}
    if(w<n);{
        z=2;
        w=w-n;}
  cout<<z<<w;












return 0;
}
