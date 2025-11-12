#include <iostream>
#include <cstdio>
#include <queue>

constexpr int MAXN = 1e4 + 10;
constexpr int MAXM = 1e6 + 10;
constexpr int MAXK = 10 + 10;

int n, m, k;
int u[MAXM];
int v[MAXM];
int w[MAXM];
int c[MAXK];
int a[MAXK][MAXN];
int fa[MAXM];

int solve1();
int solve2();
void fa_init();
int fa_merge(int x, int y);
int fa_find(int x);
bool fa_connected(int x, int y);

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        std::cin >> u[i] >> v[i] >> w[i];
    }
    for (int i = 1; i <= k; i++) {
        std::cin >> c[i];
        for (int j = 1; j <= n; j++) {
            std::cin >> a[i][j];
        }
    }

    if (k == 0) {
        int ans = solve1();
        std::cout << ans << '\n';
    } else {
        int ans = solve2();
        std::cout << ans << '\n';
    }

    return 0;
}

int solve2() {
    return 0;
}

int solve1() {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> edge_queue;
    for (int i = 1; i <= m; i++) {
        edge_queue.push(std::make_pair(w[i], i));
    }
    fa_init();
    int ans = 0;
    int cnt = 0;
    while (cnt < n - 1 && !edge_queue.empty()) {
        auto top = edge_queue.top();
        edge_queue.pop();
        int weight = top.first;
        int id = top.second;
        int from = u[id];
        int to = v[id];
        if (!fa_connected(from, to)) {
            fa_merge(from, to);
            ans += weight;
            cnt++;
        }
    }
    return ans;
}

void fa_init() {
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
}

int fa_merge(int x, int y) {
    int rx = fa_find(x);
    int ry = fa_find(y);
    fa[rx] = ry;
}

int fa_find(int x) {
    if (fa[x] == x) {
        return x;
    }
    return fa[x] = fa_find(fa[x]);
}

bool fa_connected(int x, int y) {
    return fa_find(x) == fa_find(y);
}
