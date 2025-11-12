#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <ctime>
#include <random>
#include <chrono>

typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
typedef unsigned int uint;

using namespace std;

const int MAXN = 1e4 + 20, MAXM = 1e6 + 10, MAXQ = 2e5 + 10;
const ll inf = 1e18;

int n, m, k;

struct edge
{
    int u, v, w;
    bool operator < (const edge &x) const { return w < x.w; }
};

int c[12], len[1030];
edge e[MAXM], a[12][MAXN], b[1030][MAXN], d[MAXN << 1];

int fa[MAXN], sz[MAXN];
inline int find(int k) { return fa[k] == k ? fa[k] : fa[k] = find(fa[k]); }
inline void merge(int u, int v)
{
    u = find(u), v = find(v);
    if (u == v) return;
    if (sz[u] < sz[v]) fa[u] = v, sz[v] += sz[u];
    else fa[v] = u, sz[u] += sz[v];
}

int main()
{
    // int st = clock();
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) cin >> e[i].u >> e[i].v >> e[i].w;
    int _m = 0; sort(e + 1, e + m + 1);
    for (int i = 1; i <= n; i++) fa[i] = i, sz[i] = 1;
    for (int i = 1; i <= m; i++)
        if (find(e[i].u) ^ find(e[i].v)) e[++_m] = e[i], merge(e[i].u, e[i].v);
    m = _m;
    for (int i = 0; i < k; i++)
    {
        cin >> c[i];
        for (int j = 1; j <= n; j++) cin >> a[i][j].w, a[i][j].u = n + i + 1, a[i][j].v = j;
        sort(a[i] + 1, a[i] + n + 1);
    }
    ll ans = inf;
    for (int s = 0; s < (1 << k); s++)
    {
        ll sum = 0;
        int cnt = n;
        for (int i = 0; i < k; i++)
            if (s >> i & 1) sum += c[i], cnt++;
        
        int tot = m;
        if (s == 0)
        {
            for (int i = 1; i <= m; i++) d[i] = b[s][i] = e[i];
            len[s] = m;
        }
        else
        {
            int t = s ^ (s & -s), p = __builtin_ctz(s);
            for (int i = 1, j = 1, k = 1; i <= len[t] || j <= n; )
                if (j > n || (i <= len[t] && b[t][i] < a[p][j])) d[k++] = b[t][i++];
                else d[k++] = a[p][j++];
            tot = len[t] + n;
        }

        for (int i = 1; i <= n + k; i++) fa[i] = i, sz[i] = 1;
        int _tot = 0;
        for (int i = 1; i <= tot && cnt > 1; i++)
        {
            if (find(d[i].u) ^ find(d[i].v)) sum += d[i].w, merge(d[i].u, d[i].v), cnt--, d[++_tot] = d[i];
        }
        len[s] = _tot;
        for (int i = 1; i <= _tot; i++) b[s][i] = d[i];
        ans = min(ans, sum);
    }
    cout << ans << '\n';
    // cerr << 1.0 * (clock() - st) / CLOCKS_PER_SEC << '\n';
    return 0;
}