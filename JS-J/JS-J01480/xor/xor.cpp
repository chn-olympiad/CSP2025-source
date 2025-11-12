#include <bits/stdc++.h>
using namespace std;
int a[200005];
int x[1005][1005];
int dp[1005][1005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    if(n<=1000)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            x[i][i]=a[i];
        }
        memset(dp,0x7f,sizeof(dp));
        for(int len=1;len<=n;len++)
        {
            for(int l=1;l<=n-len+1;l++)
            {
                int r=l+len-1;
                if(l==r) dp[l][r]=(a[l]==k);
                else
                {
                    x[l][r]=(x[l][r-1]^(a[r]));
                    dp[l][r]=((x[l][r])==k);
                }
            }
        }
        for(int len=1;len<=n;len++)
        {
            for(int l=1;l<=n-len+1;l++)
            {
                int r=l+len-1;
                for(int k=l;k<r;k++)
                    dp[l][r]=max(dp[l][r],dp[l][k]+dp[k+1][r]);
            }
        }
        cout<<dp[1][n];
    }
    else
    {
        for(int i=1;i<=n;i++) cin>>a[i];
        int ans=0;
        if(k==1)
        {
            for(int i=1;i<=n;i++) ans+=a[i];
        }
        else
        {
            for(int i=1;i<=n;i++) ans+=(!a[i]);
            ans+=(n-ans)/2;
        }
        cout<<ans;
    }
    return 0;
}