#include<bits/stdc++.h>
using namespace std;
const int MAXN=105;
const int INF=0x3f3f3f3f;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n;
    cin>>n;
    int max_per_dept=n/2;
    vector<vector<int>> a(n,vector<int>(3));
    for(int i=0;i<n;++i)
    {
        for(int j=0;i<3;++j)
        {
            cin>>a[i][j];
        }
    }
    vector<vector<int>> dp(max_per_dept+1,vector<int>(max_per_dept+1,-INF));
    dp[0][0]=0;
    for(int k=0;k<n;++k)
    {
        for(int i=max_per_dept;i>=0;--i)
        {
            for(int j=max_per_dept;j>=0;--j)
            {
                if(dp[i][j]=-INF)
                {
                    continue;
                }
                if(i+1<=max_per_dept)
                {
                    dp[i+1][j]=max(dp[i+1][j],dp[i][j]+a[k][0]);
                }
                if(j+1<=max_per_dept)
                {
                    dp[i][j+1]=max(dp[i][j+1],dp[i][j]+a[k][1]);
                }
                int cnt3=(k+1)-i-j;
                if(cnt3<=max_per_dept&&cnt3>=0)
                {
                    dp[i][j]=max(dp[i][j],dp[i][j]+a[k][2]);
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<=max_per_dept;++i)
    {
        for(int j=0;j<=max_per_dept;++j)
        {
            int k=n-i-j;
            if(k>=0&&k<=max_per_dept)
            {
                ans=max(ans,dp[i][j]);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
