#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n, ans = 0, a[5005];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (unsigned long long j = 0; j < (1 << n); j++) {
        int sum = 0, cnt = 0, mxn = -1;
        for (int k = 0; k < n; k++) {
            if (j & (1 << k)) {
                sum += a[k];
                mxn = max(mxn, a[k]);
                cnt++;
            }
        }
        if (cnt >= 3 && sum > mxn * 2)
            ans = (ans + 1) % 998244353;
    }
    cout << ans;
    return 0;
}
