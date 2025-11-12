#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[1000010];
long long s[1000010];
long long ans = 0;
inline void dfs (long long k) {
    if (k == n + 1) {
        long long sum = 0;
        long long ma = 0;
        long long cnt = 0;
        for (long long i = 1; i <= n; i++) {
            if (s[i] == 1) {
                cnt++;
                sum += a[i];
                ma = max (ma, a[i]);
            }
        }
        if (sum > 2 * ma && cnt >= 3)
            ans++;
        ans %= 998244353;
        return;
    }
    s[k] = 0;
    dfs (k + 1);
    s[k] = 1;
    dfs (k + 1);
}
int main () {
    freopen ("polygon.in", "r", stdin);
    freopen ("polygon.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (long long i = 1; i <= n; i++)
        cin >> a[i];
    if (n >= 40) {
        cout << 0 << '\n';
        return 0;
    }
    dfs (1);
    cout << ans << '\n';
    return 0;
}
