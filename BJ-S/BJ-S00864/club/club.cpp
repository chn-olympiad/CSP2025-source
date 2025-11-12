#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct d
{
    ll x[4],c[4][4];
}dp[1005][1005];
ll t,n,a[1005][1005],ans;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                cin>>a[i][j];
                if(i==1)
                {
                    dp[i][i].x[j]=a[i][j];
                    dp[i][i].c[j][j]=1;
                }
            }
        }
        for(int j=2;j<=n;j++)
        {
            for(int i=1;i<j;i++)
            {
                for(int k=1;k<=3;k++)
                {
                    for(int l=1;l<=3;l++)
                    {
                        ll nn=n/2;
                        if(dp[i][j-1].x[l]+a[j][k]>dp[i][j].x[k]&&(dp[i][j-1].c[l][k]+1)<=nn)
                        {
                            dp[i][j].x[k]=dp[i][j-1].x[l]+a[j][k];
                            dp[i][j].c[k][1]=dp[i][j-1].c[l][1];
                            dp[i][j].c[k][2]=dp[i][j-1].c[l][2];
                            dp[i][j].c[k][3]=dp[i][j-1].c[l][3];
                            dp[i][j].c[k][k]++;
                        }
                    }

                }
            }
        }
 /*       for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cout<<"("<<i<<"."<<j<<")"<<dp[i][j].x[1]<<","<<dp[i][j].x[2]<<","<<dp[i][j].x[3]<<"  ";
            }
            cout<<"\n";
        }*/
        for(int i=1;i<=n;i++)
        {
            ans=max(ans,max(dp[i][n].x[1],max(dp[i][n].x[2],dp[i][n].x[3])));
        }
        cout<<ans<<"\n";
    }
    return 0;
}
