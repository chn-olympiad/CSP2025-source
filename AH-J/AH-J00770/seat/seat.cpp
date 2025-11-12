#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
return a>b;}
int main(){

freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m;
cin>>n>>m;
int a[10*n*m];
for(int i=1;i<=n*m;i++){
cin>>a[i];
}
int x=a[1];
sort(a,a+n*m,cmp);
int y;
for(int i=1;i<=n*m;i++){
if(a[i]==x){
y=i;}}
int mm,nn;
if(y%m==0){
mm=y/m;}else{
mm=y/m+1;}
if(mm%2!=0){
if(y%n==0){
nn=n;}else{
nn=y%n;}}else{
if(y%n==0){
nn=1;}else{
nn=n+1-(y%n);}}
cout<<mm<<" "<<nn;

    return 0;
}
