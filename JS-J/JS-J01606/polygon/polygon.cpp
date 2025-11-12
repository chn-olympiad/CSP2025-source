#include <bits/stdc++.h>
using namespace std;
const int N=5002,MOD=998244353;
int n;
long long ans,l[N],sum[N];
void dfs(int r,long long smin,int m,int now,int nowl,int len)
{
    if(len==m&&nowl>smin)
    {
        ans=(ans+1)%MOD;
        return ;
    }
    for(int i=now+1;i<r;++i)
    {
        dfs(r,smin,m,i,nowl+l[i],len+1);
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",&l[i]);
        sum[i]=sum[i-1]+l[i-1];
    }
    sort(l+1,l+1+n);
    for(int k=3;k<=n;++k)
    {
        for(int i=k;i<=n;++i)
        {
            if(sum[i]<l[i]) continue;
            dfs(i,l[i],k-1,0,0,0);
        }
    }
    printf("%lld",ans);
    return 0;
}
