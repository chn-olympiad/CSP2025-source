#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int cval[20],fa[2000100],n,m,k;
struct node
{
    ll from,to,val;
}G[2000100];
bool cmp(node x1,node x2)
{
    return x1.val<x2.val;
}
int rfind(int x)
{
    if (fa[x]==x)
        return x;
    return fa[x]=rfind(fa[x]);
}
void kruskal()
{
    ll ans=0;
    sort(G+1,G+m+1,cmp);
    for (int i=1;i<=m;i++)
    {
        int rootx=rfind(G[i].from);
        int rooty=rfind(G[i].to);
        if (rootx==rooty)
            continue;
        fa[rootx]=rooty;
        ans+=G[i].val;
    }
    cout<<ans;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for (int i=1;i<=n+k;i++)
    {
        fa[i]=i;
    }
    for (int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        G[i].from=u;
        G[i].to=v;
        G[i].val=w;
    }
    int x=0;
    for (int i=1;i<=k;i++)
    {
        cin>>cval[i];
        for (int j=1;j<=n;j++)
        {
            cin>>x;
            G[++m].from=n+i;
            G[m].to=j;
            G[m].val=x;
        }
    }
    kruskal();
    return 0;
}
