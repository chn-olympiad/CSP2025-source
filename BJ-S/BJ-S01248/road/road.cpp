#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
struct node
{
    int u,v,w;
}edge[1000005];
bool cmp(node x,node y)
{
    return x.w<y.w;
}
int a[10005],fa[10005];
int cost[15];
int find(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>edge[i].u>>edge[i].v>>edge[i].w;
        if(edge[i].u>edge[i].v) swap(edge[i].u,edge[i].v);
    }
    for(int i=1;i<=n;i++) fa[i]=i;
    sort(edge+1,edge+m+1,cmp);
    int ans=0,cnt=0;
    for(int i=1;i<=m;i++)
    {
        int u=edge[i].u,v=edge[i].v,w=edge[i].w;
        if(find(fa[u])!=find(fa[v]))
        {
            fa[find(v)]=find(fa[u]);
            ans+=w;
            cnt++;
        }
        if(cnt==n-1) break;
    }
    cout<<ans<<endl;
    return 0;
}