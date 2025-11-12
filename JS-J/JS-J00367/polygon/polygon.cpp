#include<bits/stdc++.h>
using namespace std;
long long n,a[5009],ans;
void dfs(int x,long long sum,int cnt)
{
    if(cnt>=3)
    {
        if(sum>2*a[x])
        {
            ans++;
            ans%=998244353;
        }
            for(int i=x+1;i<=n;++i)
                dfs(i,sum+a[i],cnt+1);
    }
    else
    {
          for(int i=x+1;i<=n;++i)
                dfs(i,sum+a[i],cnt+1);
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i)
    {
        dfs(i,a[i],1);
    }
    printf("%lld",ans);
    return 0;
}
