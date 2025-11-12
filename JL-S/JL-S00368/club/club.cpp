#include <bits/stdc++.h>
using namespace std;
const int N=100010;
int v1[N],v2[N],v3[N],dp[N][N];
int n,t,ans=0;
int w1=0,w2=0,w3=0;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int k=1;k<=t;k++)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>v1[i]>>v2[i]>>v3[i];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dp[i][j]=max(dp[i-1][j],dp[i-1][j]+v1[i]);
                dp[i][j]=max(dp[i][j],dp[i-1][j]+v2[i]);
                dp[i][j]=max(dp[i][j],dp[i-1][j]+v3[i]);
            }
        }
        cout<<dp[n][n]<<endl;
    }
    return 0;
}
