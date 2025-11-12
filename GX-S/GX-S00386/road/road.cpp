#include <bits/stdc++.h>
using namespace std;
int n,m,k,c[12],fa[10105],choose[12];
long long ans,ans1;
int getfa(int x)
{
    return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
struct edge
{
    int u,v,w;
}e[3000005];
bool cmp(edge a,edge b)
{
    return a.w<b.w;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;++i)
    {
        cin>>e[i].u>>e[i].v>>e[i].w;
        e[i+m].u=e[i].v;
        e[i+m].v=e[i].u;
        e[i+m].w=e[i].w;
    }
    m*=2;
    for(int i=1;i<=k;++i)
    {
        cin>>c[i];
        for(int j=1;j<=n;++j)
        {
            cin>>e[m+j].w;
            e[m+j].v=j;
            e[m+j].u=n+i;
            e[m+j+j].v=n+i;
            e[m+j+j].u=j;
            e[m+j+j].w=e[m+j].w;
        }
        m+=2*n;
    }
    for(int i=1;i<=n+k;++i)
        fa[i]=i;
    sort(e+1,e+m+1,cmp);
    for(int i=1;i<=m;++i)
    {
        int x=getfa(e[i].u),y=getfa(e[i].v);
        if(x==y)   continue;
        fa[x]=y;
        ans+=e[i].w;
    }
    cout<<ans;
    return 0;
}

