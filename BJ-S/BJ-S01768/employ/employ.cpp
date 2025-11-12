#include <bits/stdc++.h>
using namespace std;
const int N = 505, mod = 998244353;
int n, m, s[N], c[N], fac[N], a[N];
string S;
void stk1() {
    int cnt = 0;
    for (int i = 1; i <= n; i++) cnt += s[i];
    bool flag = true;
    for (int i = 1; i <= n; i++) if (c[i] == 0) {flag = false; break;}
    if (cnt == n && flag) cout << fac[n] << '\n';
    else cout << "0\n";
}
void stk2() {
    for (int i = 1; i <= n; i++) a[i] = i;
    int ans = 0;
    do {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == 0) {
                cnt++;
                continue;
            }
            if (cnt >= c[a[i]]) {
                cnt++;
                continue;
            }
        }
        if (cnt <= n - m) {
            ans++;
            // cout << cnt << '\n';
            // for (int i = 1; i <= n; i++) cout << a[i] << ' '; cout << '\n';
        }
    } while (next_permutation(a + 1, a + n + 1));
    cout << ans << '\n';
}
int main() {
freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> S;
    for (int i = 1; i <= n; i++) cin >> c[i];
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
    bool flaga = true; int tmp = 0;
    for (int i = 1; i <= n; i++) {
        s[i] = S[i - 1] - '0';
        tmp += s[i];
    } 
    // for (int i = 1; i <= n; i++) cout << s[i] << '\n';
    if (m == n) stk1();
    else stk2();
    return 0;
}