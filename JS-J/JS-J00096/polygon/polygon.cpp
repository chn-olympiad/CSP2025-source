#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n;
    cin >> n;
    int a[5005];
    for (int i = 0; i < n; ++ i) {
        cin >> a[i];
    }
    int ans = 0;
    for (long long i = 1; i < (1 << n); ++ i) {
        int maxn = 0;
        int sum = 0;
        if (__builtin_popcount(i) >= 3) {
            for (int j = 0; j < n; ++ j) {
                if (i & (1 << j)) {
                    sum += a[j];
                    maxn = max(maxn, a[j]);
                }
            }
        }
        if (sum > 2 * maxn) {
            ans ++;
            ans %= 998244353;
        }
    }
    cout << ans;
    return 0;
}
