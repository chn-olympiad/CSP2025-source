#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FILEIO "road"
const ll N = 1e5 + 10, K = 15;

ll n, m, k;
ll fa[N];
ll C[K];
ll A[K][N];

ll find(ll u) {
    return fa[u] == u ? u : fa[u] = find(fa[u]);
}

bool merge(ll u, ll v) {
    u = find(u), v = find(v);
    if (u != v) {
        fa[u] = v;
        return 1;
    }
    return 0;
}

using nd = tuple<ll, ll, ll>;

void k0() {
    vector<nd> e;
    for (ll i = 1, u, v, w; i <= m; ++i) {
        cin >> u >> v >> w;
        e.emplace_back(w, u, v);
    }
    for (ll i = 1; i <= n; ++i) fa[i] = i;
    sort(e.begin(), e.end());
    ll cnt = 0, k0ans = 0;
    for (auto [w, u, v] : e) {
        if (merge(u, v)) cnt++, k0ans += w;
        if (cnt == n - 1) break;
    }
    if (cnt >= n - 1) cout << k0ans << "\n";
}

bool vis[K];
vector<nd> E;

ll work() {
    vector<nd> e = E;
    ll wans = 0, cnt = n - 1;
    for (ll i = 1; i <= k; ++i) {
        if (vis[i]) {
            wans += C[i];
            cnt++;
            for (ll j = 1; j <= n; ++j) {
                e.emplace_back(A[i][j], i + n, j);
            }
        }
    }
    for (ll i = 1; i <= cnt + 10; ++i) fa[i] = i;
    sort(e.begin(), e.end());
    for (auto [w, u, v] : e) {
        if (merge(u, v)) cnt--, wans += w;
        if (cnt == 0) break;
    }
    if (cnt == 0) {
        return wans;
    }
}

ll finala = 1e18;

void dfs(ll pos, ll lst, ll lmt) {
    if (pos == lmt + 1) {
        finala = min(finala, work());
        return;
    }
    for (ll i = lst + 1; i <= k; ++i) {
        if (C[i] == 0) continue;
        vis[i] = 1;
        dfs(pos + 1, i + 1, lmt);
        vis[i] = 0;
    }
}

void specialA() {
    ll wans = 0, cnt = n - 1;
    cnt += k;
    // for (ll i = 1; i <= k; ++i) {
    //     cnt++;
    //     for (ll j = 1; j <= n; ++j) {
    //         E.emplace_back(A[i][j], i + n, j);
    //     }
    // }
    for (ll i = 1; i <= cnt + 10; ++i) fa[i] = i;
    sort(E.begin(), E.end());
    for (auto [w, u, v] : E) {
        if (merge(u, v)) cnt--, wans += w;
        if (cnt == 0) break;
    }
    if (cnt == 0) cout << wans << "\n";
}

signed main() {
    #ifdef FILEIO
        freopen(FILEIO ".in", "r", stdin);
        freopen(FILEIO ".out", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m >> k;
    if (k == 0) { k0(); return 0; }
    for (ll i = 1, u, v, w; i <= m; ++i) {
        cin >> u >> v >> w;
        E.emplace_back(w, u, v);
    }
    bool call0 = 1;
    ll upl = 0;
    for (ll i = 1; i <= k; ++i) {
        cin >> C[i];
        if (C[i] != 0) call0 = 0, upl++;
        for (ll j = 1; j <= n; ++j) {
            cin >> A[i][j];
            if (C[i] == 0) E.emplace_back(A[i][j], i + n, j);
        }
    }
    if (call0) {
        specialA();
        return 0;
    }
    for (ll i = 0; i <= upl; ++i) {
        dfs(1, 0, i);
    }
    cout << finala << "\n";
}