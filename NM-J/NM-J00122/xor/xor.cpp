#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],dp[500005],sum[500005],kid[500005],dis[3000006];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=3e6;i++)
        dis[i]=-1;
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]^a[i];
        if(dis[sum[i]^k]!=-1)
            kid[i]=dis[sum[i]^k]+1;
        dis[sum[i]]=i;
    }
    for(int i=1;i<=n;i++)
        if(kid[i])
            dp[i]=max(dp[i-1],dp[kid[i]-1]+1);
        else
            dp[i]=dp[i-1];
    printf("%d",dp[n]);
    return 0;
}
