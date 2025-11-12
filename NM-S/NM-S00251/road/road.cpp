#include <bits/stdc++.h>
using namespace std;

struct FastInput {
    static const int BUFSIZE = 1 << 20;
    int idx, len;
    char buf[BUFSIZE];
    FastInput() : idx(0), len(0) {}
    inline char nextChar() {
        if (idx >= len) {
            len = fread(buf, 1, BUFSIZE, stdin);
            idx = 0;
            if (len == 0) return 0;
        }
        return buf[idx++];
    }
    template <typename T>
    bool read(T &out) {
        char c = 0;
        T sign = 1, val = 0;
        c = nextChar();
        if (!c) return false;
        while (c != '-' && (c < '0' || c > '9')) {
            c = nextChar();
            if (!c) return false;
        }
        if (c == '-') {
            sign = -1;
            c = nextChar();
        }
        for (; c >= '0' && c <= '9'; c = nextChar())
            val = val * 10 + (c - '0');
        out = val * sign;
        return true;
    }
};

struct Edge {
    int u, v;
    long long w;
    int mask;
};

struct DSU {
    vector<int> parent, rnk, cityCnt;
    DSU(int n = 0) { init(n); }
    void init(int n) {
        parent.resize(n + 1);
        rnk.assign(n + 1, 0);
        cityCnt.assign(n + 1, 0);
        for (int i = 1; i <= n; ++i) parent[i] = i;
    }
    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    bool unite(int a, int b, int &cityComp) {
        int ra = find(a), rb = find(b);
        if (ra == rb) return false;
        bool ca = cityCnt[ra] > 0;
        bool cb = cityCnt[rb] > 0;
        if (rnk[ra] < rnk[rb]) swap(ra, rb);
        parent[rb] = ra;
        cityCnt[ra] += cityCnt[rb];
        if (rnk[ra] == rnk[rb]) ++rnk[ra];
        if (ca && cb) --cityComp;
        return true;
    }
};

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    FastInput in;
    int n, m, k;
    if (!in.read(n)) return 0;
    in.read(m);
    in.read(k);
    vector<Edge> edges;
    edges.reserve((long long)m + (long long)n * k);

    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        in.read(u);
        in.read(v);
        in.read(w);
        edges.push_back({u, v, w, 0});
    }

    vector<long long> costTown(k);
    for (int j = 0; j < k; ++j) {
        long long cj;
        in.read(cj);
        costTown[j] = cj;
        for (int i = 1; i <= n; ++i) {
            long long a;
            in.read(a);
            edges.push_back({n + 1 + j, i, a, 1 << j});
        }
    }

    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) { return a.w < b.w; });

    int totalNodes = n + k;
    DSU dsu(totalNodes);

    int totalMasks = 1 << k;
    vector<long long> addCost(totalMasks, 0);
    for (int mask = 1; mask < totalMasks; ++mask) {
        int lb = __builtin_ctz(mask);
        addCost[mask] = addCost[mask ^ (1 << lb)] + costTown[lb];
    }

    long long answer = LLONG_MAX;

    for (int mask = 0; mask < totalMasks; ++mask) {
        dsu.init(totalNodes);
        for (int i = 1; i <= n; ++i) dsu.cityCnt[i] = 1;
        int cityComp = n;
        long long mstCost = 0;
        for (const auto &e : edges) {
            if (e.mask && ((mask & e.mask) == 0)) continue;
            if (dsu.unite(e.u, e.v, cityComp)) {
                mstCost += e.w;
                if (cityComp == 1) break;
            }
        }
        long long total = mstCost + addCost[mask];
        if (total < answer) answer = total;
    }

    printf("%lld\n", answer);
    return 0;
}
