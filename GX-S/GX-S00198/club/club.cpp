#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long t;
    cin>>t;
    for(int q=1;q<=t;q++)
    {
        long long n, a[100003][4],x=0,y=0,z=0,m=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][1]>a[i][2] && a[i][1]>a[i][3])
            {
                x++;
                m=m+a[i][1];
            }
            if(a[i][2]>a[i][1] && a[i][2]>a[i][3])
            {
                y++;
                m=m+a[i][2];
            }
            if(a[i][3]>a[i][2] && a[i][3]>a[i][1])
            {
                z++;
                m=m+a[i][3];
            }
        }
        if(x<=n/2 && y<=n/2 && z<=n/2)
        {
            cout<<m<<endl;
        }
        else
        {
            long long dp[100003][5]={0},ans=0;
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=3;j++)
                {
                    if(i==1 && j==1)
                    {
                        dp[i][j]=a[i][j];
                    }
                    else if(i==1)
                    {
                        dp[i][j]=dp[i][j-1]+a[i][j];
                    }
                    else if(j==1)
                    {
                        dp[i][j]=dp[i-1][j-1]+a[i][j];
                    }
                    else{
                        dp[i][j]=max(dp[i][j-1],dp[i-1][j-1])+a[i][j];
                    }
                }
            }
            for(int i=1;i<=3;i++)
            {
                ans=max(ans,dp[n][i]);
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
