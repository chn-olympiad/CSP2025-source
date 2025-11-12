#include<bits/stdc++.h>
using namespace std;
int a[1001],n,k,lm[10001],dp[1001][1001],dp1[1001][1001],p[1001][1001],ans=0,l=0;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    memset(lm,0x3f3f3f,sizeof(lm));
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        dp[i][i]=a[i];
        if(a[i]==k)
        {
            lm[i]=i;
        }
    }
    for(int i=1;i<n;i++)
    {
        dp[i][i+1]=dp[i][i]^a[i+1];
        if(dp[i][i+1]==k)
        {
            lm[i]=min(lm[i],i+1);
        }
    }
    for(int i=3;i<=n;i++)
    {
        for(int j=1;j<=n-i+1;j++)
        {
            dp[j][j+i-1]=dp[j][j+i-2]^a[j+i-1];
            if(dp[j][j+i-1]==k)
            {
                lm[j]=min(lm[j],i+j-1);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=lm[i];j<=n;j++)
            dp1[i][j]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=j;k<j+i-1;k++)
            dp1[j][j+i-1]=max(dp1[j][j+i-1],dp1[j][k]+dp1[k+1][j+i-1]);
            ans=max(ans,dp1[j][j+i-1]);
        }
    }
    cout<<ans;
}
