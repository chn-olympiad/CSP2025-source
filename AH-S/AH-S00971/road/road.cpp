#include <bits/stdc++.h>

using ll = long long;

using namespace std;

const int N = 1e4 + 10;
const int K = 15;

struct DSU {
    int n, fa[N], rnk[N];
    void init (int x) { n = x; for (int i = 1; i <= n; i ++) fa[i] = i, rnk[i] = 1; }
    int find (int x) { return x == fa[x] ? x : fa[x] = find (fa[x]); }
    bool merge (int x, int y) { x = find (x), y = find (y); if (x == y) return false; if (rnk[x] < rnk[y]) swap (x, y); fa[y] = x; rnk[x] += (rnk[y] == rnk[x]); return true; }
} dsu;

int n, m, k;
ll c[K], a[K][N]; 
bool in[N];
vector < tuple <ll, int, int> > edge, ne;

namespace featureA {
    int main () {
        ne = edge;
        for (int i = 0; i < k; i ++) {
            for (int j = 1; j <= n; j ++) {
                if (!a[i][j]){ 
                    for (int k = 1; k <= n; k ++) {
                        if (k == j) continue;
                        ne.emplace_back (a[i][k], j, k);
                    }
                    break ;
                }
            }
        }
        dsu.init (n);

        ll tmp = 0;
        for (const auto [w, u, v] : ne) if (dsu.merge (u, v))  {
            tmp += w;
        }
        printf ("%lld\n", tmp);
        return 0;
    }
}

int main (void) {

    // auto st = clock ();

    freopen ("road.in", "r", stdin);
    freopen ("road.out", "w", stdout);

    scanf ("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i ++) {
        int u, v, w;
        scanf ("%d%d%d", &u, &v, &w);
        edge.emplace_back (w, u, v);
    } int ff = 0; ne = edge;
    for (int i = 0; i < k; i ++) {
        scanf ("%lld", c + i); ff |= c[i];
        int tmp = 1;
        for (int j = 1; j <= n; j ++) {
            scanf ("%lld", &a[i][j]);
            ne.emplace_back (a[i][j], i + n + 1, j);
            tmp &= (a[i][j] > 0);
            in[j] = true;
        }
        if (tmp) ff = 1;
    }
    // if (!ff) return featureA :: main ();
    sort (ne.begin (), ne.end ());

    ll ans = 1e18;
    for (int msk = 0; msk < (1 << k); msk ++) {
        int cnt = 0;
        ll tmp = 0;
        for (int i = 0; i < k; i ++)
            if (msk >> i & 1) {
                tmp += c[i];
                in[i + 1 + n] = true;
            }
        dsu.init (n + k);

        for (const auto [w, u, v] : ne) if (in[u] && in[v] && dsu.merge (u, v))  {
            tmp += w;
            if (tmp > ans) break;
        }
        for (int i = 0; i < k; i ++) if (msk >> i & 1) in[i + 1 + n] = false;
        ans = min (ans, tmp);
    }

    printf ("%lld\n", ans);

    // fprintf (stderr, "%.2fms\n", (clock () - st) * 1000.0 / CLOCKS_PER_SEC);

    return 0;
}