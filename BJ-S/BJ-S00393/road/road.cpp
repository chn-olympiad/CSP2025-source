#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1e4 + 5;
const int M = 1e6 + 5;
const int K = 15;
int n, m, k, c[K], a[K][N];
struct Edge{
    int u, v, w;
    bool operator<(const Edge& other) const{
        return w < other.w;
    }
} e[M];

namespace sit1{
    int f[N];

    int find(int x) {
        if (x == f[x]) return x;
        return f[x] = find(f[x]);
    }

    void merge(int x, int y) {
        f[find(x)] = find(y);
    }

    void solve() {
        for (int i = 1; i <= n; ++i)
            f[i] = i;
        sort(e + 1, e + m + 1);
        int ans = 0, cnt = 0;
        for (int i = 1; i <= m; ++i) {
            if (find(e[i].u) != find(e[i].v)) {
                merge(e[i].u, e[i].v);
                ++cnt;
                ans += e[i].w;
            }
            if (cnt == n - 1) {
                cout << ans << '\n';
                return;
            }
        }
        cout << "-1\n";
    }
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i)
        cin >> e[i].u >> e[i].v >> e[i].w;
    for (int i = 1; i <= k; ++i) {
        cin >> c[i];
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
    }
    if (k == 0)
        sit1::solve();
    return 0;
}