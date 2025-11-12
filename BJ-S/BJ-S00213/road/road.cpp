#include <bits/stdc++.h>
using namespace std;
const int N=1e4+15,M=1e6+5;
int n,m,k,cnt,ans,fa[N];
struct Node
{
    int u,v,w;
}G[M];
bool cmp(Node x,Node y)
{
    return x.w<y.w;
}
inline int find(int x)
{
    if(fa[x]==x) return x;
    fa[x]=find(fa[x]);
    return fa[x];
}
int main()
{   
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        G[++cnt]={u,v,w};
    }
    for(int i=1;i<=n;i++) fa[i]=i;
    sort(G+1,G+1+cnt,cmp);
    int eno=0;
    for(int i=1;i<=cnt;i++)
    {
        if(eno==n-1) break;
        int u=G[i].u,v=G[i].v;
        int fu=find(u),fv=find(v);
        if(fu==fv) continue;
        fa[fu]=fv;
        eno++;
        ans+=G[i].w;
    }
    cout<<ans<<endl;
    return 0;
}