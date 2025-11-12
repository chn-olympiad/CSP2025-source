#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <utility>
#include <map>
#define maxm 1000005
#define maxn 11005

struct node {
    int a, b; long long v;
    bool operator <(const node &a) const {
        return v < a.v;
    }
} edge[maxm], vise[maxm];

int f[maxn], n, m, k, tot, p[15];
long long a[15][maxn], ans = LLONG_MAX;
void init() {
    for (int i = 1; i <= n + tot; i++) f[i] = i;
}

int getf(int x) {
    if (f[x] != x) f[x] = getf(f[x]);
    return f[x];
}

void change(int a, int b) {
    a = getf(a), b = getf(b);
    f[a] = b;
}

long long kruskal() {
    init();
    int cnt = n + tot - 1;
    long long ret = 0;
    std::sort(edge + 1, edge + m + 1);
    for (int i = 1; i <= m && cnt > 0; i++) {
        int u = edge[i].a, v = edge[i].b; long long w = edge[i].v;
        if (getf(u) == getf(v)) continue;
        --cnt;
        change(u, v);
        ret += w;
    }
    if (cnt > 0) return LLONG_MAX;
    return ret;
}

std::vector<int> chosen;
void dfs(int pos) {
    if (pos > k) {
        int vism = m;
        for (int i = 1; i <= m; i++) vise[i] = {edge[i].a, edge[i].b, edge[i].v};
        long long sum = 0;
        tot = 0;
        for (int num : chosen) {
            sum += p[num];
            ++tot;
            for (int i = 1; i <= n; i++) edge[++m] = {tot + n, i, a[num][i]};
        }
        long long val = kruskal();
        if (val != LLONG_MAX) ans = std::min(ans, val + sum);
        m = vism;
        for (int i = 1; i <= m; i++) edge[i] = {vise[i].a, vise[i].b, vise[i].v};
        return;
    }
    dfs(pos + 1);
    chosen.push_back(pos);
    dfs(pos + 1);
    chosen.pop_back();
}

std::map<std::pair<int, int>, int> id;
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    std::ios::sync_with_stdio(false); std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        std::cin >> edge[i].a >> edge[i].b >> edge[i].v;
        if (id.count({edge[i].a, edge[i].b})) {
            int pos = id[{edge[i].a, edge[i].b}];
            edge[pos] = std::min(edge[pos], edge[i]);
            --i, --m;
        }
        else id[{edge[i].a, edge[i].b}] = id[{edge[i].b, edge[i].a}] = i;
    }
    for (int i = 1; i <= k; i++) {
        std::cin >> p[i];
        for (int j = 1; j <= n; j++) std::cin >> a[i][j];
        /*if (p[i] == 0) {
            for (int j = 1; j <= n; j++) {
                for (int l = 1; l <= n; l++) {
                    edge[++m] = {j, l, a[i][j] + a[i][l]};
                    if (id.count({j, l})) {
                        int pos = id[{j, l}];
                        edge[pos] = std::min(edge[pos], edge[i]);
                        --m;
                    }
                    else id[{j, l}] = id[{l, j}] = m;
                }
            }
            --i, --k;
        }*/
    }
    dfs(1);
    std::cout << ans;
    return 0;
}
