#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define endl '\n'
#define MOD 998244353
#define int long long
using namespace std;
const int MAXN = 5e3 + 5;
int n, ans, sum, maxarr;
bool vis[MAXN], flag;
void dfs(int total, vector<int>& arr, int now) {
    if (total == n) {
        if (flag) {
            ans = (ans + 1) % MOD;
        }
        return;
    }
    int all = 0, maxt = -1, all_num = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            all += arr[i];
            maxt = max(maxt, arr[i]);
            all_num++;
        }
    }
    if (all > 2 * maxt && all_num >= 3) {
        ans = (ans + 1) % MOD;
    }
    for (int i = now + 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = true;
            dfs(total + 1, arr, i);
            vis[i] = false;
        }
    }
}
int jie(int ttt) {
    int res = 1;
    for (int i = 1; i <= ttt; i++) {
        res *= i;
    }
    return res;
}
int c(int x, int y) {
    return (jie(x) / jie(x - y) / jie(y)) % MOD;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    if (n < 3) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> arr(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum += arr[i];
        maxarr = max(maxarr, arr[i]);
    }
    if (maxarr == 1) {
        for (int i = 3; i <= n; i++) {
            ans = (ans + c(n, i)) % MOD;
        }
        cout << ans << endl;
        return 0;
    }
    if (sum > maxarr * 2) {
        flag = true;
    }
    dfs(0, arr, 0);
    cout << ans << endl;
    return 0;
}
