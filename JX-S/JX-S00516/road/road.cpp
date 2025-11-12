#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'

constexpr int MAXN = 1e4 + 5;
constexpr int MAXM = 1e6 + 5;
constexpr int MAXK = 15;
int n, m, k;
struct Edge {
    int u, v, w;
    friend bool operator<(Edge a, Edge b) {
        return a.w < b.w;
    }
} e[MAXM];
int c[MAXK], a[MAXK][MAXN], id[MAXN], bd[MAXN];
int current;

bool cmp(int x, int y) {
    return a[current][x] < a[current][y];
}

namespace DSU {
int c[MAXN];
void init() {
    rep (i, 1, n) c[i] = i;
}
int get(int x) {
    if (x == c[x]) return x;
    return c[x] = get(c[x]);
}
void merge(int x, int y) {
    x = get(x), y = get(y);
    c[x] = y;
}
}

signed main() {
#ifndef INFTER
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;
    rep (i, 1, m) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    int ans = 0;
    rep (i, 1, k) {
        cin >> c[i];
        rep (j, 1, n) {
            cin >> a[i][j];
            id[j] = j;
        }
        current = i;
        sort(id + 1, id + n + 1, cmp);
        // rep (j, 1, n) cerr << id[j] << " ";
        // cerr << endl;
        bd[id[1]] = i;
        ans += c[i] + a[i][id[1]];
        rep (j, 2, n) {
            e[++m] = {id[1], id[j], a[i][id[j]]};
        }
    }
    // cerr << ans << endl;
    // cerr << "OK" << endl;
    sort(e + 1, e + m + 1);
    DSU::init();
    rep (i, 1, m) {
        // cerr << e[i].u << " " << e[i].v << endl;
        if (DSU::get(e[i].u) != DSU::get(e[i].v)) {
            DSU::merge(e[i].u, e[i].v);
            ans += e[i].w;
        }
    }
    cout << ans << endl;

    return 0;
}