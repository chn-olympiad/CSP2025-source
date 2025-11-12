#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int cnt,n,m,k,c[15],a[15][20005];
int fa[20005];
struct node
{
    int u,v,w;
}e[2000005];
bool cmp(node x,node y)
{
    return x.w<y.w;
}
int find(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
int kruskal()
{
    int res=0,d=0;
    for(int i=1;i<=cnt;i++)
    {
        int aa=find(e[i].u),bb=find(e[i].v);
        if(aa==bb) continue;
        //cout<<e[i].u<<' '<<e[i].v<<' '<<e[i].w<<endl;
        fa[aa]=bb;
        res+=e[i].w;d++;
        if(d==n+k-1) break;
    }
    return res;
}
signed main()
{
    cin.tie(0);cout.tie(0);
    ios::sync_with_stdio(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        e[++cnt]={u,v,w};
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            e[++cnt]={i+n,j,a[i][j]};
        }
    }
    sort(e+1,e+1+cnt,cmp);
    for(int i=1;i<=n+k;i++) fa[i]=i;
    cout<<kruskal();
    return 0;
}
