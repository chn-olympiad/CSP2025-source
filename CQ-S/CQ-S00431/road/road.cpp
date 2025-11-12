#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned ui;
typedef unsigned long long ull;

const int MAXN = 20100, MAXM = 1000010;

int tt = 1;

int n, m, k;

namespace miku // union-find
{
    int ff[MAXN];
    void init() {for (int i = 1; i <= n + 50; i++) ff[i] = i;}
    int getfa(int x) {return ff[x] == x? ff[x]: ff[x] = getfa(ff[x]);}
    bool merge(int x, int y) {
        x = getfa(x), y = getfa(y);
        ff[x] = y;
        return (x != y);    
    }
}

struct edge
{
    int u, v; ll w;
} e[MAXM];
bool operator<(const edge& xx, const edge& yy) {
    return xx.w < yy.w;
}

ll c[12][MAXN], a[20];
int p[12][MAXN];
int pt[20];

inline void solve()
{
    // scanf("%d%d%d", &n, &m, &k);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        // scanf("%d%d%lld", &e[i].u, &e[i].v, &e[i].w);
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    // cerr << "time usage: " << clock() * 1.00 / CLOCKS_PER_SEC << "\n";
    sort(e + 1, e + m + 1);
    // cerr << "time usage: " << clock() * 1.00 / CLOCKS_PER_SEC << "\n";
    // cout << "debug\n";
    miku::init();
    int mm = 0;
    ll ans = 0;
    for (int i = 1; i <= m && mm != n - 1; i++) {
        if (miku::merge(e[i].u, e[i].v)) ans += e[i].w, e[++mm] = e[i];
    }
    // cerr << "time usage: " << clock() * 1.00 / CLOCKS_PER_SEC << "\n";
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
        for (int j = 1; j <= n; j++) cin >> c[i][j], p[i][j] = j;
    }
    for (int i = 1; i <= k; i++) sort(p[i] + 1, p[i] + n + 1, [i](int x, int y) {return c[i][x] < c[i][y];});
    // cout << "debug\n";
    // cout << "debug: " << ans << "\n";
    // for (int i = 1; i <= k; i++)
    // {
    //     for (int j = 1; j <= n; j++) cout << p[i][j] << " ";
    //     cout << "\n";
    // }
    // cerr << "time usage: " << clock() * 1.00 / CLOCKS_PER_SEC << "\n";
    for (int s = 1; s < (1 << k); s++)
    {
        // cout << "debug: " << s << "\n";
        priority_queue<pair<ll, int> , vector<pair<ll, int> > , greater<pair<ll, int> > > pq;
        pq.push({e[1].w, 0});
        for (int i = 0; i <= k; i++) pt[i] = 1;
        ll res = 0;
        for (int i = 1; i <= k; i++) if (s & (1 << (i - 1))) pq.push({c[i][p[i][1]], i}), res += a[i];
        int tot = n + __builtin_popcount(s), now = 0;
        miku::init();
        // cout << "debug: " << s << "\n";
        // cout << pq.size() << "\n";
        while (now != tot - 1)
        {
            int id = pq.top().second; pq.pop();
            int u = id? p[id][pt[id]]: e[pt[id]].u, v = id? (n + id): e[pt[id]].v;
            ll w = id? c[id][u]: e[pt[id]].w;
            if (miku::merge(u, v)) now++, res += w;
            pt[id]++;
            if (id) {
                if (pt[id] <= n) pq.push({c[id][p[id][pt[id]]], id});
            } else if (pt[id] < n) pq.push({e[pt[id]].w, id});
            if (res >= ans) break;
        }
        // cout << "ans: " << res << "\n";
        ans = min(ans, res);
    }
    // printf("%lld\n", ans);
    cout << ans << "\n";
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    // scanf("%d", &tt);
    while (tt--) solve();
    // cerr << "time usage: " << clock() * 1.00 / CLOCKS_PER_SEC << "\n";    
    return 0;
}