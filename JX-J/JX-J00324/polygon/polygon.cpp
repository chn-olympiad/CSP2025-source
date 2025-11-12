#include<bits/stdc++.h>
using namespace std;
int n;int a[5010];long long l=1,r=1,ans=0;
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
sort(a+1,a+n+1);
if(a[n]==1){
    for(int j=3;j<=n;j++){
    for(int i=1;i<=n;i++){
        l=l*i%998244353;
        if(i==j)r=l;
       if(i==n-j)ans=l;
      }
    }
    ans=l/(r*ans%998244353)%998244353;
    cout<<ans;
    return 0;
}
if(n==3){
  if(2*a[n]<a[1]+a[2]+a[3]){
    cout<<"1";
    return 0;
  }
  else{
    cout<<"0";
  }
}
return 0;
}
