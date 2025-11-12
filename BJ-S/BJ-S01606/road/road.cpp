#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=10050;
struct Edge
{
    int u,v;
    ll w;
    bool operator < (const Edge &rhs) const
    {
        return w>rhs.w;
    }
};
int n,m,k,sumv;
ll ans,c[15],anss;
vector<Edge> e[15];
priority_queue<Edge> q;
int fa[maxn];
int findx(int x)
{
    if(fa[x]==x)
        return x;
    return fa[x]=findx(fa[x]);
}
void MST()
{
    int addv=0;
    for(int i=1;i<=n+k;++i)
        fa[i]=i;
    while(addv<sumv && !q.empty())
    {
        int u=q.top().u;
        int v=q.top().v;
        ll w=q.top().w;
        q.pop();
        if(findx(u)==findx(v))
            continue;
        else
        {
            fa[findx(v)]=findx(u);
            ++addv;
            anss+=w;
        }
    }
    ans=min(ans,anss);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    ans=0x3f3f3f3f3f3f3f3f;
    for(int i=1;i<=m;++i)
    {
        int u,v;
        ll w;
        scanf("%d%d%lld",&u,&v,&w);
        e[0].pb({u,v,w});
    }
    for(int i=1;i<=k;++i)
    {
        scanf("%lld",&c[i]);
        for(int j=1;j<=n;++j)
        {
            ll w;
            scanf("%lld",&w);
            e[i].pb({i+n,j,w});
        }
    }
    for(int o=0;o<(1<<k);++o)
    {
        anss=0;
        sumv=n-1;
        while(!q.empty())
            q.pop();
        for(int i=1;i<=k;++i)
        {
            if(1<<(i-1) & o)
            {
                anss+=c[i];
                ++sumv;
                for(auto atx:e[i])
                {
                    q.push(atx);
                }
            }
        }
        for(auto atx:e[0])
        {
            q.push(atx);
        }
        MST();
    }
    printf("%lld\n",ans);
}
