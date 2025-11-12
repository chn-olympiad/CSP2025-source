#include<iostream>
#include<algorithm>
using namespace std;
long long dp[10005],n,ans=0;long long u[5005];
int main(){
  freopen("polygon.in","r",stdin);
  freopen("polygon.out","w",stdout);
  cin>>n;
  dp[0]=1;
  for(long long j=0;j<n;j++){
    cin>>u[j];
  }
  sort(u,u+n);
  for(long long j=0;j<n;j++){
    for(long long k=u[j]+1;k<=5001;k++){
        ans+=dp[k];
        ans%=998244353;
    }
    for(long long k=5001;k>=0;k--){
        if(k+u[j]>5000){
            dp[5001]+=dp[k];
            dp[5001]%=998244353;
        }else{
            dp[k+u[j]]+=dp[k];
            dp[k+u[j]]%=998244353;
        }
    }
  }
  cout<<ans%998244353;
  return 0;
}
