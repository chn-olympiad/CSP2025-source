#include<iostream>
#include<cstdio>
using namespace std;
int n,k,a[101],x,y,s;
int main(){
  freopen("xor.in","r",stdin);
  freopen("xor.out","w",stdout);
  cin>>n>>k;
  for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1) x++;
        else y++;
  }if(k==0&&x==n){
    if(n<=100) s=n/2;
  }else if(k==0&&x+y==n){
      for(int i=1;i<=n;i++){
        if(a[i]==0) s++;
        if(a[i]==1&&a[i+1]==1){
            s++;
            i++;
        }
      }
  }else if(k==1&&x+y==n) s=x;
  cout<<s;
  return 0;
}
