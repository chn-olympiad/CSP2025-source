#include <bits/stdc++.h>
#define int long long
#define st first
#define nd second
#define MP make_pair
#define rep(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N=2e6+5,mod=1e9+7;
int quickpow(int a,int b,int mod){
    int ans=1;
    while(b){
        if(b&1)ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
int dp[N],xorsum[N],n,k,a[N],cnt[N];
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    memset(cnt,0x3f,sizeof(cnt));
    scanf("%d %d",&n,&k);
    rep(i,1,n+1)scanf("%d",&a[i]);
    rep(i,1,n+1)xorsum[i]=xorsum[i-1]^a[i];
    cnt[0]=0;
    rep(i,1,n+1){
        dp[i]=dp[i-1];
        int nd=cnt[xorsum[i]^k];
        cnt[xorsum[i]]=i;
        if(nd>mod)continue;
        dp[i]=max(dp[i],dp[nd]+1);
    }
    printf("%d",dp[n]);
    return 0;
}
