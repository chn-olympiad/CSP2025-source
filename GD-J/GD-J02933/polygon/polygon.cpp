#include <bits/stdc++.h>

#define fst first
#define snd second

const long long IMX = 1ll << 30;
const long long LMX = 1ll << 60;

const long long MOD1 = 998244353;
const long long MOD2 = 1000000007;
const long long MOD3 = 1000000009;

using ll = long long;
using ld = long double;
using namespace std;
const int N = 5005, MOD = MOD1;
ll n, ans;
ll a[N], C[N][N], res[N];
void dfs(int cur) {
    if (cur > n) {
        ll maxn = 0, sum = 0;
        for (int i = 1; i <= n; i++) { if (res[i]) sum += a[i], maxn = max(maxn, a[i]); }
        if (sum > 2 * maxn) ans++;
        return ;
    }
    res[cur] = 1; dfs(cur + 1);
    res[cur] = 0; dfs(cur + 1);
}
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n <= 20) dfs(1);
    else {
        C[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            C[i][0] = 1;
            for (int j = 1; j <= i; j++) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
        }
        for (int i = 3; i <= n; i++) ans = (ans + C[n][i]) % MOD;
    }
    cout << ans;
    return 0;
}