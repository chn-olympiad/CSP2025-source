#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int n,ans,a[5001],sum[5001],dp[2500001];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=a[i]+sum[i-1];
    for(int i=3;i<=n;i++)
    {
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int j=1;j<i;j++)
        {
            for(int k=sum[i-1];k>=a[j];k--)
            {
                dp[k]=(dp[k]+dp[k-a[j]])%Mod;
            }
        }
        for(int j=a[i]+1;j<=sum[i-1];j++) ans=(ans+dp[j])%Mod;
    }
    cout<<ans;
    return 0;
}
