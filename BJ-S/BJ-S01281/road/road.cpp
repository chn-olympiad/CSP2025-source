#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct Edge { int u,v,w; } ed[1000010],e[10010];
inline bool cmp(Edge &x,Edge &y) { return x.w<y.w; }
int c[11]; pair<int,int> a[11][10010];
int fa[10020];
inline int find(int x) { return x==fa[x]?x:fa[x]=find(fa[x]); }
struct Prio
{
    int x,wzx,wzy;
    inline bool operator < (Prio tmp) const
    {
        return tmp.x<x;
    }
}; priority_queue<Prio> q;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1; i<=m; ++i) cin>>ed[i].u>>ed[i].v>>ed[i].w;
    sort(ed+1,ed+m+1,cmp);
    for(int i=1; i<=k; ++i)
    {
        cin>>c[i];
        for(int j=1; j<=n; ++j) cin>>a[i][j].first,a[i][j].second=j;
        sort(a[i]+1,a[i]+n+1);
    }
    int tot=0;
    for(int i=1; i<=n; ++i) fa[i]=i;
    for(int i=1; i<=m; ++i)
    {
        int fu=find(ed[i].u),fv=find(ed[i].v);
        if(fu!=fv) fa[fu]=fv,e[++tot]=ed[i];
    }
    long long ans=1e18;
    for(int i=0; i<(1<<k); ++i)
    {
        while(!q.empty()) q.pop();
        q.push({e[1].w,0,1});
        long long sum=0; int all=n-1;
        for(int j=1; j<=k; ++j)
        {
            if(i>>j-1&1) ++all,q.push({a[j][1].first,j,1}),sum+=c[j];
        }
        int cnt=0;
        for(int j=1; j<=n+k; ++j) fa[j]=j;
        while(cnt!=all && sum<ans)
        {
            Prio now=q.top(); q.pop();
            int u,v,w;
            if(now.wzx==0) u=e[now.wzy].u,v=e[now.wzy].v,w=now.x;
            else u=now.wzx+n,v=a[now.wzx][now.wzy].second,w=now.x;
            int fu=find(u),fv=find(v);
            if(fu!=fv) ++cnt,sum+=w,fa[fu]=fv;
            if(now.wzx==0 && now.wzy!=n-1) q.push({e[now.wzy+1].w,now.wzx,now.wzy+1});
            if(now.wzx!=0 && now.wzy!=n) q.push({a[now.wzx][now.wzy+1].first,now.wzx,now.wzy+1});
        }
        ans=min(ans,sum);
    }
    cout<<ans;
    return 0;
}
