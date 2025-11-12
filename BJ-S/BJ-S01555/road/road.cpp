#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
const int maxm=2e6+10;
struct edge
{
    int u,v,w;
}e[maxm];
int n,m,k,tot=0,c[100],fa[maxn],vis[100][maxn],cnt[100];
int get(int x)
{
    if(x==fa[x])return x;
    return fa[x]=get(fa[x]);
}
bool cmp(edge x,edge y)
{
    return x.w<y.w;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;++i)
    {
        int u,v,w;
        cin>>u>>v>>w;
        e[++tot].u=u,e[tot].v=v,e[tot].w=w;
    }
    for(int i=1;i<=k;++i)
    {
        cin>>c[i];
        for(int j=1;j<=n;++j)
        {
            int w;
            cin>>w;
            e[++tot].u=n+i,e[tot].v=j,e[tot].w=w;
        }
    }
    for(int i=1;i<=n+k;++i)fa[i]=i;
    long long ans=0;
    int p=0;
    sort(e+1,e+tot+1,cmp);
    for(int i=1;i<=tot;++i)
    {
        int u=e[i].u,v=e[i].v,w=e[i].w;
        int x=get(u),y=get(v);
        if(x==y)continue;
        if(p>=n+k)break;
        ans+=w;
        fa[x]=y;
        p++;
    }
    cout<<ans<<endl;
    return 0;
}
