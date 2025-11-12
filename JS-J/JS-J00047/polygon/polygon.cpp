#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;
const int MAXN = 5005;
int a[MAXN];
signed main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n; cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int m = 0; m <= (1 << n); ++m) {
        int sum = 0, cnt = 0, maxn = -1e9;
        bitset<MAXN> bs = bitset<MAXN>(m);
        if (bs.count() >= 3) {
            int sum = 0, maxn = -1e9;
            for (int i = 0; i < n; ++i) {
                if (bs[i]) {
                    sum += a[i + 1], maxn = max(maxn, a[i + 1]);
                }
            }
            if ((unsigned long long)sum > (unsigned long long)maxn * 2ull) {
                ++ans;
            }
        }
    }
    cout << (ans % MOD) << endl;
    return 0;
}