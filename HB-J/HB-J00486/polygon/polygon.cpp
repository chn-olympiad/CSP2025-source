#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[11],m[11],q,usd[11];
void xz(int bs,int i,int s){
  if(i==bs+1){
    if(s>m[bs]*2){
        q++;
    }return;
  }for(int j=i;j<=n-i+1;j++){
      if(usd[j]!=1){
        m[i]=a[j];
        usd[j]=1;
        xz(bs,i+1,s+a[j]);
      }usd[j]=0;
  }
}
int main(){
  freopen("polygon.in","r",stdin);
  freopen("polygon.out","w",stdout);
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }sort(a+1,a+n+1);
  for(int l=3;l<=n;l++){
    xz(l,1,0);
  }cout<<q;
  return 0;
}
