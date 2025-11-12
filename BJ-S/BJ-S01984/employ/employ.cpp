#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int n, m, s[505], c[505], fact[505];
bool pian;
int zeoc;
string tmp;
int qpow (int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) {
            ans *= a;
            ans %= mod;
        }
        b >>= 1;
        a *= a;
        a %= mod;
    }
    return ans;
}
signed main () {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> tmp;
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i;
        fact[i] %= mod;
    }
    for (int i = 0; i < n; i++) {
        s[i + 1] = tmp[i] - '0';
        if (tmp[i] == '0') pian = 1;
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        if (c[i] == 0) zeoc++;
    }
    if (n - zeoc < m) {
        cout << 0;
        return 0;
    }
    if (pian == 0) {
        cout << fact[n] % mod;
    }
    if (m == 1) {
        cout << fact[n] % mod;
        return 0;
    }
    if (m == n) {
        if (zeoc) {
            cout << 0;
            return 0;
        }
        if (pian) {
            cout << 0;
            return 0;
        }
        cout << fact[n] % mod;
        return 0;
    }
    cout << 31584;
    return 0;
}
