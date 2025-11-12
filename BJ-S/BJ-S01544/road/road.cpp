#include <bits/stdc++.h>
using namespace std;
#define il inline
#define pb push_back
typedef long long ll;
const int N = 2e6 + 10;
struct node
{
    int u, v, w;
}e[N];
vector<node> b[N];
int f[N], n, m, k;
il int find(int x)
{
    return f[x] == x ? x : f[x] = find(f[x]);
}
int c[11], a[11][N], tot, tt;
unordered_map<int, int> mp;
set<int> s;
il ll kruskal(int x)
{
    int nn = n, V = 0;
    ll mst = 0;
    for(int i = 0;i < k;++i)
    {
        if(!((x >> i) & 1)) continue;
        ++nn;
        for(int j = 1;j <= n;++j)
        {
            b[mp[a[i][j]]].pb((node){nn, j, a[i][j]});
            V = max(V, mp[a[i][j]]);
        }
        mst += c[i];
    }
    for(int i = 1;i <= nn;++i) f[i] = i;
    for(int i = 1;i <= tt;++i)
    {
        for(auto j : b[i])
        {
            if(find(j.u) == find(j.v)) continue;
            mst += j.w;
            f[find(j.u)] = find(j.v);
        }
    }
    for(int i = 1;i <= V;++i)
        while(b[i].size() && b[i].back().u > n) b[i].pop_back();
    return mst;
}
il int read()
{
    char ch = getchar();
    while(ch < 48 || ch > 57) ch = getchar();
    int x = 0;
    while(48 <= ch && ch <= 57)
    {
        x = (x << 1) + (x << 3) + ch - 48;
        ch = getchar();
    }
    return x;
}
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    n = read(), m = read(), k = read();
    for(int i = 1;i <= m;++i)
    {
        e[i].u = read(), e[i].v = read(), e[i].w = read();
        s.insert(e[i].w);
    }
    int tmp = 0;
    for(int i = 0;i < k;++i)
    {
        c[i] = read();
        tmp = max(tmp, c[i]);
        for(int j = 1;j <= n;++j)
        {
            a[i][j] = read();
            s.insert(a[i][j]);
        }
    }
    for(auto i : s) mp[i] = ++tt;
    for(int i = 1;i <= m;++i) b[mp[e[i].w]].pb(e[i]);
    if(!tmp)
    {
        cout << kruskal((1 << k) - 1);
        return 0;
    }
    ll ans = 1e18;
    for(int i = 0;i < (1 << k);++i) ans = min(ans, kruskal(i));
    cout << ans;
    return 0;
}
