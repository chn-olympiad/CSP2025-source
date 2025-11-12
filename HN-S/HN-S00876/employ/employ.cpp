#include <bits/stdc++.h>
#define int long long
#define Pii pair<int, int>
#define Sc second
#define Fr first
#define ls(x) x << 1
#define rs(x) x << | 1

using namespace std;

const int kMaxN = 1e6 + 5, Mod = 998244353;

int f[kMaxN], a[kMaxN], n, m, cnt, ans;
bool b[kMaxN], vis[kMaxN];

void dfs(int x) {
    if (x == n + 1) {
        int t = 0;
        for (int i = 1; i <= n; i++) {
            if (b[i] == 0 || a[f[i]] <= t) t++;
        }
        if (n - t >= m) ans++;
        return;
    }
    for (int i = 1; i <= n; i++) if (!vis[i]) {
        vis[i] = 1;
        f[x] = i;
        dfs(x + 1);
        vis[i] = 0;
    }
}

signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios:: sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        char x; cin >> x;
        b[i] = x - '0';
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dfs(1);
    cout << ans % Mod << '\n';
    return 0;
}