#include <bits/stdc++.h>
using namespace std;

using u32 = uint32_t;
using u64 = uint64_t;
using i32 = int32_t;
using i64 = int64_t;

template <u64 N>
struct dsu {
    u32 parent[N], size[N];
    dsu() {
        fill(size, size + N, 1);
        iota(parent, parent + N, 0);
    }
    u32 find (u32 p) { return p == parent[p] ? p : parent[p] = find(parent[p]); }
    bool same (u32 i, u32 j) { return find(i) == find(j); }
    void merge (u32 i, u32 j) {
        i = find(i), j = find(j);
        if (size[i] > size[j]) swap(i, j);
        parent[i] = j, size[j] += size[i];
    }
};

constexpr u64 N = 10'000, K = 10, M = 1'000'000;

array<i64, 4> edges[M + N * K]; // (#, u, v, w), extra = n + i;
i64 built[N], stamp, sz, n, m, k;
array<array<array<i64, 3>, N>, K + 1> pending;
array<array<i64, 3>, N> pd, nw;
array<array<i64, 3>, N * 2> rt;
i64 ans = numeric_limits<i64>::max();

bool cmp4(array<i64, 4> x, array<i64, 4> y) {
    return array<i64, 4>{x[0],x[3],x[1],x[2]} < array<i64, 4>{y[0],y[3],y[1],y[2]};
}

bool cmp3(array<i64, 3> x, array<i64, 3> y) {
    return array<i64, 3>{x[2],x[0],x[1]} < array<i64, 3>{y[2],y[0],y[1]};
}

i64 from(i64 i) {
    return lower_bound(edges, edges + sz, array<i64, 4>{i, 0, 0, 0}, cmp4) - edges;
}

i64 to(i64 i) {
    constexpr i64 M = numeric_limits<i64>::max();
    return upper_bound(edges, edges + sz, array<i64, 4>{i, M, M, M}, cmp4) - edges;
}

void kruskal() {
    i64 res = 0, h = 0;
    dsu<N + K> uf;
    for (u32 i = n * k; i < m + n * k; i++) {
        auto u = edges[i][1], v = edges[i][2], w = edges[i][3];
        if (uf.same(u, v)) continue;
        uf.merge(u, v), res += w, pd[h++] = {u, v, w};
    }
    pending[0] = pd;
    ans = min(ans, res);
}

bool vis[1 << K];

void calc(u32 tot, u32 p, int cge = -1, u32 dpt = 0) {
    if (vis[p]) return;
    vis[p] = true;
    u32 R = __builtin_popcount(p);
    if (p >= (1 << tot)) return;
    if (cge == -1) {
        kruskal();
    } else {
        i64 res = 0;
        for (u32 i = 0; i < k; i++) if ((p >> i) & 1) res += built[i];
        // calc. given: pd -> calc. pending[cge] and do rev[p];
        for (u32 i = from(~i64(cge)), j = 0; i < to(~i64(cge)); i++, j++) for (auto d : {0, 1, 2}) nw[j][d] = edges[i][d + 1];
        u32 l = 0, r = 0, h = 0;
        while (l < n + R - 2 && r < n) {
            bool pred = cmp3(pd[l], nw[r]);
            rt[h++] = (pred ? pd[l++] : nw[r++]);
        }
        while (l < n + R - 2) rt[h++] = pd[l++];
        while (r < n) rt[h++] = nw[r++];
        assert(h == 2 * n + R - 2);
        dsu<N + K> uf;
        h = 0;
        for (u32 i = 0; i < 2 * n - 1; i++) {
            auto u = rt[i][0], v = rt[i][1], w = rt[i][2];
            if (uf.same(u, v)) continue;
            res += w, uf.merge(u, v), pending[dpt][h++] = {u, v, w};
        }
        ans = min(ans, res);
    }
    for (u32 i = 0; i < k; i++) {
        pd = pending[dpt];
        if (((~p) >> i) & 1) calc(tot, p | (1 << i), i, dpt + 1); 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (u32 _ = 0, u, v, w; _ < m; _++) {
        cin >> u >> v >> w, u--, v--;
        edges[_ + n * k] = {0, u, v, w};
    }
    for (u32 j = 0; j < k; j++) {
        cin >> built[j];
        for (u32 l = 0, w; l < n; l++)
            cin >> w, edges[n * j + l] = {~i64(j), n + j, l, w};
    }
    sz = m + n * k, sort(edges, edges + sz, cmp4);
    calc(k, 0);
    cout << ans << endl;
}

/**
 * 16:42
 * ~0.56 s, 100
 */