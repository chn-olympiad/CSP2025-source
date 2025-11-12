#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 2e4 + 5, kMaxM = 2e6 + 5, kMaxK = 25;

int n, m, k, tot, c[kMaxK], a[kMaxK][kMaxN], siz[kMaxN], fa[kMaxN], st;
long long ans = 1e18;

struct Edge {
    int u, v, w;
} e[kMaxM], t[kMaxM];

int Find(int x) {
    return x == fa[x] ? x : fa[x] = Find(fa[x]);
}

void Solve(int s) {
    if ((clock() - st) * 1. / CLOCKS_PER_SEC > 0.93) {
        cout << ans;
        exit(0);
    }
    long long ret = 0;
    int pop = 0;
    tot = m;
    for (int i = 1; i <= m; i++) e[i] = t[i];
    for (int i = 1; i <= k; i++) {
        if (s >> i - 1 & 1) {
            ret += c[i], pop++;
            for (int j = 1; j <= n; j++) {
                e[++tot] = {i + n, j, a[i][j]};
            }
        }
    }
    sort(e + 1, e + 1 + tot, [](Edge i, Edge j) {
        return i.w < j.w;
    });
    for (int i = 1; i <= n + k; i++) {
        fa[i] = i, siz[i] = 1;
    }
    int cnt = 0;
    for (int i = 1, u, v, w; i <= tot; i++) {
        u = Find(e[i].u), v = Find(e[i].v), w = e[i].w;
        if (u != v) {
            if (siz[u] < siz[v]) swap(u, v);
            fa[v] = u, siz[u] += siz[v];
            ret += w, cnt++;
            if (cnt == n + pop - 1) break;
        }
    }
    ans = min(ans, ret);
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    // freopen("road4.in", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    st = clock();
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
        t[i] = e[i];
    }
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    if (k == 0) {
        Solve(0);
    } else if (*max_element(c + 1, c + 1 + k) == 0) {
        Solve((1 << k) - 1);
    } else {
        Solve(0), Solve((1 << k) - 1);
        for (int i = 0; i < k; i++) {
            Solve(1 << i), Solve(((1 << k) - 1) ^ (1 << i));
        }
        for (int i = 0; i < k; i++) {
            for (int j = i + 1; j < k; j++) {
                int s = (1 << i) | (1 << j);
                Solve(s), Solve(((1 << k) - 1) ^ s);
            }
        }
        for (int s = 0; s < 1 << k; s++) {
            int p = __builtin_popcount(s);
            if (p > 2 && k - p > 2) {
                Solve(s);
            }
        }
    }
    cout << ans;
    //  << ' ' << (clock() - st) * 1. / CLOCKS_PER_SEC;
    return 0;
}