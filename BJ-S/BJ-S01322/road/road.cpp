#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e4+12,M=1e6+6;
ll n,m,k;
int c[13];
int a[13][N];
ll ans;
vector<array<int,3> >edge;
bitset<(1<<10)+2>vis;
pair<short,int> fa[(1<<10)+2][N];
vector<pair<short,int> >g[N];
short f[N];
short get(short x)
{
    if(f[x]!=x)f[x]=get(f[x]);
    return f[x];
}
void tree(int id,short u)
{
    for(auto v:g[u])
    {
        if(v.first==fa[id][u].first)continue;
        fa[id][v.first].first=u;
        fa[id][v.first].second=v.second;
        tree(id,v.first);
    }
}
ll build(int id)
{
    ll tmp=0;
    sort(edge.begin(),edge.end());
    for(int i=1;i<=n+k;i++)f[i]=i,g[i].clear();
    for(auto e:edge)
    {
        if(get(e[1])==get(e[2]))continue;
        f[get(e[1])]=get(e[2]);
        tmp+=e[0];
        g[e[1]].push_back({e[2],e[0]});
        g[e[2]].push_back({e[1],e[0]});
    }
    tree(id,1);
    vis[id]=1;
    return tmp;
}
ll cal(int st)
{
    ll res=0;
    for(int j=0;j<10;j++)
    {
        if(st&(1<<j))res+=c[j+1];
    }
    return res;
}
void dfs(int st)
{
    if(vis[st])
    {return;}
    vis[st]=1;
    for(int j=0;j<10;j++)
    {
        if(st&(1<<j))
        {
            int omg=(st^(1<<j));
            dfs(omg);
            edge.clear();
            for(int i=2;i<=n+k;i++)
            {
                if(fa[omg][i].first)edge.push_back({fa[omg][i].second,i,fa[omg][i].first});
            }
            for(int i=1;i<=n;i++)edge.push_back({a[j+1][i],j+n+1,i});
            ans=min(ans,cal(st)+build(st));//
            break;
        }
    }
    return;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    edge.resize(m);
    for(int i=0;i<m;i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        edge[i]={w,u,v};
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    ans=build(0);
    //cout<<ans<<'\n';
    for(int i=(1<<k)-1;i;i--)dfs(i);
    cout<<ans;
    return 0;
}
