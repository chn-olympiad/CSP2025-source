 #include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
ll n, a[5005], ans, tmp = 1;
void dfs(ll dep, ll sum = 0, ll ma = 0, ll t = 0) {
    if (dep == n + 1) {
        if (sum > 2 * ma && t >= 3)ans = (ans + 1)%mod;
        return;
    }
    dfs(dep + 1, sum + a[dep], max(a[dep], ma), t + 1);
    dfs(dep + 1, sum, ma, t);
}
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    bool flag = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] != 1)flag = 0;
    }
    if (flag == 1) {
        for (int i = 1; i <= n; i++) {
            tmp = tmp * 2 % mod;
        }
        tmp -= n + n * (n - 1) / 2 + 1;
        tmp %= mod;
        cout << tmp;
        return 0;
    }
    dfs(1);
    cout << ans;
    return 0;
}
