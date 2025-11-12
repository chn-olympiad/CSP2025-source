#include <bits/stdc++.h>

#define fin(s) freopen(s".in", "r", stdin)
#define fout(s) freopen(s".out", "w", stdout)

using i64 = long long;
using namespace std;

template<typename T>
void read(T &x) {
    char ch = getchar();
    x = 0;
    T f = 1;

    while (!isdigit(ch)) {
        f -= (ch == '-') << 1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = (x << 1) + (x << 3) + (ch & 15);
        ch = getchar();
    }

    x *= f;
}
template<typename T, typename ...L>
void read(T &x, L &...y) {
    read(x);
    read(y...);
}

constexpr int N = 1E4 + 25, K = 11, M = 1E6 + 5;

int n, m, k, c[K];

vector<array<int, 3>> e, h, b;
int fa[N];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) {
        fa[x] = y;
    }
}

int main() {
    fin("road");
    fout("road");

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        e.push_back({u, v, w});
    }

    sort(e.begin(), e.end(), [&](auto x, auto y) {
        return x[2] < y[2];
    });

    iota(fa + 1, fa + 1 + n, 1);

    for (auto _ : e) {
        auto u = _[0], v = _[1], w = _[2];
        if (find(u) != find(v)) {
            h.push_back({u, v, w});
            merge(u, v);
        }
    }

    for (int i = 1; i <= k; ++i) {
        cin >> c[i];
        for (int j = 1; j <= n; ++j) {
            int x;
            cin >> x;
            h.push_back({n + i, j, x});
        }
    }

    sort(h.begin(), h.end(), [&](auto x, auto y) {
        return x[2] < y[2];
    });
    while (h.back()[0] > n) {
        h.pop_back();
    }

    i64 ans = LLONG_MAX;

    for (int S = 0; S < (1 << k); ++S) {
        iota(fa + 1, fa + 1 + n + k, 1);
        i64 sum = 0;
        for (int i = 0; i < k; ++i) if (S >> i & 1) {
            sum += c[i + 1];
        }
        for (auto _ : h) {
            auto u = _[0], v = _[1], w = _[2];
            if (u <= n || S >> (u - n - 1) & 1) {
                if (find(u) != find(v)) {
                    merge(u, v);
                    sum += w;
                }
            }
        }
        ans = min(ans, sum);
    }

    cout << ans << "\n";

    return 0;
}