#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+50;
int fa[N];
struct node
{
    int u,v,w;
};
int ans;
vector<node> e;
int n,m,k;
int find(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=find(x);
}
bool check()
{
    for(int i=1;i<n;i++) if(fa[i]!=fa[i+1]) return 0;
    return 1;
}
bool cmp(node aa,node bb)
{
    return aa.w<bb.w;
}
void krs()
{
    sort(e.begin(),e.end()-1,cmp);
    for(int i=0;i<e.size()&&!check();i++)
    {
        int u=e[i].u;
        int v=e[i].v;
        int w=e[i].w;
        if(fa[u]==fa[v]) continue;
        ans+=w;
        fa[find(u)]=find(v);
    }

}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        e.push_back({u,v,w});
    }
    for(int i=1;i<=k;i++)
    {
        int c;
        scanf("%lld",&c);
        for(int j=1;j<=n;j++)
        {
            int v;
            scanf("%lld",&v);
            e.push_back({n+i,i,v+c});

        }
    }
    n+=k;
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
    }
    krs();
    cout<<ans;
    return 0;
}
