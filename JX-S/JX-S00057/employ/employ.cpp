#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=505,mod=998244353;
ll n,m,a[maxn],dp[maxn];
char s[maxn];
void init(){
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=maxn;i++){
        dp[i]=dp[i-1]*i;
        dp[i]%=mod;
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%lld%lld%s",&n,&m,s+1);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    init();
    printf("%lld",dp[n]%mod);
    return 0;
}

