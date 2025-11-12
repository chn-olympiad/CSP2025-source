#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=510;
const int mod=998244353;
int n,m,d[N],ans;
char a[N];
int vis[N],q[N];

void dfs(int dep)
{
    if(dep>n)
    {
        int tu=0;
        for(int i=1;i<=n;i++)
        {
            if(d[q[i]]<=tu)
                tu++;
            else
            {
                if(a[i]=='0')
                    tu++;
            }
        }
        if((n-tu)>=m)
            ans++;
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i])
            continue;
        vis[i]=1;
        q[dep]=i;
        dfs(dep+1);
        vis[i]=0;
    }
    return ;
}

signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    scanf("%s",a);
    for(int i=n;i>=1;i--)
        a[i]=a[i-1];
    for(int i=1;i<=n;i++)
        scanf("%lld",&d[i]);
    if(n<=10)
    {
        dfs(1);
        printf("%lld",ans);
    }
    return 0;
}
