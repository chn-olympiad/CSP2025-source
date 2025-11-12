#include<bits/stdc++.h>
using namespace std;
int n,k;
int sum[500005];
int dp[500005];
int cnt[2000005];
int b;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&sum[i]);
        sum[i]^=sum[i-1];
    }
    memset(cnt,-1,sizeof(cnt));
    cnt[0]=0;
    for(int i=1;i<=n;i++)
    {
        dp[i]=dp[i-1];
        if(cnt[(sum[i]^k)]!=-1)
        {
            dp[i]=max(dp[i],dp[cnt[(sum[i]^k)]]+1);
        }
        cnt[sum[i]]=i;
    }
    printf("%d",dp[n]);
    return 0;
}
