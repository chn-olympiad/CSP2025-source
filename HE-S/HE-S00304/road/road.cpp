#include<bits/stdc++.h>
const int N=1e4+5;
const int M=1e6+5;
#define int long long
using namespace std;
int n,m,k;
struct edge
{
    int u,v,w;
}e[M],t[M];
struct town
{
    int c;
    int a[N];
}tw[20];
int fa[N],sum,cnt;
int find(int x)
{
    if(x==fa[x])
    return x;
    return fa[x]=find(fa[x]);
}
void kruscal()
{
    sort(e+1,e+m+1,[](edge x,edge y){return x.w<y.w;});
    for(int i=1;i<=m;i++)
    {
        int u=e[i].u;
        int v=e[i].v;
        u=find(u),v=find(v);
        if(u==v)
        continue;
        fa[v]=u;
        t[++cnt]=e[i];
        sum+=e[i].w;
        if(cnt==n-1)
        break;
    }
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int i=1;i<=m;i++)
        cin>>e[i].u>>e[i].v>>e[i].w;
    kruscal();
    cout<<sum;
}