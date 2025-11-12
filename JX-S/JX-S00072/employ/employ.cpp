#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 20;
const int mod = 998244353;
int n, m;
string s;
int c[N];
bool vis[N];
int ans = 0;
void dfs(int step, int now) {
    if (step == n) {
        if (now > n - m) {
            return ;
        }
        ans++;
        ans %= mod;
        return ;
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        if (s[step + 1] == '0') {
            dfs(step + 1, now + 1);
        }
        else {
            if (c[i] <= now) {
                dfs(step + 1, now + 1);
            }
            else dfs(step + 1, now);
        }
        vis[i] = 0;
    }
    return ;
}
signed main() {
    cin >> n >> m;
    cin >> s;
    s = " " + s;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; i++) {
        vis[i] = 1;
        if (s[1] == '0') {
            dfs(1, 1);
        }
        else {
            if (!c[i]) {
                dfs(1, 1);
            }
            else {
                dfs(1, 0);
            }
        }
        vis[i] = 0;
    }
    cout << ans << '\n';
    return 0;
}
