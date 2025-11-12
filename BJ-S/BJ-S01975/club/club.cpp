#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=210;
int n,t;
int a[N][3];
int dp[N][N/2][N/2][N/2];
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        memset(dp,0,sizeof dp);
        cin>>n;
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<3; j++)
            {
                cin>>a[i][j];
            }
        }
        dp[1][1][0][0]=a[1][0];
        dp[1][0][1][0]=a[1][1];
        dp[1][0][0][1]=a[1][2];
        for(int i=2; i<=n; i++)
        {
            for(int j=0; j<=n/2; j++)
            {
                for(int k=0; k<=n/2; k++)
                {
                    for(int l=0; l<=n/2; l++)
                    {
                        if(j!=0)
                        {
                            dp[i][j][k][l]=max(dp[i][j][k][l],dp[i-1][j-1][k][l]+a[i][0]);
                        }
                        if(k!=0)
                        {
                            dp[i][j][k][l]=max(dp[i][j][k][l],dp[i-1][j][k-1][l]+a[i][1]);
                        }
                        if(l!=0)
                        {
                            dp[i][j][k][l]=max(dp[i][j][k][l],dp[i-1][j][k][l-1]+a[i][2]);
                        }
                    }
                }
            }
        }
        int ans=0;
        for(int j=0; j<=n/2; j++)
        {
            for(int k=0; k<=n/2; k++)
            {
                for(int l=0; l<=n/2; l++)
                {
                    ans=max(ans,dp[n][j][k][l]);
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
