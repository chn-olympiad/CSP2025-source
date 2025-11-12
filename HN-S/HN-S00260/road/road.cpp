#include <cstdio>
#include <vector>
#include <algorithm>

constexpr int MAX_N = 10000 + 2;
constexpr int MAX_M = 1000000 + 2;
constexpr int MAX_K = 10 + 2;

int n, m, k, rt[MAX_N + MAX_K], c[MAX_K];

long long ans;

class Edge {
  public:
    int u, v, w;

    bool operator<(const Edge &rhs) const {
        return w < rhs.w;
    }
} tmp[MAX_M], eg[MAX_K][MAX_N];

std::vector<Edge> tree[MAX_K];

int findRoot(int x) {
    return rt[x] ? rt[x] = findRoot(rt[x]) : x;
}

bool merge(int x, int y) {
    x = findRoot(x);
    y = findRoot(y);

    if (x == y) {
        return false;
    }

    return rt[x] = y, true;
}

long long kruskal(int e, std::vector<Edge> &tar) {
    for (int i = 1; i <= n + k; i++) {
        rt[i] = 0;
    }

    tar.clear();

    long long ret = 0;

    for (int i = 0; i < e; i++) {
        if (merge(tmp[i].u, tmp[i].v)) {
            tar.push_back(tmp[i]);
            ret += tmp[i].w;
        }
    }

    return ret;
}

void solve(int cur, long long cost) {
    static int tp = 0;

    if (cur < k) {
        solve(cur + 1, cost);
    }

    std::merge(
      tree[tp].begin(), tree[tp].end(),
      eg[cur], eg[cur] + n, tmp
    );

    cost += c[cur];

    ans = std::min(ans, kruskal(
      tree[tp].size() + n, tree[tp + 1]
    ) + cost);
    tp++;

    if (cur < k) {
        solve(cur + 1, cost);
    }

    tp--;
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0, u, v, w; i < m; i++) {
        scanf("%d%d%d", &u, &v, &w);

        tmp[i] = {u, v, w};
    }

    for (int i = 1; i <= k; i++) {
        scanf("%d", &c[i]);

        for (int j = 0, w; j < n; j++) {
            scanf("%d", &w);

            eg[i][j] = {n + i, j + 1, w};
        }

        std::sort(eg[i], eg[i] + n);
    }

    std::sort(tmp, tmp + m);

    ans = kruskal(m, tree[0]);

    solve(1, 0);

    printf("%lld\n", ans);

    return 0;
}
