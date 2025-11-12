#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
const int N = 1e3 + 10;
int n, m;
string s;
int c[N];
bool vis[N];
int ans;

void dfs(int x, int qr, int lq) {
    if (x >= n) {
        if (lq >= m) (ans += 1) %= mod;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;

        if (qr >= c[i]) {
            vis[i] = true;
            dfs(x + 1, qr + 1, lq);
            vis[i] = false;

            continue;
        }

        vis[i] = true;
        if (s[x] == '0') dfs(x + 1, qr + 1, lq);
        else dfs(x + 1, qr, lq + 1);
        vis[i] = false;
    }
}

signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++) cin >> c[i];

    if (m == n) {
        if (s != string(n, '1')) cout << 0;
        else {
            int ans = 1;
            for (int i = 1; i <= n; i++) (ans *= i) %= mod;
            cout << ans % mod;
        }

        return 0;
    }

    dfs(0, 0, 0);
    cout << ans;

    return 0;
}
