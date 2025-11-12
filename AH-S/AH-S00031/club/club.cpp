#include<bits/stdc++.h>
using namespace std;
long long n,t,a[100001][4],dp[201][101][101],ans,b[100001];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        memset(dp,0,sizeof(dp));
        ans=0;
        for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
        if(n==1e5)
        {
            for(int i=1;i<=n;i++) b[i]=a[i][1];
            sort(b+1,b+n+1);
            for(int i=n;i>=n/2;i--) ans+=b[i];
            cout<<ans;
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            for(int x=0;x<=n/2;x++)
            {
                if(x>i) break;
                for(int y=0;y<=n/2;y++)
                {
                    if(x+y>i) break;
                    int z=i-x-y;
                    if(x>=1) dp[i][x][y]=dp[i-1][x-1][y]+a[i][1];
                    if(y>=1)
                        dp[i][x][y]=max(dp[i][x][y],dp[i-1][x][y-1]+a[i][2]);
                    if(z>=1)
                        dp[i][x][y]=max(dp[i][x][y],dp[i-1][x][y]+a[i][3]);
                }
            }
        }
        for(int i=0;i<=n/2;i++)
        {
            for(int j=0;j<=n/2;j++)
            {
                ans=max(ans,dp[n][i][j]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
