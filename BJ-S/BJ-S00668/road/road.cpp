#include<bits/stdc++.h>
#define pb push_back
#define endl '\n'

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int N=1e4+233,M=1e6+233;
int n,m,k,c[11],a[11][N];
struct edge
{
    int u,v,w;
}e[M<<1];
inline bool operator<(edge x,edge y)
{
    return x.w<y.w;
}
int fa[N];
inline int gtf(int u)
{
    return u==fa[u]?u:fa[u]=gtf(fa[u]);
}
inline bool trA()
{
    for (int i=1;i<=k;i++)
        if (c[i]) return 0;
    return 1;
}
inline void doA()
{
    for (int i=1;i<=k;i++)
    {
        int t;
        for (int j=1;j<=n;j++)
            if (a[i][j]==0) t=j;
        for (int j=1;j<=n;j++)
            if (t!=j) e[++m]={t,j,a[i][j]};
    }
    sort(e+1,e+1+m);
    ll ans=0,cnt=0;
    for (int i=1;i<=m;i++)
    {
        int u=gtf(e[i].u),v=gtf(e[i].v),w=e[i].w;
        if (u!=v) ans+=w,cnt++,fa[u]=v;
        if (cnt==n-1) break;
    }
    cout<<ans<<endl;
}
inline ll calc(int opr)
{
    int tm=m;
    ll ans=0;
    for (int i=1;i<=k;i++)
    {
        if (opr>>i-1&1)
        {
            ans+=c[i];
            for (int j=1;j<=n;j++)
                for (int k=j+1;k<=n;k++)
                e[++m]={j,k,a[i][j]+a[i][k]};
        }
    }
    sort(e+1,e+1+m);
    int cnt=0;
    for (int i=1;i<=m;i++)
    {
        int u=gtf(e[i].u),v=gtf(e[i].v),w=e[i].w;
        if (u!=v) ans+=w,cnt++,fa[u]=v;
        if (cnt==n-1) break;
    }
    m=tm;
    for (int i=1;i<=n;i++) fa[i]=i;
    return ans;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);

    cin>>n>>m>>k;
    for (int i=1;i<=m;i++)
        cin>>e[i].u>>e[i].v>>e[i].w;
    for (int i=1;i<=k;i++)
    {
        cin>>c[i];
        for (int j=1;j<=n;j++) cin>>a[i][j];
    }
    for (int i=1;i<=n;i++) fa[i]=i;
    if (trA()) return doA(),0;
    ll ans=1e18;
    for (int i=0;i<1<<k;i++)
        ans=min(ans,calc(i));
    cout<<ans<<endl;

    return 0;
}


