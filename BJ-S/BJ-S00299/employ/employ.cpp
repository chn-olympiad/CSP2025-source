#include<bits/stdc++.h>
using namespace std;
int a[505];
int c[505];
int cnt1[505];
char ch;
long long dp[20][20][(1<<18)+1];
long long mod=998244353;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>ch;
        a[i]=ch-'0';
        cnt1[i]=cnt1[i-1];
        if(a[i])cnt1[i]++;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    if(m>cnt1[n])
    {
        cout<<0;
        return 0;
    }
    int nt=0;
    for(int i=0;i<=n;i++)dp[i][0][0]=1;
    for(int i=1;i<=n;i++)
    {
        //cout<<a[i]<<'\n';
        for(int j=0;j<=m&&j<=cnt1[i];j++)
        {
            nt=i-j;
            for(int k=0;k<(1<<n);k++)
            {
                for(int l=1;l<=n;l++)
                {
                    if(!(k&(1<<(l-1))))continue;
                    //cout<<l<<' '<<a[i]<<' '<<c[l]<<' '<<nt<<'\n';
                    if(a[i]&&c[l]>nt)
                    {
                        if(j)dp[i][j][k]=(dp[i][j][k]+dp[i-1][j-1][k-(1<<(l-1))])%mod;
                        //cout<<'('<<i<<' '<<j<<' '<<k<<' '<<l<<')'<<'\n';
                    }
                    else dp[i][j][k]=(dp[i][j][k]+dp[i-1][j][k-(1<<(l-1))])%mod;
                }
                //cout<<'('<<i<<' '<<j<<' '<<k<<' '<<nt<<')'<<dp[i][j][k]<<'\n';
            }
        }
    }
    cout<<dp[n][m][(1<<n)-1];
}
