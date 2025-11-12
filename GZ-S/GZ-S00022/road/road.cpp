//GZ-S00022 何奕歆 凯里市第一初级中学
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    int t;cin>>t;
    for(int tt=0;tt<t;tt++)
    {
        int n;cin>>n;
        int sum=0,m=n/2;
        int shu[n+1][4],dp[n+1][4],num[4];
        for(int i=1;i<=n;i++)
        {
            cin>>shu[i][1]>>shu[i][2]>>shu[i][3];
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                if(num[j]<=m)
                {
                    dp[i][j]=sum+shu[i][j];num[j]++;
                }
                else if(num[j]>m)
                {
                    int ls=sum;
                    dp[i][j]=max(sum-dp[i-1][j]+shu[i][j],sum);
                    if(dp[i][j]!=sum)
                    {
                        if(j==1)
                        {
                            if(num[2]<m)
                            {
                                if(num[3]<m)
                                {
                                    dp[i][j]+=max(dp[i-1][2],dp[i-1][3]);continue;
                                }
                                dp[i][j]+=dp[i-1][2];continue;
                            }
                            dp[i][j]+=dp[i-1][3];
                        }
                    }
            }
        }
        cout<<sum;
    }

    return 0;
}
