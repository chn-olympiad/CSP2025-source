# include <bits/stdc++.h>
using namespace std;
# define int long long
const int MAXN = 5e2 + 10, PR = 998244353;
int n, m, a[MAXN];
int c[MAXN], f[1 << 18][20], g[MAXN], fac[MAXN], h[MAXN];
signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    string s;
    cin >> s;
    bool flag = 1; 
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        a[i] = s[i - 1] - '0';
    }
    for (int i = 1; i <= n; i++) {
        if (!a[i]) flag = 0;
    }
    if (m == 1) {
        fac[0] = 1;
        g[0] = 1;
        sort(c + 1, c + n + 1);
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            while (cnt < n && c[cnt + 1] <= i - 1) cnt++;
            h[i] = h[i - 1]; 
            if (a[i] == 1) {
                g[i] = 1ll * g[i - 1] * (cnt - h[i - 1]) % PR;
                h[i]++;
            } else g[i] = g[i - 1];
            fac[i] = 1ll * fac[i - 1] * i % PR;
        }
        int ans = 0, pos = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 1) {
            while (pos <= n && c[pos] <= i - 1) pos++;
            ans = (ans + 1ll * g[i - 1] * (n - pos + 1) % PR * fac[n - h[i - 1] - 1]) % PR;
            // cout << ans << endl ;
            }
        }
        cout << ans << endl ;
        return 0;
    } else if (m == n) {
        bool flag = 1;
        for (int i = 1; i <= n; i++) flag &= (c[i] != 0), flag &= (a[i]);
        if (flag) {
            int ans = 1;
            for (int i = 1; i <= n; i++) ans = 1ll * ans * i % PR;
            cout << ans << endl ;
        } else {
            cout << 0 << endl ;
        }
        return 0;
    }
    f[0][0] = 1;
    for (int i = 0; i < (1 << n); i++) {
        int cnt = 0;
        for (int j = 0; j<  n; j++) {
            cnt += ((i >> j) & 1);
        }
        for (int j = 0; j <= cnt; j++) {
        for (int k = 1; k <= n; k++) {
            if (((i >> k - 1) & 1)) continue;
            if (a[cnt + 1] && cnt - j < c[k]) {
                (f[i | (1 << k - 1)][j + 1] += f[i][j]) %= PR;
            } else {
                (f[i | (1 << k - 1)][j] += f[i][j]) %= PR;
            }
        }
            // if (f[i][j]) cout << i << " " << j << " " << f[i][j] << endl ;
        }
    }
    int ans = 0;
    for (int i = m; i <= n; i++) (ans += f[(1 << n) - 1][i]) %= PR;
    cout << ans << endl ;
    return 0;
}