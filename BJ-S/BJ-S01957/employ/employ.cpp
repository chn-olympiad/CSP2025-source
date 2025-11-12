#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 500 + 10;
const int mod = 998244353;
int n, m, ans, a[maxn], p[maxn];
char s[maxn];
bool vis[maxn];
void dfs(int k) {
    if (k > n) {
        int cnt = 0;
        for (int i = 1, cur = 0; i <= n; i++)
            if (cur < a[p[i]] && s[i] == '1') ++cnt;
            else ++cur;
        if (cnt >= m) ++ans;
        return;
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i]) vis[i] = true, p[k] = i, dfs(k + 1), vis[i] = false;
}
int main() {
    ios::sync_with_stdio(false);
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> s + 1;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (count(a + 1, a + n + 1, 0) >= n - m) {cout << "0\n"; return 0;}
    dfs(1); cout << ans << '\n';
    return 0;
}