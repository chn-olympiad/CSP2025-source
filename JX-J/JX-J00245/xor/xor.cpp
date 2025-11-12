#include<bits/stdc++.h>
using namespace std;
long long a[500005],dp[500005],n,k;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k>>a[1];
    for(long long i=2;i<=n;i++)
    {
        long long x;
        cin>>x;a[i]=a[i-1]^x;
    }
    for(long long r=1;r<=n;r++)
    {
        dp[r]=dp[r-1];
        for(long long l=1;l<=r;l++)
        {
            if((a[r]^a[l-1])==k)
            {
                dp[r]=max(dp[r],dp[l-1]+1);
            }
        }
    }
    cout<<dp[n];
    return 0;
}
