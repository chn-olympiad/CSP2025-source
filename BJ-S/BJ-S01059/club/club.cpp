#include<bits/stdc++.h>
using namespace std;
int a[100001][10];
//b[100001];
//priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q[4];
int dp[202][202][202];
int b[100001];
int n;
int dfs(int k,int a1,int a2,int a3)
{
    if(k>n)
    {
        return 0;
    }
    if(dp[k][a1][a2])
    {
        return dp[k][a1][a2];
    }
    int maxans = 0;
    if(a1>0)
    {
        maxans = max(dfs(k+1,a1-1,a2,a3)+a[k][1],maxans);
    }
    if(a2>0)
    {
        maxans = max(dfs(k+1,a1,a2-1,a3)+a[k][2],maxans);
    }
    if(a3>0)
    {
        maxans = max(dfs(k+1,a1,a2,a3-1)+a[k][3],maxans);
    }
    dp[k][a1][a2] = maxans;
    return maxans;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        for(int i = 0;i<=201;i++)
        {
            for(int j = 0;j<=201;j++)
            {
                for(int k = 0;k<=201;k++)
                {
                 //   for(int x = 0;x<=31;x++)
                        dp[i][j][k] = 0;
                }
            }
        }
        cin>>n;
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=3;j++)
            {
                cin>>a[i][j];
            }
        }
        if(n<=300)
            cout<<dfs(1,n/2,n/2,n/2)<<endl;
        else
        {
            for(int i = 1;i<=n;i++)
            {
                b[i] = a[i][1];
            }
            sort(b+1,b+n+1);
            int cnt = 0;
            long long ans = 0;
            for(int i = n;i>=1;i--)
            {
                cnt++;
                if(cnt>n/2)
                {
                    break;
                }
                else
                {
                    ans += b[i];
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
