#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
inline void add(int &a,int b) { a=(a+b<mod?a+b:a+b-mod); }
int jc[510];
int n,m;
int s[510],c[510],cnt[510],cnt1[510];
int dp[2][510][510];
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    jc[0]=1;
    for(int i=1; i<=505; ++i) jc[i]=jc[i-1]*i%mod;
    cin>>n>>m;
    string ss; cin>>ss;
    for(int i=1; i<=n; ++i) s[i]=ss[i-1]-'0',cnt1[i]=cnt1[i-1]+s[i];
    for(int i=1; i<=n; ++i) cin>>c[i],++cnt[c[i]];
    for(int i=1; i<=n; ++i) cnt[i]+=cnt[i-1];
    dp[0][0][0]=1;
    for(int i=0; i<n; ++i)
    {
        memset(dp[i+1&1],0,sizeof(dp[i+1&1]));
        for(int j=0; j<=i; ++j)
        {
            for(int k=0; k<=j; ++k)
            {
                if(dp[i&1][j][k]==0) continue;
                if(s[i+1]==1)
                {
                    add(dp[i+1&1][j+1][k],dp[i&1][j][k]);
                    int tmp=dp[i&1][j][k]*max(cnt[i-j]-cnt1[i]+(j-k),0ll)%mod;
                    add(dp[i+1&1][j+1][k+1],tmp),add(dp[i+1&1][j][k],tmp);
                    //add(dp[i+1][j+1][k+1],dp[i][j][k]*max(cnt[i-j]-l,0ll)%mod);
                    //add(dp[i+1][j][k],dp[i][j][k]*max(cnt[i-j]-l,0ll)%mod);
                }
                else add(dp[i+1&1][j][k],dp[i&1][j][k]);
            }
        }
    }
    int ans=0;
    for(int j=m; j<=n; ++j)
    {
        for(int k=0; k<=j; ++k)
        {
            if(dp[n&1][j][k]==0) continue;
            int nowans=dp[n&1][j][k]*jc[n-cnt1[n]+(j-k)]%mod;
            if(k%2==0) add(ans,nowans);
            else add(ans,mod-nowans);
        }
    }
    cout<<ans;
    return 0;
}
