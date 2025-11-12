#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// #define int ll
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = 1e4 + 5;
const int K = 10 + 5;
const int M = 1e4 * 10 + 1e6 + 5;
bool __st__;
int n, m, k;
struct node
{
    int u, v;
    ll w;
    bool operator<(const node &T) const & { return w < T.w; }
};
struct DSU
{
    int n;
    vector<int> siz, fa;
    void in(int _n)
    {
        n = _n + 1;
        siz.assign(n, 1);
        fa.assign(n, 0);
        for (int i = 1; i <= _n; i++)
            fa[i] = i;
    }
    int find(int k)
    {
        if (fa[k] == k)
            return k;
        else
            return fa[k] = find(fa[k]);
    }
    void merge(int x, int y)
    {
        x = find(x), y = find(y);
        if (x == y)
            return;
        if (siz[x] > siz[y])
            swap(x, y);
        siz[y] += siz[x];
        fa[x] = y;
    }
} d;
vector<node> g;
ll a[K][N];
bool __ed__;
void PrintMemUse() { cerr << (&__st__ - &__ed__) / 1048576.0 << '\n'; }
int Krus(vector<node> &edge, int nx)
{
    d.in(nx);
    sort(edge.begin(), edge.end());
    ll ans = 0;
    int tot = 0;
    for (node tmp : edge)
    {
        int u = tmp.u, v = tmp.v, w = tmp.w;
        if (d.find(u) == d.find(v))
            continue;
        tot++;
        ans += w;
        d.merge(u, v);
        if (tot == nx - 1)
            break;
    }
    if (tot != nx - 1)
        cerr << "?";
    return ans;
}
void Force_14() { cout << Krus(g, n) << '\n'; }
void Force()
{
    vector<node> gx;
    ll ans = 1e18;
    for (int i = 0; i < (1 << k); i++)
    {
        ll cur = 0, cnt = 0;
        for (int j = 0; j < k; j++)
            if (i >> j & 1)
                cur += a[j + 1][0];
        for (node tmp : g)
            gx.push_back(tmp);
        for (int x = 0; x < k; x++)
            if (i >> x & 1)
            {
                cnt++;
                for (int j = 1; j <= n; j++)
                    gx.push_back({j, n + (int)cnt, a[x + 1][j]});
            }
        cur += Krus(gx, n + cnt);
        ans = min(ans, cur);
        gx.clear();
        gx.shrink_to_fit();
    }
    cout << ans << '\n';
}
bool checksss()
{
    for (int i = 1; i <= k; i++)
        if (a[i][0] != 0)
            return 0;
    for (int i = 1; i <= k; i++)
    {
        bool ok = 0;
        for (int j = 1; j <= n && !ok; j++)
            if (!a[i][j])
                ok = 1;
        if (!ok)
            return 0;
    }
    return 1;
}
signed main()
{
    FASTIO;
    // PrintMemUse(); //1.14511
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1, u, v, w; i <= m; i++)
    {
        cin >> u >> v >> w;
        g.push_back({u, v, w});
    }
    for (int i = 1; i <= k; i++)
        for (int j = 0; j <= n; j++)
            cin >> a[i][j];
    if (checksss())
    {
        for (int i = 1; i <= k; i++)
            for (int j = 1; j <= n; j++)
                g.push_back({i + n, j, a[i][j]});
        cout << Krus(g, k + n);
    }
    else
        return Force(), 0;
    return 0;
}
/*
g++ road.cpp -o road.exe -std=c++14 -O2 '-Wl,--stack=536870912' -Wall
./road.exe
*/