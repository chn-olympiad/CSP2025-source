#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,a[5005],dp[5005],ans;
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        if(i>=3){
            for(int j=a[i]+1;j<=5001;j++)ans=(ans+dp[j])%mod;
        }
        for(int j=5001;j>5000-a[i];j--){
            dp[5001]=(dp[5001]+dp[j])%mod;
        }
        for(int j=5000;j>=a[i];j--){
            dp[j]=(dp[j]+dp[j-a[i]])%mod;
        }
    }
    printf("%lld",ans);
    return 0;
}
