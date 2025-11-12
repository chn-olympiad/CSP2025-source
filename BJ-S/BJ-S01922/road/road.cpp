#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+5;
ll n,m,k,fa[maxn],ans,cnt;
struct Edge{ll u,v,w;}e[maxn];
bool cmp(Edge a,Edge b)
{
    if(a.w==b.w) return (a.u<=n&&a.v<=n);
    return a.w<b.w;
}
inline ll find(ll x)
{
    if(x==fa[x]) return x;
    return fa[x]=find(fa[x]);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
    for(int j=1;j<=k;j++)
    {
        ll c;
        cin>>c,fa[n+j]=n+j;
        for(int i=1;i<=n;i++)
        {
            cin>>e[++m].w;
            e[m].u=n+j,e[m].v=i,e[m].w+=c;
        }
    }
    sort(e+1,e+1+m,cmp);
    for(ll i=1;i<=m;i++)
    {
        ll u=e[i].u,v=e[i].v,w=e[i].w;
        ll x=find(u),y=find(v);
        if(x==y) continue;
        fa[x]=y,ans+=w;
        if(u<=n&&v<=n) cnt++;
        if(cnt==n) break;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
