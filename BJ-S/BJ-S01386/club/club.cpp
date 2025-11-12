//第一次CSP-S考试 RP++
#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=1e5+10;

int n;
ll a[maxn][5],b[maxn],ans;
ll dp[2][505][505][505];

void dfs(int st,int x,int y,int z,ll sum)
{
    if(st>n)
    {
        ans=max(ans,sum);
        return ;
    }
    if(x<n/2) dfs(st+1,x+1,y,z,sum+a[st][1]);
    if(y<n/2) dfs(st+1,x,y+1,z,sum+a[st][2]);
    if(z<n/2) dfs(st+1,x,y,z+1,sum+a[st][3]);
}

void solve()
{
    cin>>n;

    ans=0;
    bool fl=true;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i][1]>>a[i][2]>>a[i][3];
        if(a[i][2]||a[i][3]) fl=false;
    }

    if(fl)
    {
        for(int i=1;i<=n;i++) b[i]=a[i][1];
        sort(b+1,b+n+1);
        for(int i=n;i>n/2;i--) ans+=b[i];
        cout<<ans<<"\n";
        return ;
    }

    if(n<=14)
    {
        dfs(1,0,0,0,0);
        cout<<ans<<"\n";
        return ;
    }

    memset(dp,0,sizeof(dp));

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=min(i,n/2);j++)
        {
            for(int k=0;k<=min(i-j,n/2);k++)
            {
                for(int l=0;l<=min(i-j-k,n/2);l++)
                {
                    if(j) dp[i%2][j][k][l]=max(dp[i%2][j][k][l],dp[(i-1)%2][j-1][k][l]+a[i][1]);
                    if(k) dp[i%2][j][k][l]=max(dp[i%2][j][k][l],dp[(i-1)%2][j][k-1][l]+a[i][2]);
                    if(l) dp[i%2][j][k][l]=max(dp[i%2][j][k][l],dp[(i-1)%2][j][k][l-1]+a[i][3]);
                    if(i==n) ans=max(ans,dp[i%2][j][k][l]);
                }
            }
        }
    }
    cout<<ans<<"\n";
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int T;cin>>T;
    while(T--) solve();
    return 0;
}
