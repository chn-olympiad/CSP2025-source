#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, k, a[500005], sum[500005], las, ans;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = (sum[i - 1] ^ a[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = las; j < i; j++) {
            if (k == (sum[i] ^ sum[j])) {
                ans++;
                las = i;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}
