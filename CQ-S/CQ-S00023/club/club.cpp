#include<bits/stdc++.h>
using namespace std;
const int N=2e2+10;

int a[4][N];
int dp[N][N][N];

int main(void)
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while (T--)
    {
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                cin>>a[j][i];
            }
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=n/2;j++)
            {
                for(int k=0;k<=n/2;k++)
                {
                    if(j!=0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[1][i]);
                    if(k!=0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[2][i]);
                    if(j+k<i)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[3][i]);
                }
            }
        }
        int ans=0;
        for(int i=0;i<=n/2;i++)
        {
            for(int j=0;j<=n/2;j++)
            {
                if(i+j<n/2)continue;
                ans=max(dp[n][i][j],ans);
            }
        }
        
        cout<<ans<<endl;

    }
    


    return 0;
}