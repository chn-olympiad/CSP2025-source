#include<bits/stdc++.h>
using namespace std;
int a[5005],n,cnt;
int s3(int a,int b,int c){
int sum=max(a,max(b,c));
if(sum<a+b+c){
return 1;
}
else return 2;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
cin>>a[i];
}
if(n==3){
if(s3(a[1],a[2],a[3])==1)
{
  int ans=1;
  cout<<ans%998244353;
  return 0;
}
else if(s3(a[1],a[2],a[3])==2){
int ans=0;
  cout<<ans%998244353;
  return 0;
}
}
else {
for(int l=1;l<=n-2;l++){
for(int j=l+1;j<=n-1;j++){
for(int y=j+1;y<=n;y++){
if(s3(a[l],a[j],a[y])==1)
    cnt++;
}
}
}
}
cout<<cnt%998244353;
return 0;
}
