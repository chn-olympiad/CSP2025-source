#include <bits/stdc++.h>     //bao li dai ma
using namespace std;
const int mod=998244353;
int n,ans,a[10005];
bool f[10005];
void dfs(int t,int sum,int maxn,int now)
{
    if(sum>2*maxn&&t>=3)
        ans++;
    for(int i=now+1;i<=n;i++)
    {
        if(f[i])
            continue;
        f[i]=1;
        dfs(t+1,sum+a[i],max(maxn,a[i]),i);
        f[i]=0;
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    dfs(0,0,0,0);
    printf("%d",ans%mod);
    return 0;
}
