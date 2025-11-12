#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500002];
long long dp[500002];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    int last=1;
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        dp[i]=max(dp[i],dp[i-1]);
        long long xorall=0;
        for(int j=i;j>=last;j--)
        {
            if(j==i)
            {
                xorall=a[j];
            }
            else
            {
                xorall=xorall^a[j];
            }
            if(xorall==k)
            {
                if(dp[i]<dp[j-1]+1)
                {
                    dp[i]=dp[j-1]+1;
                    last=i+1;
                }
            }
        }
    }
    printf("%lld",dp[n]);
    return 0;
}
