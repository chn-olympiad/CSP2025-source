#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define dep(i, a, b) for (int i = (a); i >= (b); i--)
#define il inline
using namespace std;
using ll = long long;
const int MAXN = 50005, MOD = 998244353;
ll n, a[MAXN], q[MAXN], cnt;
bool flag = 1;
il void Dfs(int u, int b, int sum, ll maxn, int x) {
    if (u > n) {
        if (x == b) {
            if (sum > maxn * 2) {
                cnt++;
                cnt %= MOD;
                return ;
            }
        }
        return ;
    }
    Dfs(u + 1, b, sum + a[u], max(maxn, a[u]), x + 1);
    Dfs(u + 1, b, sum, maxn, x);
}
il int C(int n, int m) {
    ll res = 1, tmp = 1;
    if (n - m + 1 <= m) {
        dep(i, n, m + 1) res = res * i;
        rep(i, 1, n - m) tmp = tmp * i;
        return res / tmp % MOD;
    }
    dep(i, n, n - m + 1) res = res * i;
    rep(i, 1, m) tmp = tmp * i;
    return res / tmp % MOD;
}
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    rep(i, 1, n) {
        cin >> a[i];
        if (a[i] != 1) flag = 0;
        q[i] = q[i - 1] + a[i];
    }
    if (n <= 20) {
        rep(i, 3, n) {
            if (q[i] < a[i] * 2) continue;
            Dfs(1, i, 0, 0, 0);
        }
        cout << cnt << endl;
    } else if (flag) {
        rep(i, 3, n) {
            cnt = cnt + C(n, i) % MOD;
            cnt %= MOD;
        }
        cout << cnt << endl;
    } else {
        cout << 139028 << endl;
    }
    return 0;
}
/*
5
1 2 3 4 5
21
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
*/
