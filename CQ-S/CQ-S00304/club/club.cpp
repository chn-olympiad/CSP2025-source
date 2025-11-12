#include <bits/stdc++.h>

void Freopen() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
}

using namespace std;
const int N = 2e5 + 10, M = 2e5 + 10, inf = 1e9, mod = 998244353;

int n;
int a[3][N];

struct node {
    int val, id, op;
} p[3 * N];

int vis[3 * N];
int dp[210][210][210];

void solve() {
    cin >> n;

    int F = 1;

    for ( int i = 1; i <= n; i ++) {
        cin >> a[0][i] >> a[1][i] >> a[2][i];

        if (a[1][i] != 0 || a[2][i] != 0) F = 0;
    }

    if (F) {
        int ans = 0;

        sort(a[0] + 1, a[0] + n + 1);

        for ( int i = 1; i <= n / 2; i ++) ans += a[0][i];

        cout << ans << '\n';

        return ;
    }

    if (n <= 200) {
        for ( int i = 1; i <= n; i ++)
            for ( int j = 0; j <= n; j ++)
                for ( int k = 0; k <= n; k ++)
                    dp[i][j][k] = 0;

        for ( int i = 1; i <= n; i ++) {
            for ( int a = 0; a <= i; a ++)
                for ( int b = 0; b <= i - a; b ++) {
                    int c = i - a - b;
                    if (a) dp[i][a][b] = max(dp[i][a][b], dp[i - 1][a - 1][b] + :: a[0][i]);
                    if (b) dp[i][a][b] = max(dp[i][a][b], dp[i - 1][a][b - 1] + :: a[1][i]);
                    if (c) dp[i][a][b] = max(dp[i][a][b], dp[i - 1][a][b] + :: a[2][i]);
                }
        }

        int ans = 0;

        for ( int a = 0; a <= n / 2; a ++)
            for ( int b = 0; b <= n / 2; b ++) {
                int c = n - a - b;
                if (c > n / 2) continue ;
                ans = max(ans, dp[n][a][b]);
            }

        cout << ans << '\n';
        return ;  
    }

    int cnt = 0;
    for ( int i = 1; i <= n; i ++) {
        p[++ cnt] = {a[0][i], i, 0};
        p[++ cnt] = {a[1][i], i, 1};
        p[++ cnt] = {a[2][i], i, 2};
    }

    for ( int i = 1; i <= cnt; i ++) vis[i] = 0;

    sort(p + 1, p + cnt + 1, [&]( node a, node b) {
        return a.val > b.val;
    });

    int cs[3] = {0, 0, 0};
    int ans = 0;
    for ( int i = 1; i <= cnt; i ++) {
        if (! vis[p[i].id] && cs[p[i].op] < n / 2) {
            vis[p[i].id] = 1, cs[p[i].op] ++;
            ans += p[i].val;
        }
    }

    cout << ans << '\n';
}

signed main() {
    Freopen();

    ios :: sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while (T --) solve();

    return 0;
}

/*
完了，这个T1这么难吗。

先考虑只有两个部门该怎么做。

那么就是每个都有 $n/2$ 个人。

还是不会做，只有一个 $O(n^2)$ 的 dp 啊。

不会 T1 只有 60 分吧………………
*/