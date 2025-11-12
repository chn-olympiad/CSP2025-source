#include<bits/stdc++.h>
using namespace std;
 int t,n,m;
 int x[10010],y[10010],z[10010];
 int love=0;
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
cin>>t;
for(int j=1;j<=t;j++){
cin>>n;
m=n/2;
for(int i=0;i<=n;i++){
    cin>>x[i]>>y[i]>>z[i];
 }
 int X=0,Y=0,Z=0;

for(int i=0;i<=n;i++){
if(x[i]>y[i] and x[i]>z[i] and X<=m){
 love+=x[i];
 X++;}
if(y[i]>x[i] and y[i]>z[i] and Y<=m){
 love+=y[i];
 Y++;}
if(z[i]>y[i] and z[i]>x[i] and Z<=m){
 love+=z[i];
 Z++;}
 }

cout<<love<<endl;
}
return 0;}
