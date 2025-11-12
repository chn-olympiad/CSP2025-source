#include <bits/stdc++.h>
using namespace std;
int a[500005],l[500005],dp[500005],s[500005];
map <int,int> mp;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    memset(dp,-0x3f,sizeof(dp));
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        s[i]=s[i-1]^a[i];
    }
    for(int i=0;i<=n;i++)
    {
        if(mp.find(s[i]^k)!=mp.end())
            l[i]=mp[s[i]^k]+1;
        mp[s[i]]=i;
    }
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        if(!l[i])
            dp[i]=dp[i-1];
        else
            dp[i]=max(dp[i-1],dp[l[i]-1]+1);
    }
    printf("%d\n",dp[n]);
    return 0;
}
