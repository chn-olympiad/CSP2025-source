#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 998244353;
const int N = 509;
int n, m, c[N], p[N], fac[N];
string s;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    fac[0] = fac[1] = 1;
    for (int i = 2;i <= 500;i++) fac[i] = fac[i - 1] * i % MOD;
    cin >> n >> m >> s;
    s = " " + s;
    for (int i = 1;i <= n;i++) cin >> c[i];
    if (m == n) {
        int u = 1;
        for (int i = 1;i <= n;i++)
            u &= (s[i] == '1' && c[i] != 0);
        if (u) cout << fac[n];
        else cout << 0;
    } else {
        int sum = 0;
        for (int i = 1;i <= n;i++) p[i] = i;
        do {
            int cnt = 0;
            for (int i = 1;i <= n;i++) {
                if (cnt >= c[p[i]] || s[i] == '0') cnt++;
            }
            if (n - cnt >= m) sum++;
        } while (next_permutation(p + 1, p + 1 + n));
        cout << sum;
    }
    return 0;
}
