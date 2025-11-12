#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{int u,v,w;};
vector<node>es;
vector<int>p;
int c[19],n,m,k;
bool vis[19];
ll cnt=INT_MAX;
bool cmp(node a,node b){return a.w<b.w;}
int f(int x)
{
    return (x==p[x])?x:p[x]=f(p[x]);
}
ll minitree(ll temp,int o)
{
    for(int i=1;i<=n+k;i++)
    {
        if(i<=n||(i>n&&vis[i-n]==1))p[i]=i;
        else p[i]=0;
    }
    ll ans=0,flg=0;
    for(auto e:es)
    {
        if(e.u>n&&vis[e.u-n]==0)continue;
        int u=f(e.u),v=f(e.v);
        if(u!=v)
        {
            p[u]=p[v];
            ans+=e.w;
            if(++flg==o)break;
        }
    }
    return 1ll*(ans+temp);
}
void dfs(int i,ll tot,int o)
{
    if(i==k+1)cnt=min(cnt,minitree(tot,o+n-1));
    else
    {
        vis[i]=1;
        dfs(i+1,tot+c[i],o+1);
        vis[i]=0;
        dfs(i+1,tot,o);
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    ios::sync_with_stdio(0);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        es.push_back({u,v,w});
    }
    p.resize(n+1);
    for(int i=1;i<=n;i++)p[i]=i;
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
        {
            int t;
            cin>>t;
            es.push_back({n+i,j,t});
        }
    }
    sort(es.begin(),es.end(),cmp);
    dfs(1,0,0);
    cout<<cnt;
    return 0;
}

