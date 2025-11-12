#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2.5e6 + 5;

int n, k;

int a[N], f[N], now_idx[N];

signed main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    scanf("%lld%lld", &n, &k);

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        a[i] ^= a[i - 1];
    }

    for (int i = 1; i <= n; i++) {
        f[i] = max(f[i - 1], (now_idx[a[i] ^ k] || !(a[i] ^ k) ? f[now_idx[a[i] ^ k]] + 1 : 0));
        now_idx[a[i]] = i;
    }

    printf("%lld\n", f[n]);

    fclose(stdin);
    fclose(stdout);
    return 0;
}