#include<bits/stdc++.h>
#define int long long
using namespace std;
int n , m , k , c[15] , a[15][10005] , fa[10005] , cnt , ans;
bitset<15> ysy;
struct p
{
    int u , v , w;
}b[1000005] , f[10005] , g[110005];
inline bool cmp(p l , p r)
{
    return l.w < r.w;
}
inline int findfa(int p)
{
    if(fa[p] == p)
    {
        return p;
    }
    fa[p] = findfa(fa[p]);
    return fa[p];
}
inline void merge(int p , int q)
{
    fa[findfa(p)] = findfa(q);
}
inline int fmst()
{
    for(int i = 1 ; i <= n ; i++)
    {
        fa[i] = i;
    }
    int anss = 0;
    for(int i = 1 ; i <= m ; i++)
    {
        if(findfa(b[i].u) != findfa(b[i].v))
        {
            anss += b[i].w;
            merge(b[i].u , b[i].v);
            cnt++;
            f[cnt] = b[i];
        }
    }
    return anss;
}
inline int mst(int l)
{
    for(int i = 1 ; i <= n + k ; i++)
    {
        fa[i] = i;
    }
    int anss = 0;
    for(int i = 1 ; i <= l ; i++)
    {
        if(findfa(g[i].u) != findfa(g[i].v))
        {
            anss += g[i].w;
            merge(g[i].u , g[i].v);
        }
    }
    return anss;
}
inline void chk()
{
    int l = cnt , cst = 0;
    for(int i = 1 ; i <= cnt ; i++)
    {
        g[i] = f[i];
    }
    for(int i = 1 ; i <= k ; i++)
    {
        if(ysy[i])
        {
            for(int j = 1 ; j <= n ; j++)
            {
                l++;
                g[l] = {n + i , j , a[i][j]};
            }
            cst += c[i];
        }
    }
    if(l == cnt)
    {
        return;
    }
    sort(g + 1 , g + l + 1 , cmp);
    ans = min(ans , mst(l) + cst);
    return;
}
inline void dfs(int dep)
{
    if(dep > k)
    {
        chk();
        return;
    }
    ysy[dep] = 0;
    dfs(dep + 1);
    ysy[dep] = 1;
    dfs(dep + 1);
    return;
}
signed main()
{
    freopen("road.in" , "r" , stdin);
    freopen("road.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1 ; i <= m ; i++)
    {
        cin >> b[i].u >> b[i].v >> b[i].w;
    }
    for(int i = 1 ; i <= k ; i++)
    {
        cin >> c[i];
        for(int j = 1 ; j <= n ; j++)
        {
            cin >> a[i][j];
        }
    }
    sort(b + 1 , b + m + 1 , cmp);
    ans = 1000000000000000018ll;
    ans = min(ans , fmst());
    dfs(1);
    cout << ans;
    return 0;
}
/*
T2 road (100pts)

思考 6

代码 27

对拍 4 Wa

代码 5

对拍 4
*/