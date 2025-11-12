#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k,x[15],a[15][10005],fa[10015],res,ans=1e9,tot,cnt;
vector<ll> re;
struct node
{
    ll u,v,w;
    bool operator<(node cspjy)const
    {
        return w<cspjy.w;
    }
}edge[1100005],edge1[1100005];
ll find(ll u)
{
    if(u==fa[u]) return u;
    return fa[u]=find(fa[u]);
}
void dfs(ll now)
{
    if(now==k+1)
    {
        for(ll i=1;i<=tot;i++) edge1[i].u=edge[i].u,edge1[i].v=edge[i].v,edge1[i].w=edge[i].w;
        for(ll i=1;i<=n+k;i++) fa[i]=i;
        ll cntt=0,val=0;
        sort(edge1+1,edge1+1+tot);
        for(ll i=1;i<=tot;i++)
        {
            if(cntt==n+cnt-1) break;
            ll u=edge1[i].u,v=edge1[i].v,w=edge1[i].w;
            ll uu=find(u),vv=find(v);
            if(uu==vv) continue;
            val+=w,cntt++,fa[uu]=vv;
            if(val+res>=ans) break;
        }
        ans=min(ans,val+res);
    }
    else
    {
        dfs(now+1);
        for(ll i=1;i<=n;i++)
        {
            tot++;
            edge[tot].u=n+now,edge[tot].v=i,edge[tot].w=a[now][i];
        }
        cnt++,res+=x[now];
        if(res<=ans) dfs(now+1);
        cnt--,tot-=n,res-=x[now];
    }
    return;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for(ll i=1;i<=m;i++) cin>>edge[i].u>>edge[i].v>>edge[i].w;
    for(ll i=1;i<=k;i++)
    {
        cin>>x[i];
        for(ll j=1;j<=n;j++) cin>>a[i][j];
    }
    tot=m;
    dfs(1);
    cout<<ans;
    return 0;
}
