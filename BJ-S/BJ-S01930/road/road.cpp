#include <bits/stdc++.h>
using namespace std;
const int N=1e4+20;
const int M=2e6+20;
const int K=15;
#define ll long long
int n,m,k;
int fa[N];
bool build[K];
struct node
{
    int u,v,w;
}g[M];
int idx;
void add(int u,int v,int w)
{
    g[++idx].u=u;
    g[idx].v=v;
    g[idx].w=w;
}
int find(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
bool cmp(node a,node b)
{
    return a.w<b.w;
}
bool check()
{
    int cnt=find(1);
    for(int i=2;i<=n;i++) if(find(i)!=cnt) return 0;
    return 1;
}
ll tot;
queue<int> no[N];
void kruskal()
{
    for(int i=1,x,y;i<=idx;i++)
    {
        x=find(g[i].u),y=find(g[i].v);
        if(x==y) continue;
        if(g[i].v==0)
        {
            build[g[i].u-n]=1;
            while(!no[g[i].u-n].empty())
            {
                int u=g[no[g[i].u-n].front()].u;
                no[g[i].u-n].pop();
                x=find(u);
                if(x==y) continue;
                fa[x]=y;
                tot+=g[i].w;
                if(check()) return;
            }
        }
        if(g[i].u>n&&!build[g[i].u-n])
        {
            no[g[i].u-n].push(i);
            continue;
        }
        fa[x]=y;
        tot+=g[i].w;
        if(check()) return;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("road4.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n+k;i++) fa[i]=i;
    for(int i=1,u,v,w;i<=m;i++) cin>>u>>v>>w,add(u,v,w);
    for(int i=1;i<=k;i++)
    {
        for(int j=0,x;j<=n;j++)
        {
            cin>>x;
            add(i+n,j,x);
        }
    }
    sort(g+1,g+1+idx,cmp);
    kruskal();
    cout<<tot;
    return 0;
}
