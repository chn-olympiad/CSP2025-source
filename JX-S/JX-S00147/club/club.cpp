#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, ans;
int a[N], b[N], c[N];
void dfs (int i, int sum_a, int sum_b, int sum_c, int sum) {
    if (i == n + 1) {
        ans = max (ans, sum);
        return;
    }
    if (sum_a + 1 <= n / 2) {
        dfs (i + 1, sum_a + 1, sum_b, sum_c, sum + a[i]);
    }
    if (sum_b + 1 <= n / 2) {
        dfs (i + 1, sum_a, sum_b + 1, sum_c, sum + b[i]);
    }
    if (sum_c + 1 <= n / 2) {
        dfs (i + 1, sum_a, sum_b, sum_c + 1, sum + c[i]);
    }
}
int main () {
    freopen ("club.in", "r", stdin);
    freopen ("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie (0), cout.tie (0);
    int T; cin >> T;
    while (T--) {
        ans = INT_MIN;
        cin >> n;
        bool f2 = true, f3 = true;
        for (int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i] >> c[i];
            if (b[i] != 0) f2 = false;
            if (c[i] != 0) f3 = false;
        }
        if (f2 && f3) {
            sort (a + 1, a + 1 + n);
            int x = 0;
            for (int i = n; i >= 1; i--) {
                ++ x;
                if (x > n / 2) break;
                ans += a[i];
            }
            continue;
        }
        dfs (1, 0, 0, 0, 0);
        cout << ans << "\n";
    }
    return 0;
}
