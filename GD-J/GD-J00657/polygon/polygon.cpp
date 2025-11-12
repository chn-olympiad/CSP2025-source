#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=998244353;

int n,ans;
int a[5005];
int dp[5005];

int quick_pow(int a,int b){
  int res=1;
  for(;b;b>>=1){
    if(b&1) res=res*a%MOD;
    a=a*a%MOD;
  }
  return res;
}

signed main(){
  freopen("polygon.in","r",stdin);
  freopen("polygon.out","w",stdout);
  ios::sync_with_stdio(0);cin.tie(0);

  cin>>n;

  for(int i=1;i<=n;i++){
    cin>>a[i];
  }

  sort(a+1,a+n+1);

  dp[0]=1;
  for(int i=1;i<=n;i++){
    int del=0;

    if(i>=3){
      for(int j=0;j<=a[i];j++){
        del=(del-dp[j]+MOD)%MOD;
        // cout<<dp[j]<<' ';
      }
      // cout<<'\n';
      ans=(ans+quick_pow(2,i-1)+del)%MOD;
    }

    // cout<<del<<'\n';

    for(int j=5000;j>=a[i];j--){
      dp[j]=(dp[j]+dp[j-a[i]])%MOD;
    }
    // cout<<ans<<'\n';
  }

  cout<<ans<<'\n';

}