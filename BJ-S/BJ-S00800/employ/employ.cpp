#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int N=5e2+10,mod=998244353;
int ans[N],book[N],n,b[N],m;
char c[N];
int dp[N][N][N],a[N],f[N],C[N][N],g[N];
int solve()
{
    int cnt=0,res=0;
    for(int i=1;i<=n;i++)
    {
        if(b[i]>cnt&&c[i]=='1')res++;
        else cnt++;
    }
    return res;
}
void dfs(int x)
{
    if(x>n)
    {
        int p=solve();
        ans[p]++;
        return;
    }
    for(int i=1;i<=n;i++)if(!book[i])
    {
        b[x]=a[i];
        book[i]=1;
        dfs(x+1);
        book[i]=0;
    }
}
void init()
{
    C[0][0]=1;
    for(int i=1;i<=500;i++)
    {
        C[i][0]=1;
        for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    }
}
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;
    if(n<=10)
    {
    cin>>(c+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dfs(1);
    int res=0;
    for(int i=n;i>=m;i--)res+=ans[i];
    cout<<res<<endl;
    return 0;
    }
    init();
    cin>>(c+1);
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        a[x]++;
    }
    for(int i=n;i;i--)a[i-1]+=a[i];
    for(int i=0;i<=n;i++)dp[0][0][i]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            for(int k=0;k<=n;k++)
            {
                dp[i][j][k]=dp[i-1][j][k]%mod;
                if(j&&c[i]=='1')dp[i][j][k]=(dp[i-1][j-1][k+1]*max(0ll,a[i-j+1]-k)+dp[i][j][k])%mod;
                // if(dp[i][j][k])cout<<i<<' '<<j<<' '<<k<<' '<<dp[i][j][k]<<endl;
            }
        }
    }
    int cnt=1;
    for(int i=n;i>=0;i--)
    {
        // cout<<dp[n][i][0]<<' ';
        f[i]=dp[n][i][0]*cnt%mod;
        cnt=cnt*(n-i+1)%mod;
    }
    // cout<<endl;
    int ans=0;
    for(int i=n;i>=m;i--)
    {
        g[i]=f[i];
        for(int j=i+1;j<=n;j++)g[i]+=g[j]*C[j][i]%mod*-1+mod,g[i]%=mod;
        // cout<<f[i]<<' '<<g[i]<<endl;
        ans=(ans+g[i])%mod;
    }
    cout<<ans<<endl;
    return 0;
}