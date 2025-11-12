#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 5;
struct edge
{
    int u,v;
    long long w;
}edges[50*N],ufl[N],nw[N];
long long nd[N],c[N],f[15][N];
int ft[N],lg2[N],sz[N];
long long an;
int bs,n,m,k;
int fnd(int u)
{
    if(ft[u] == u)
        return u;
    return ft[u] = fnd(ft[u]);
}
void merge(int u,int v)
{
    int a = fnd(u),b = fnd(v);
    ft[a] = b;
}
void krus()
{
    sort(edges+1,edges+m+1,
    [&](edge x,edge y)
    {
        return x.w < y.w;
    });
    for(int i = 1;i<=n;i++)
        ft[i] = i;
    int u,v;
    long long w;
    for(int i = 1;i<=m;i++)
    {
        if(bs == n-1)
            return ;
        u = edges[i].u,v = edges[i].v,w = edges[i].w;
        if(fnd(u) == fnd(v))
            continue;
        merge(u,v);
        ufl[++bs] = edges[i];
        an += w;
    }
}
long long krus2(int st)
{
    long long s = 0;
    for(int i = 1;i<=n+k;i++)
        ft[i] = i;
    int tbs = 0,u,v;
    long long w;
    int i = 1,j = 1;
            while(j <= n*k && !((st << 1 >> (nw[j].u-n))&1))    j++;
    while(1)
    {
        if(tbs == n+sz[st]-1)
            return s;
        edge tnw;
        if(i > bs && j > n*k)
            break;
        if(i > bs)
        {
            tnw = nw[j];
            j++;
            while(j <= n*k && !((st << 1 >> (nw[j].u-n))&1))    j++;
        }
        else if(j > n*k)
        {
            tnw = ufl[i];
            i++;
        }
        else if(ufl[i].w <= nw[j].w)
        {
            tnw = ufl[i];
            i++;
        }
        else
        {
            tnw = nw[j];
            j++;
            while(j <= n*k && !((st << 1 >> (nw[j].u-n))&1))    j++;
        }
        u = tnw.u,v = tnw.v,w = tnw.w;
        // cout << u <<" " << v <<"\n";
        if(fnd(u) == fnd(v))
            continue;
        merge(u,v);
        tbs++;
        s += w;
    }
    return s;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int u,v,w;
    cin >> n >> m >> k;
    for(int i = 1;i<=m;i++)
    {
        cin >> u >> v >> w;
        edges[i] = {u,v,w};
    }
    for(int i = 1;i<=k;i++)
    {
        cin >> c[i];
        for(int j = 1;j<=n;j++)
            cin >> f[i][j];
    }
    krus();
    for(int i = 0;i<=10;i++)
        lg2[(1 << i)] = i;
    int tbs = 0;
    for(int j = 1;j<=k;j++)
        for(int tk = 1;tk<=n;tk++)
            nw[++tbs] = {n+j,tk,f[j][tk]};
    sort(nw+1,nw+n*k+1,
    [&](edge x,edge y)
    {
        return x.w < y.w;
    });
    for(int i = 1;i<(1 << k);i++)
    {
        nd[i] = nd[i^(i & (-i))] + c[lg2[(i & (-i))]+1];
        sz[i] = sz[i&(i-1)]+1;
        // cout << i <<"\n";
        an = min(an,nd[i]+krus2(i));
    }
    cout << an <<"\n";
    return 0;
}