#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int NR = 1e5 + 5;

int n, a[NR][4];
int v[NR], dp[205][105][105];

void solve23() {
    for (int i = 1; i <= n; i++)
        v[i] = a[i][1];
    sort(v + 1, v + 1 + n, greater<int>());

    int ans = 0;
    for (int i = 1; i <= n / 2; i++)
        ans += v[i];
    printf("%d\n", ans);
}

void solve3() {
    printf("%d\n", 0);
}

void solve() {
    int n2;
    n2 = n / 2;

    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        for (int c1 = 0; c1 <= min(n2, i); c1++) {
            for (int c2 = 0; c2 <= min(n2, i); c2++) {
                if (c1 != 0) dp[i][c1][c2] = max(dp[i][c1][c2], dp[i - 1][c1 - 1][c2] + a[i][1]);
                if (c2 != 0) dp[i][c1][c2] = max(dp[i][c1][c2], dp[i - 1][c1][c2 - 1] + a[i][2]);
                if (i - c1 - c2 != 0 && i - c1 - c2 <= n2)
                    dp[i][c1][c2] = max(dp[i][c1][c2], dp[i - 1][c1][c2] + a[i][3]);
            }
        }
    }

    int ans = 0;
    for (int c1 = 0; c1 <= n2; c1++) {
        for (int c2 = 0; c2 <= n2; c2++) {
            ans = max(ans, dp[n][c1][c2]);
        }
    }
    printf("%d\n", ans);
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    bool flg2, flg3;

    cin >> t;
    while (t--) {
        flg2 = flg3 = true;

        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i][1] >> a[i][2] >> a[i][3];
            flg2 &= (a[i][2] == 0);
            flg3 &= (a[i][3] == 0);
        }
        if (n <= 200)
            solve();
        else if (flg2 && flg3)
            solve23();
        else if (!flg2 && flg3)
            solve3();
        else
            solve();
    }
    return 0;
}
