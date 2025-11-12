#include "bits/stdc++.h"
#define int long long
using namespace std;

const int N = 5 * 1e5 + 10;
int n, k, a[N], f[N], dp[N], ans, ma[N];

inline int read() {
    int fa = 1, x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') fa = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * fa;
}

signed main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    n = read(), k = read();
    for (int i = 1; i <= n; i ++) {
        a[i] = read();
    }
    for (int i = 1; i <= n; i ++) {
        f[i] = f[i - 1] ^ a[i];
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = i; j >= 1; j --) {
            if ((f[i] ^ f[j - 1]) == k){
                dp[i]= max(dp[i], dp[j - 1] + 1);
            }
        }
        dp[i] = max(dp[i - 1], dp[i]);
    }
    printf("%lld", dp[n]);
}
