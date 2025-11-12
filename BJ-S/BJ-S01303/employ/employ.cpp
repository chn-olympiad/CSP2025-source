#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;

long long n, m, c[510], p[510], l[510], ans;
string op;
bool f[510];

void solve() {
    for (int i = 1; i <= n; i++) {
        l[i] = c[p[i]];
    }
    long long cnty = 0, cntn = 0;
    for (int i = 1; i <= n; i++) {
        if (op[i] == '0') {
            cntn++;
        }
        else {
            if (cntn >= l[i]) {
                cntn++;
            }
            else {
                cnty++;
            }
        }
    }
    if (cnty >= m) {
        ans++;
        ans %= mod;
    }
}

void dfs(int x) {
    if (x > n) {
        solve();
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (f[i]) continue;
        p[x] = i;
        f[i] = true;
        dfs(x + 1);
        f[i] = false;
    }
}

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> op;
    op = " " + op;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}
