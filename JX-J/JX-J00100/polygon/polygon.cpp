#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e3 + 5;
const int mod = 998244353;
int sum[N];
int n;
int a[N];
int s[N];
int modpow(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = ans * x % mod;
        y = y >> 1;
        x = x * x % mod;
    }
    return ans;
}
signed main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            sum[a[j]]++;
            sum[a[j]] %= mod;
        }
        for (int j = 0; j <= a[i]; j++) {
            ans = (ans + sum[j]) % mod;
        }
        for (int j = a[n] - a[i]; j >= 0; j--) {
            sum[j + a[i]] = (sum[j + a[i]] + sum[j]) % mod;
        }
        for (int j = 1; j < i; j++) {
            sum[a[j]] = (sum[a[j]] - 1 + mod) % mod;
        }
    }
    cout << ((modpow(2, n) - (1 + n) + mod) % mod - ans + mod) % mod << "\n";
    return 0;
}
