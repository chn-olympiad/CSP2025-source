#include<bits/stdc++.h>
using namespace std;
int a[500010];
int s[500010];
int dp[500010];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=s[i-1]^a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(dp[i-j]!=dp[i-j+1] && j!=1)
            {
                break;
            }
            if((s[i-j]^s[i])==k)
            {
                dp[i]=max(dp[i],dp[i-j]+1);
            }
            else
            {
                dp[i]=max(dp[i],dp[i-j]);
            }
        }
    }
    cout<<dp[n];
    return 0;
}
