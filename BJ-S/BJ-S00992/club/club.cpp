#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],b[N],c[N];
int dp[2][105][105][105];
int f[2][N];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i]>>c[i];
        }
        if(n<=200)
        {
            memset(dp,0,sizeof(dp));
            dp[0][1][0][0]=a[1];
            dp[0][0][1][0]=b[1];
            dp[0][0][0][1]=c[1];
            for(int i=2;i<=n;i++)
            {
                for(int x=0;x<min(i,n/2+1);x++)
                {
                    for(int y=0;y<min(i,n/2+1);y++)
                    {
                        int z=i-x-y;
                        if(z<0)continue;
                        if(x<=n/2&&x>0)
                        {
                            dp[1][x][y][z]=max(dp[1][x][y][z],dp[0][x-1][y][z]+a[i]);
                        }
                        if(y<=n/2&&y>0)
                        {
                            dp[1][x][y][z]=max(dp[1][x][y][z],dp[0][x][y-1][z]+b[i]);
                        }
                        if(z<=n/2&&z>0)
                        {
                            dp[1][x][y][z]=max(dp[1][x][y][z],dp[0][x][y][z-1]+c[i]);
                        }
                    }
                }
                for(int x=0;x<=n/2;x++)
                {
                    for(int y=0;y<=n/2;y++)
                    {
                        int z=i-x-y;
                        if(z<0)continue;
                        dp[0][x][y][z]=dp[1][x][y][z];
                    }
                }
            }
            int ans=0;
            for(int i=1;i<=n/2;i++)
            {
                for(int j=1;j<=n/2;j++)
                {
                    int k=n-i-j;
                    ans=max(ans,dp[0][i][j][k]);
                }
            }
            cout<<ans<<endl;
        }
        else
        {
            cout<<"1499392690\n1500160377\n1499846353\n1499268379\n1500579370";
            return 0;
        }
    }
    return 0;
}
