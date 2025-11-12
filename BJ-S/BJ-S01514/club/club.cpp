#include<bits/stdc++.h>
using namespace std;
int dp[501][501][501];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,ans,i,j,k,a[500001][4];
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans=0;
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        for(i=0;i<=n/2;i++)
        {
            for(j=0;j<=n/2;j++)
            {
                for(k=0;k<=n/2;k++)
                {
                    if(i>0)
                        dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i+j+k][1]);
                    if(j>0)
                        dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]+a[i+j+k][2]);
                    if(k>0)
                        dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1]+a[i+j+k][3]);
                    if(i+j+k==n)
                    {
                        ans=max(ans,dp[i][j][k]);
                        break;
                    }
                }
            }
        }
        cout<<ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}