#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>

const int N = 1e5 + 5, PN = 205;
int T, n, a[N][3], f[PN][PN / 2][PN / 2];
int backup[N];

void solve1 () {
    memset (f, 0, sizeof(f));
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= n / 2 && j <= i; ++j) {
            for (int k = max(0ll, i - j - n / 2); k <= n / 2 && k <= i - j; ++k) {
                int p = i - j - k;
                if (p > n / 2) continue ;
                if (j > 0) f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][k] + a[i][0]);
                if (k > 0) f[i][j][k] = max(f[i][j][k], f[i - 1][j][k - 1] + a[i][1]);
                if (p > 0) f[i][j][k] = max(f[i][j][k], f[i - 1][j][k] + a[i][2]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= n / 2; ++i)
        for (int j = 0; j <= n / 2; ++j)
            if (n - i - j <= n / 2) ans = max(ans, f[n][i][j]);
    printf ("%lld\n", ans);
}

void solve2 () {
    for (int i = 1; i <= n; ++i)
        backup[i] = a[i][0];
    sort (backup + 1, backup + n + 1, greater<int>());
    int ans = 0;
    for (int i = 1; i <= n / 2; ++i)
        ans += backup[i];
    printf ("%lld\n", ans);
}

void solve3 () {
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += max(max(a[i][0], a[i][1]), a[i][2]);
    printf ("%lld\n", ans);
}

void solve4 () {
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += a[i][0];
    priority_queue <int, vector <int>, greater <int> > q;
    for (int i = 1; i <= n; ++i) {
        if (q.size() < n / 2) {
            int val = a[i][1] - a[i][0];
            ans = ans + val;
            q.push(val);
        } else {
            int val = a[i][1] - a[i][0];
            int p = q.top();
            if (p < val) {
                ans = ans - p + val;
                q.pop();
                q.push(val);
            }
        }
    }
    printf ("%lld\n", ans);
}

signed main () {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf ("%lld", &T);
    while (T --) {
        scanf ("%lld", &n);
        bool flag1 = 1, flag2 = 1;
        for (int i = 1; i <= n; ++i)
            scanf ("%lld %lld %lld", &a[i][0], &a[i][1], &a[i][2]),
            flag1 &= (a[i][1] == 0 && a[i][2] == 0),
            flag2 &= (a[i][2] == 0);
        if (n <= 200) solve1();
        else if (flag1) solve2();
        else if (flag2) solve4();
        else solve3();
    }
    return 0;
}
