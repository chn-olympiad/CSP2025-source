#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
struct edge
{
    int u,v,w;
}edges[10000010];
int tot;
int c[11],a[20010][11]; 
int fa[20010];
int getf(int x){return fa[x] == x ? x : fa[x] = getf(fa[x]);}
signed main()
{  
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1;i <= n + 100;i ++) fa[i] = i;
    for(int i = 1;i <= m;i ++) cin >> edges[i].u >> edges[i].v >> edges[i].w;
    tot = m;
    bool fl = true;
    for(int i = 1;i <= k;i ++)
    {
        cin >> c[i];
        if(c[i] != 0) fl = false;
        bool f =false;
        for(int j = 1;j <= n;j ++) 
        {
            cin >> a[j][i];
            if(a[j][i] == 0) f = true;
        }
        if(!f) fl = false;
    }
    if(fl)
    {
        int ans = 0;
        for(int i = 1;i <= k;i ++)
        {
            for(int j = 1;j <= n;j ++)
            {
                edges[++tot].u = i + n;
                edges[tot].v = j;
                edges[tot].w = a[j][i];
            }
        }
        sort(edges + 1,edges + tot + 1,[](edge a,edge b){return a.w < b.w;});
        for(int i = 1;i <= tot;i ++)
        {
            int x =getf(edges[i].u);
            int y = getf(edges[i].v);
            if( x != y)
            {
                ans += edges[i].w;
                fa[x] = y ;
            }
        }
        cout<<ans<<"\n";
        return 0;
    }
    int ans = 0;
    for(int i = 1;i <= n + k;i ++) fa[i] = i;
    sort(edges + 1,edges + m + 1,[](edge a,edge b){return a.w < b.w;});
    for(int i = 1;i <= m;i ++)
    {
        int x = getf(edges[i].u);
        int y = getf(edges[i].v);
        if(x != y)
        {
            ans += edges[i].w;
            fa[x] = y;
        }
    }
    if(k == 0) 
    {
        cout << ans << "n";
        return 0;
    }
    int res = ans;
    for(int i = 0;i <= (1 << k) - 1;i ++)
    {
        tot = m;
        int t = 0;
        for(int j = 1;j <= k;j++)
        {

            if(i & (1 << (j - 1))) 
            {
                t += c[j]; 
                for(int l = 1;l <= n;l ++)
                {
                    edges[++tot].u = l;
                    edges[tot].v = j + n;
                    edges[tot].w = a[l][j];
                }
            }
        }
        for(int j = 1;j <= n + k;j ++) fa[j] = j;
        sort(edges + 1,edges + tot + 1,[](edge a,edge b){return a.w < b.w;});
        for(int j= 1;j <=tot;j ++)
        {
            int x = getf(edges[j].u);
            int y = getf(edges[j].v);
            if(x != y) 
            {
                t += edges[j].w;
                fa[x] = y;
            } 
        }
        res = min(res,t);
    }
    cout<<res<<endl;
    return 0;
}