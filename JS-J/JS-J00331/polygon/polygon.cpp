#include <bits/stdc++.h>
using namespace std;
int n;
int a[5002];
int sum[5002];
long long ans=0;
bool cmp(int x,int y)
{
    return x>y;
}
void dfs(int x,int maxx,int co,int last)
{
    if(maxx*2<co && x>=3)
    {
        ans=(ans+1)%998244353;
    }
    if(last>n)
    {
        return ;
    }
    if(co+sum[n]-sum[last-1]<=maxx*2)
    {
        return ;
    }
    for(int i=last;i<=n;i++)
    {
        dfs(x+1,max(maxx,a[i]),co+a[i],i+1);
    }
    return ;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    sort(a+1,a+1+n,cmp);
    dfs(0,0,0,1);
    printf("%lld",ans);
    return 0;
}
