#include <bits/stdc++.h>
using namespace std;
#define INPUT_FILE "employ.in"
#define OUTPUT_FILE "employ.out"
using ll = long long;
constexpr int N=503;
constexpr int MOD=998244353;
int n,m,c[N],fac[N<<1],inv[N<<1];
string str;
bool check_all1()
{
    for(int i=1;i<=n;i++)
        if(str[i]!='1') return false;
    return true;
}
void init()
{
    fac[0]=1;
    for(int i=1;i<N<<1;i++)
        fac[i]=(ll)fac[i-1]*i%MOD;
    inv[0]=inv[1]=1;
    for(int i=2;i<N<<1;i++)
        inv[i]=(ll)(MOD-MOD/i)*inv[MOD%i]%MOD;
    for(int i=2;i<N<<1;i++)
        inv[i]=(ll)inv[i]*inv[i-1]%MOD;
}
inline ll combine(int x,int y)
{
    if(x<0||y<0||x>y) return 0;
    return (ll)fac[x]*inv[y]%MOD*inv[x-y]%MOD;
}
int dp[1<<20][20];
inline void upd(int &x,int y){(x+=y)>=MOD&&(x-=MOD);}
int main()
{
    cin>>n>>m>>str;
    init();
    str="#"+str;
    for(int i=1;i<=n;i++) cin>>c[i];
    if(n<=20)
    {
        dp[0][0]=1;
        for(int i=0;i<1<<n;i++)
        {
            const int cnt=__builtin_popcount(i);
            for(int j=((1<<n)-1)^i;j;j-=(j&-j))
            {
                const int pos=__builtin_ctz(j);
                if(str[cnt+1]=='1')
                for(int k=0;k<=cnt;k++)
                    if(k>=c[pos+1]) upd(dp[i|(1<<pos)][k+1],dp[i][k]);
                    else upd(dp[i|(1<<pos)][k],dp[i][k]);
                else for(int k=0;k<=cnt;k++) upd(dp[i|(1<<pos)][k+1],dp[i][k]);
            }
        }
        int res=0;
        for(int i=0;i<=n-m;i++)
        upd(res,dp[(1<<n)-1][i]);
        cout<<res;
        return 0;
    }
    cout<<"0";
    return 0;
}
inline __attribute((constructor)) void init_io()
{
#ifdef INPUT_FILE
    freopen(INPUT_FILE,"r",stdin);
#endif
#ifdef OUTPUT_FILE
    freopen(OUTPUT_FILE,"w",stdout);
#endif
#ifndef RUN_ON_LOCAL
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
#endif
}