#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans,n,k,a[500010],sum[500010],dp[500010];
bool check(ll l,ll r)
{
    ll res;
    if(l==1) res=sum[r];
    else res=sum[r]^sum[l-1];
    return res==k;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        if(i==1) sum[i]=a[i];
        else sum[i]=sum[i-1]^a[i];
    }
    bool flag=1;
    for(int i=1;i<=n;i++)
    {
        dp[i]=check(i,i);
        if(flag)
        {
            for(int j=i-1;j>=1;j--) dp[i]=max(dp[i],dp[i]+check(j,i)),flag=0;
        }
        for(int j=i-1;j>=1;j--)
        {
            for(int k=j+1;k<=i;k++)
            {
                dp[i]=max(dp[i],dp[j]+check(k,i));
            }
        }
    }
    printf("%lld",*max_element(dp+1,dp+n+1));

    return 0;
}
