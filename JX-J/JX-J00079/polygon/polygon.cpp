#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e3+5,mod=998244353;
ll n,a[maxn],ans,dp[maxn],dp1[maxn],dp2[maxn];
void init(){
    dp[2]=0;
    dp1[2]=0;
    dp2[2]=0;
    for(int i=3;i<=maxn;i++){
        dp2[i]=dp2[i-1]+1;
    }
    for(int i=3;i<=maxn;i++){
        dp1[i]=dp1[i-1]+dp2[i];
    }
    for(int i=3;i<=maxn;i++){
        dp[i]=dp[i-1]+dp1[i];
    }
    for(int i=3;i<=maxn;i++){
        dp[i]%=mod;
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    init();
    printf("%lld\n",dp[n]%mod);
    return 0;
}
