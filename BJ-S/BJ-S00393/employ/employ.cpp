#include <iostream>
#include <cstdio>
using namespace std;

const int N = 505;
const int P = 998244353;
int n, m, c[N], sum[N];
string s;
bool vis[N];

namespace sit1{
    int ans;

    void dfs(int x, int cnt) {
        if (cnt + sum[n] - sum[x - 1] < m)
            return;
        if (x > n) {
            if (cnt >= m)
                ans = (ans + 1) % P;
            return;
        }
        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) {
                vis[i] = 1;
                dfs(x + 1, cnt + (x - cnt <= c[i] && s[x] == '1'));
                vis[i] = 0;
            }
        }
    }

    void solve() {
        dfs(1, 0);
        cout << ans << '\n';
    }
}

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> s;
    s = ' ' + s;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
        sum[i] = sum[i - 1] + (s[i] == '1');
    }
    if (n <= 18)
        sit1::solve();
    return 0;
}