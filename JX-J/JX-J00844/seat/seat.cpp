#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],x,y,b,c;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n*m;i++){
    cin>>a[i];
}
b=a[1];
sort(a+1,a+n*m+1);
for(int i=1;i<=n*m;i++){
if(a[n*m-i+1]==b){
   c=i;
   break;
}
}
y=c/n;
if(c%n>0){
y++;
}
if(y%2==0){
x=n-c%n+1;
}
else{
x=c%n;
if(x==0){
    x=n;
}
}
cout<<y<<" "<<x;
}
