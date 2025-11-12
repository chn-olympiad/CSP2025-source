#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 2e4 + 5, kMaxM = 2e6 + 5, kMaxK = 25;

int n, m, k, tot, c[kMaxK], a[kMaxK][kMaxN], siz[kMaxN], fa[kMaxN];
long long ans = 1e18;

struct Edge {
    int u, v, w;
} e[kMaxM], t[kMaxM], tt[kMaxM];

int Find(int x) {
    return x == fa[x] ? x : fa[x] = Find(fa[x]);
}

void Solve(int s) {
    long long ret = 0;
    int pop = 0;
    tot = m;
    for (int i = 1; i <= m; i++) e[i] = tt[i];
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
    // freopen("road.in", "r", stdin);
    // freopen("road.out", "w", stdout);
    freopen("road4.in", "r", stdin);
    // freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
        tt[i] = e[i];
    }
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    sort(e + 1, e + 1 + m, [](Edge i, Edge j) {
        return i.w < j.w;
    });
    for (int i = 1; i <= n; i++) {
        fa[i] = i, siz[i] = 1;
    }
    int cnt = 0;
    for (int i = 1, u, v, w; i <= m; i++) {
        u = Find(e[i].u), v = Find(e[i].v), w = e[i].w;
        if (u != v) {
            if (siz[u] < siz[v]) swap(u, v);
            fa[v] = u, siz[u] += siz[v];
            t[++tot] = e[i];
        } else if (cnt <= n * k) {
            t[++tot] = e[i], cnt++;
        }
    }
    swap(tot, m), swap(e, t);
    // ans = min(ans, ret);
    // cerr << 1LL * minn  << '\n';
    // Solve(0);
    if (*min_element(c + 1, c + 1 + k) == 0) {
        Solve((1 << k) - 1);
    } else {
        for (int s = 0; s < 1 << k; s++) {
            Solve(s);
        }
    }
    cout << ans;
    return 0;
}