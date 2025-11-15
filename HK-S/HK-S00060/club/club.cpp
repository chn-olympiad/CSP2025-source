#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100005;

int n, w[4][N] = {0};

void solve () {
    int ans = -1;
    for (int i = 1; i <= 3; i++) {
        int v[N] = {0}, ans2 = 0;
        for (int j = 1; j <= n; j++) {
            int mx = 0;
            for (int k = 1; k <= 3; k++) mx = max(mx, (i == k ? -1 : w[k][j]));
            v[j] = mx;
        }
        pair<int, int> dif[N];
        for (int j = 1; j <= n; j++) {
            dif[j] = {v[j] - w[i][j], j};
        }
        sort(dif + 1, dif + n + 1);
        for (int j = 1; j <= n; j++) {
            if (j <= n / 2) ans2 += w[i][dif[j].second];
            else ans2 += v[dif[j].second];
        }
        // for (int j = 1; j <= n; j++) cout << w[i][j] << " " << v[j] << " " << dif[j].first << " " << dif[j].second << "\n";
        // cout << "\n";
        ans = max(ans, ans2);
    }
    cout << ans << "\n";
    return;
}

int recr (int a, int b, int c, int val) {
    if (a + b + c == n) {
        if (a <= n / 2 && b <= n / 2 && c <= n / 2) return val;
        else return 0;
    }
    return max(recr(a + 1, b, c, val + w[1][a + b + c + 1]), max(recr(a, b + 1, c, val + w[2][a + b + c + 1]), recr(a, b, c + 1, val + w[3][a + b + c + 1])));
}

signed main () {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int mode = 1, t;
    if (mode == 1) cin >> t;
    else t = 1;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> w[1][i] >> w[2][i] >> w[3][i];
        if (n > 10) solve();
        else {
            cout << recr(0, 0, 0, 0) << "\n";
        }
    }
    fclose(stdin); fclose(stdout);
    return 0;
}