#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,a[4][N],ans[N],vis[N],dp[4][210][210];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while (t--)
    {
        cin>>n;
        for (int i=1;i<=n;i++)
        {
            cin>>a[1][i]>>a[2][i]>>a[3][i];
            dp[1][i][0]=a[1][i];
            dp[2][i][0]=a[2][i];
            dp[3][i][0]=a[3][i];
        }
        if (n==2)
        {
            ans[1]=a[1][1]+a[2][2];
            ans[2]=a[1][1]+a[3][2];
            ans[3]=a[2][1]+a[1][2];
            ans[4]=a[2][1]+a[3][2];
            ans[5]=a[3][1]+a[1][2];
            ans[6]=a[3][1]+a[2][2];
            sort(ans+1,ans+7);
            cout<<ans[6]<<"\n";
        }
        else
        {
            memset(vis,0,sizeof(vis));
            for (int k=1;k<=3;k++)
                for (int i=1;i<=n;i++)
                {
                    for (int j=1;j<=n/2;j++)
                    {
                        if (dp[k][i-1][j]<=dp[k][i-1][j-1]+a[k][i] && vis[i]==0)
                        {
                            dp[k][i-1][j]=dp[k][i-1][j-1]+a[k][i];
                            vis[i]=k;
                        }
                        else if (dp[k][i-1][j]<=dp[k][i-1][j-1]+a[k][i] && vis[i]!=0)
                        {
                            if (a[k][i]>a[vis[i]][i])
                            {
                                dp[k][i-1][j]=dp[k][i-1][j-1]+a[k][i];
                                vis[i]=k;
                            }
                        }
                    }
                }
            cout<<dp[1][n][n/2]+dp[2][n][n/2]+dp[3][n][n/2]<<"\n";
        }
    }
    return 0;
}
