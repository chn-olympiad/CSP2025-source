#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
const int N = 5005;
int a[N];
int ans;
const int mod = 998244353;
int c[N][N];
void rest() {
    c[1][1] = 1;
    c[1][0] = 1;
    for (int i = 2; i <= n; i ++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j ++) {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
            c[i][j] %= mod;
        }
    }
}
void dfs(int now, int len, int num) {
    if(num >= 2) {
        int k = lower_bound(a + now + 1, a + n + 1, len) - a - 1;
        ans = (ans + k - now + mod) % mod;
    }
    for (int i = now + 1; i < n; i ++) {
        dfs(i, len + a[i], num + 1);
    }
}
struct node {
    int now, len, num;
};
void bfs() {
    queue <node> q;
    for (int i = 1; i < n - 1; i ++) q.push({i, a[i], 1});
    while (q.size()) {
        node u = q.front();
        q.pop();
        int now = u.now, len = u.len, num = u.num;
        if(num >= 2) {
            int k = lower_bound(a + now + 1, a + n + 1, len) - a - 1;
            ans = (ans + k - now + mod) % mod;
        }
        for (int i = now + 1; i < n; i ++) {
            q.push({i, len + a[i], num + 1});
        }
    }
}
signed main(void) {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    rest();
    int maxn = 0;
    for (int i = 1; i <= n; i ++) cin >> a[i], maxn = max(maxn, a[i]);
    if(maxn == 1) {
        for (int i = 3; i <= n; i ++) {
            ans = (ans + c[n][i]) % mod;
        }
        cout << ans % mod;
        return 0;
    }
    sort(a + 1, a + n + 1);
    bfs();
    cout << ans % mod;
    return 0;
}
