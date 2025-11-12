#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e4+20;
int n,m,k;
struct edge
{
    int u,v;
    ll w;
};
vector<edge> g;
ll ans=0;
int fa[N];

bool cmp(edge x,edge y)
{
    return x.w<y.w;
}

int find(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}

void join(int x,int y)
{
    int rx=find(x),ry=find(y);
    fa[rx]=ry;
}

int main()
{
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        ll t; cin>>x>>y>>t;
        g.push_back({x,y,t});
    }
    for(int i=1;i<=k;i++)
    {
        int t; cin>>t;
        for(int j=1;j<=n;j++)
        {
            ll w; cin>>w;
            g.push_back({i,j,w});
        }
    }

    for(int i=0;i<=n;i++) fa[i]=i;
    sort(g.begin(),g.end(),cmp);
    for(auto [u,v,w]:g)
        if(find(u)!=find(v))
        {
            join(u,v);
            ans+=w;
        }
    cout<<ans;
    return 0;
}
