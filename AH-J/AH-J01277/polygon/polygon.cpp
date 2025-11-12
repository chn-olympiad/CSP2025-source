#include <bits/stdc++.h>
using namespace std;
int n;
int l[5005];
const int MOD = 998244353;
int cs[5005], cnt, sum;
long long ans = 0;
void dfs (int i) {
    if (i > n) {
        return;
    }
    cs[++cnt] = l[i];
    sum += l[i];
    if (cnt >= 3) {
        if (sum > cs[cnt] * 2) {
            ans++;
            ans %= MOD;
        }
    }
    dfs(i + 1);
    cnt--;
    sum -= l[i];
    dfs(i + 1);
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen ("polygon.in", "r", stdin);
    freopen ("polygon.out", "w", stdout);
    cin >> n;
    bool all1 = true;
    for (int i = 1; i <= n; i++) {
        cin >> l[i];
        if (l[i] != 1) {
            all1 = false;
        }
    }
    if (all1) {
        ans = 1;
        for (int i = 1; i <= n; i++) {
            ans <<= 1;
            ans %= MOD;
        }
        ans--;//all 0
        ans -= n;//one 1
        ans -= 1LL * n * (n - 1) / 2;
        ans = ans % MOD;
        cout << ans;
        return 0;
    }
    sort (l + 1, l + 1 + n);
    dfs (1);
    cout << ans;
    return 0;
}
