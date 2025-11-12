#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5000, Mod = 998244353;
int n, ans;
int a[N + 10];
priority_queue<int, vector<int>, greater<int> > q;
/*
void dfs(int dep) {
    if (dep == n + 1) return ;

}
*/
signed main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    int maxn = -1;
    bool f = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        maxn = max(maxn, a[i]);
        if (a[i] != 1) f = 1;
    }
    if (!f) {
        int nown = 1;
        int num = 1;
        for (int i = 3; i <= n; i ++) {
            nown = num = 1;
            for (int j = 1; j <= i; j ++) {
                nown *= j;
                nown %= Mod;
                num *= (n - j + 1);
                num %= Mod;
            }
            ans += num / nown;
            ans %= Mod;
        }
        cout << ans << endl;
        return 0;
    }
    if (n == 3) {
        if (a[1] + a[2] + a[3] > 2 * maxn) cout << 1;
        else cout << 0;
        return 0;
    }
 //   dfs(3);
    return 0;
}
