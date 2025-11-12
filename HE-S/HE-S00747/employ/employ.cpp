#include<bits/stdc++.h>
using namespace std;
using llt=long long;
const llt N=510,mod=998244353;
llt n,m,dp[N][N],c[N],d[N],id[N],ans;char s[N];
/*llt tms[N],inv[N],invt[N];
struct S1
{
    void solve()
    {
        inv[1]=1;for(int i=2;i<N;i++) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
        for(int i=1;i<=n;i++)
        dp[0][0]=1;
        for(int i=0;i<=n;i++)
        {
            for(int k=0;k<=n;++k)
            {
                for(int w=0;w<=n;w++)
                    for(int j=0;j<=d[i];j++)
                    {
                        s[k+1][w]=dp[k][w]*k%mod;
                        s[k][w]=
                    }   
            }
        }
    }
}s1;*/
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++) scanf("%lld",&c[i]),d[i]++,id[i]=i;
    do
    {
        llt cnt=0;
        for(int i=1;i<=n;i++) if(s[i]=='0'||cnt>=c[id[i]]) cnt++;
        if(cnt<=n-m) ++ans;
    }while(next_permutation(id+1,id+1+n));
    printf("%lld\n",ans);
    return 0;
}