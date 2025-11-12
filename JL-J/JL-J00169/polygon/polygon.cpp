#include<bits/stdc++.h>
using namespace std;
int n,a[5050],m;
int main()
{
  freopen("polygon.in","r",stdin);
  freopen("polygon.out","w",stdout);
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  if(n<=3){
    m=0;
    if(a[1]>=m){
        m=a[1];
    }
    if(a[2]>=m){
        m=a[2];
    }
    if(a[3]>=m){
        m=a[3];
    }
    if(a[1]+a[2]+a[3]>2*m){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
  }
    return 0;
}
