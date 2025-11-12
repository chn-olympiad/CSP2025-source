#include <bits/stdc++.h>
using namespace std;

int fa[10015];

// struct node {
//     int a, b, c;
//     bool operator < (const node &oth) const {
//         return a == oth.a ? (b == oth.b ? c >= oth.c : b >= oth.b) : a >= oth.a;
//     }
// };

vector<tuple<int, int, int>> edge;

int find(int x) {
    return fa[x] == x ? x : x = fa[x];
}

void merge(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) {
        fa[x] = fy;
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    int n, m, k, ans = 0;
    cin >> n >> m >> k;

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edge.push_back({w, u, v});
    }

    for (int i = m; i < m + k; ++i) {
        int c;
        cin >> c;
        vector<int> a(n + 1);
        for (int j = 1; j <= n; ++j) {
            cin >> a[j];
        }
    }

    for (int i = 1; i <= n + k; ++i) {
        fa[i] = i;
    }

    sort(edge.begin(), edge.end());

    int flag = 0;

    for (auto [w, u, v] : edge) {

        cout << u << ' ' << v << ' ' << w << '\n';
        if (find(u) != find(v)) {
            merge(u, v);
            ans += w;
            if (++flag == n - 1) {
                break;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
