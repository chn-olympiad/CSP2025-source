#include<bits/stdc++.h>
using namespace std;
long long T,n,ta=0,tb=0,tc=0,ans=0,dp[100005][5],ff[100005];
int d[100005][5];
bool flag=1;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--)
    {
        cin>>n;
        ta=n/2-1,tb=n/2-1,tc=n/2-1;
        for(int i=1;i<=n;i++)
        {
            cin>>d[i][1]>>d[i][2]>>d[i][3];
            if(d[i][2]!=0||d[i][3]!=0) flag=0;
        }
        int ans=-999;
        if(flag)
        {
            for(int i=1;i<=n;i++)
            {
                ff[i]=d[i][1];
            }
            sort(ff+1,ff+n+1,cmp);
            int ans=0;
            for(int i=1;i<=n/2;i++)
            {
                ans+=ff[i];
            }
            cout<<ans<<endl;
        }
        else if(n==2)
        {
            for(int i=1;i<=3;i++)
            {
                for(int j=1;j<=3;j++)
                {
                    if(i==j) continue;
                    ans=max(ans,d[1][i]+d[2][j]);
                }
            }
            cout<<ans<<endl;
        }
        else
        {
            dp[1][1]=d[1][1],dp[1][2]=d[1][2],dp[1][3]=d[1][3];
            for(int i=2;i<=n;i++)
            {
                if(dp[i-1][2]>=dp[i-1][1]&&dp[i-1][3]>=dp[i-1][1])
                {
                    dp[i][1]=d[i][1]+max(dp[i-1][2],dp[i-1][3]);
                }
                else
                {
                    if(dp[i-1][1]==max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))&&ta)
                    {
                        dp[i][1]=d[i][1]+dp[i-1][1];
                        ta--;
                    }
                    else
                    {
                        dp[i][1]=d[i][1]+max(dp[i-1][2],dp[i-1][3]);
                    }
                }
                if(dp[i-1][1]>=dp[i-1][2]&&dp[i-1][3]>=dp[i-1][2])
                {
                    dp[i][2]=d[i][2]+max(dp[i-1][1],dp[i-1][3]);
                }
                else
                {
                    if(dp[i-1][2]==max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))&&tb)
                    {
                        dp[i][2]=d[i][2]+dp[i-1][2];
                        tb--;
                    }
                    else
                    {
                        dp[i][2]=d[i][2]+max(dp[i-1][1],dp[i-1][3]);
                    }
                }
                if(dp[i-1][1]>=dp[i-1][3]&&dp[i-1][2]>=dp[i-1][3])
                {
                    dp[i][3]=d[i][3]+max(dp[i-1][1],dp[i-1][2]);
                }
                else
                {
                    if(dp[i-1][3]==max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))&&tc)
                    {
                        dp[i][3]=d[i][3]+dp[i-1][3];
                        tc--;
                    }
                    else
                    {
                        dp[i][3]=d[i][3]+max(dp[i-1][1],dp[i-1][2]);
                    }
                }
            }
            cout<<max(dp[n][1],max(dp[n][2],dp[n][3]))<<endl;
        }
    }
    return 0;
}
