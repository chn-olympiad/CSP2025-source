#include <bits/stdc++.h>
using namespace std;
int t,n,dp[464][232][232],res=0,a[100005][3];
void rx()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<3;j++)
        {
            cin>>a[i][j];
        }
        for (int j=0;j<=min({i,n/2});j++)
        {
            for (int k=0;k<=min({i-j,n/2});k++)
            {
                if (i-j-k>=n/2)
                {
                    continue;
                }
                dp[i][j][k]=0;
                if (i-j-k>0)
                {
                    dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i][2]);
                }
                if (j>0)
                {
                    dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i][0]);
                }
                if (k>0)
                {
                    dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i][1]);
                }
            }
        }
    }
    res=0;
    for (int j=0;j<=n/2;j++)
    {
        for (int k=0;k<=min({n-j,n/2});k++)
        {
            if (n-j-k>=n/2)
            {
                continue;
            }
            res=max(res,dp[n][j][k]);
        }
    }
    cout<<res<<endl;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while (t--)
    {
        rx();
    }
}
