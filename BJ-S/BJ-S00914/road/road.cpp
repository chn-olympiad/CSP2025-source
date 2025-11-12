#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,ans=0;
int c[20],len;
int fa[100010],son[100010];
bool can[20],getans;
struct node
{
    int u,v,w;
}edge[2000010];
int findfa(int t)
{
    if(fa[t]==t)
        return t;
    return fa[t]=findfa(fa[t]);
}
bool cmp(node a,node b)
{
    return a.w<b.w;
}
void check(int sum)
{
    memset(son,0,sizeof son);
    for(int i=1;i<=n+k;i++)
        fa[i]=i;
    for(int i=1;i<=n;i++)
        son[i]=1;
    for(int i=1;i<=m;i++)
    {
        if(findfa(edge[i].u)==findfa(edge[i].v))
            continue;
        if(edge[i].u>n)
        {
            if(can[edge[i].u-n]==false)
                continue;
        }
        sum+=edge[i].w;
        son[findfa(edge[i].v)]+=son[findfa(edge[i].u)];
        fa[findfa(edge[i].u)]=findfa(edge[i].v);
        if(son[findfa(edge[i].v)]==n)
        {
            if(getans==false||(getans==true&&ans>sum))
                ans=sum;
            getans=true;
            return;
        }
    }
}
void dfs(int t,int p)
{
    if(t==k+1)
    {
        check(p);
        return;
    }
    if(c[t]!=0)
        dfs(t+1,p);
    can[t]=true;
    dfs(t+1,p+c[t]);
    can[t]=false;
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=m;i++)
        scanf("%lld%lld%lld",&edge[i].u,&edge[i].v,&edge[i].w);
    for(int i=1;i<=k;i++)
    {
        scanf("%lld",&c[i]);
        for(int j=1;j<=n;j++)
        {
            scanf("%lld",&len);
            m++;
            edge[m].u=n+i;
            edge[m].v=j;
            edge[m].w=len;
        }
    }
    sort(edge+1,edge+m+1,cmp);
    dfs(1,0);
    printf("%lld",ans);
    return 0;
}
