#include<bits/stdc++.h>
using namespace std;

const int N = 505, mod = 998244353;

int n, m, c[N];
string s;
long long fac[N], inv[N];

long long qpow(long long a, int b) {
    if (b == 0) {
        return 1;
    }
    if (b == 1) {
        return a;
    }
    long long ret = qpow(a, b / 2);
    if (b % 2 == 0) {
        return ret * ret % mod;
    }
    return ret * ret % mod * a % mod;
}

void init() {
    fac[0] = 1;
    for (int i = 1; i <= 502; i++) {
        fac[i] = fac[i-1] * i % mod;
    }
    inv[502] = qpow(fac[502], mod - 2);
    for (int i = 501; i >= 0; i--) {
        inv[i] = inv[i+1] * (i + 1) % mod;
    }
}

int main() {
    //freopen("employ.in", "r", stdin);
    //freopen("employ.out", "w", stdout);
    init();
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    cout << inv[n];

    return 0;
}
