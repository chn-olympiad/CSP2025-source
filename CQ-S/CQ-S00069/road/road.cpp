#include <bits/stdc++.h>

namespace CYRENE {
#define rep(i, st, ed) for (int i = (st), _##i = (ed); i <= _##i; ++i)
#define qep(i, st, ed) for (int i = (st), _##i = (ed); i <  _##i; ++i)
#define per(i, st, ed) for (int i = (st), _##i = (ed); i >= _##i; --i)
#define fi first
#define se second
#define eb emplace_back
// #define gc getchar
#define gc() (ihedp == italp && (italp = (ihedp = ibuf) + fread(ibuf, 1, BUF_SIZ, stdin), ihedp == italp) ? EOF : *(ihedp++))
#define pc putchar
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using vi = vector<int>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

namespace IO {
    constexpr size_t BUF_SIZ = 1 << 20;

    char ibuf[BUF_SIZ], *ihedp, *italp;

    template<typename T>
    void read(T &x) {
        x = 0; char c = gc(); bool f = false;
        while (!isdigit(c)) f = (c == '-'), c = gc();
        while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = gc();
        if (f) x = -x;
    }

    template<typename T, typename ...Nxt>
    void read(T &x, Nxt &...nxt) { read(x); read(nxt...); }
} using namespace IO;

template<typename T> constexpr bool chkmin(T &x, T y) { return x > y ? x = y, true : false; }

constexpr int N = 1e4 + 5, M = 1e6 + 5, K = 12, INF = 1e9;

struct Edge {
    int u, v, w;
    Edge(int _u = 0, int _v = 0, int _w = 0): u(_u), v(_v), w(_w) {}
};

int n, m, k, tot;
int a[K][N];
i64 ans;

struct {
    int fa[N + K];
    void init(int n) { iota(fa + 1, fa + n + 1, 1); }
    int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
    bool merge(int x, int y) { return (x = find(x), y = find(y), x != y) ? (fa[x] = y, true) : false; }
} dsu;

void kruskal(int n, const vector<Edge> &e1, const vector<Edge> &e2, i64 &res) {
    dsu.init(tot);
    int ent = 0;
    for (auto p1 = e1.begin(), p2 = e2.begin(); p1 != e1.end() || p2 != e2.end(); ) {
        int u, v, w;
        if (p1 == e1.end()) {
            u = p2->u;
            v = p2->v;
            w = p2->w;
            ++p2;
        } else if (p2 == e2.end()) {
            u = p1->u;
            v = p1->v;
            w = p1->w;
            ++p1;
        } else {
            if (p1->w < p2->w) {
                u = p1->u;
                v = p1->v;
                w = p1->w;
                ++p1;
            } else {
                u = p2->u;
                v = p2->v;
                w = p2->w;
                ++p2;
            }
        }
        if (dsu.merge(u, v)) {
            res += w;
            if (++ent == n - 1) break;
        }
    }
}

int moe() {
    read(n, m, k); tot = n + k;
    vector<Edge> e1(m);
    for (auto &[u, v, w]: e1) read(u, v, w);
    sort(e1.begin(), e1.end(), [](const Edge &lhs, const Edge &rhs) { return lhs.w < rhs.w; });

    kruskal(n, e1, vector<Edge>(), ans);
    if (k == 0) return printf("%lld\n", ans), 0;

    rep(i, 1, k) rep(j, 0, n) read(a[i][j]);

    const int lim = (1 << k) - 1;
    rep(s, 1, lim) {
        i64 tns = 0;
        vector<Edge> e2;
        rep(i, 1, k) if (s & (1 << (i - 1))) {
            tns += a[i][0];
            rep(j, 1, n) e2.eb(n + i, j, a[i][j]);
        }
        sort(e2.begin(), e2.end(), [](const Edge &lhs, const Edge &rhs) { return lhs.w < rhs.w; });
        kruskal(n + __builtin_popcount(s), e1, e2, tns);
        chkmin(ans, tns);
    }
    printf("%lld\n", ans);
    return 0;
}
} // namespace CYRENE

int main() {
    std::freopen("road.in", "r", stdin);
    std::freopen("road.out", "w", stdout);
    return CYRENE::moe();
}

/*
MST.
with w of edge changing.
*/

/*
g++ -o road road.cpp -std=c++17 -O2 -Wall -Wno-unused-result -g -DDEBUG -fsanitize=address,undefined
*/
