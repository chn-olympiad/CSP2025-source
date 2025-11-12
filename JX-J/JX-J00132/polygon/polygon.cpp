#include<bits/stdc++.h>
using namespace std;
int n;
int a[4];
int maxx;
int main(){
//freopen("polygon.in","r",stdin);
//freopen("polgyon.ans","w",stdout);
cin>>n;
if(n<3){
cout<<0;
return 0;}
for(int i=1;i<=3;i++){
cin>>a[i];
maxx=max(maxx,a[i]);
}
if(2*maxx<a[1]+a[2]+a[3]){

cout<<1;}
else cout<<0;
return 0;
}
