#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e4 + 10, M = 1e6 + 10, K = 30;
struct node {
    int u, v, w;
} a[M * K];
int c[K];
int fa[N + K];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    fa[y] = x;
}

bool check(int n) {
    int lst = find(1);
    bool ans = true;
    for (int i = 2; i <= n; i++)
        if (lst != find(i)) {
            ans = false;
            break;
        } else lst = find(i);
    return ans;
}

signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) cin >> a[i].u >> a[i].v >> a[i].w;

    for (int i = 1; i <= k; i++) {
        cin >> c[i];

        for (int j = 1; j <= n; j++) {
            cin >> a[i + m].w;
            a[i + m].u = i + n;
            a[i + m].v = j;
        }
    }

    for (int i = 1; i <= n + k; i++) fa[i] = i;

    sort(a + 1, a + m + k * n + 1, [ & ](const node& x, const node& y) {
        return x.w < y.w;
    });

    int ans = 0;
    for (int i = 1; i <= m + k * n; i++) {
        int x = find(a[i].u), y = find(a[i].v);
        if (x != y) {
            fa[y] = x;
            ans += a[i].w;
        }

        if (check(n)) break;
    }
    cout << ans;

    return 0;
}
