#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,j,cnt[4],sum,i,k,a[100005][4],dp[205][205][4];
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n;
        sum=0;
        memset(cnt,0,sizeof(cnt));
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=3;j++)cin>>a[i][j];
        }
        for(i=1;i<=n;i++)
        {
            for(j=(n>>1);j>=1;j--)
            {
                for(k=1;k<=3;k++)dp[i][j][k]=max(dp[i-1][j-(k==1)][1]+a[i][k]*(k==1),max(dp[i-1][j-(k==2)][2]+a[i][k]*(k==2),dp[i-1][j-(k==3)][3]+a[i][k]*(k==3)));
            }
        }
        /*for(i=1;i<=n;i++)
        {
            for(j=1;j<=(n>>1);j++)
            {
                cout<<j<<" ";
                for(k=1;k<=3;k++)cout<<dp[i][j][k]<<" ";
                cout<<endl;
            }
            cout<<endl;
        }*/
        cout<<max(dp[n][n/2][1],max(dp[n][n/2][2],dp[n][n/2][3]))<<endl;
    }
    return 0;
}
