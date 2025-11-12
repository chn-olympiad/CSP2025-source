#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, t, a[N][3], mxi[N];
bool vis[N];
pair<int, int> to[3][N];
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    for (cin >> t; t; t--) {
        cin >> n;
        memset(mxi, 0, sizeof(mxi));
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < 3; j++)
                if (a[i][mxi[i]] <= a[i][j]) mxi[i] = j;
        }
        int s[3] = {0, 0, 0};
        for (int i = 1; i<= n; i++) s[mxi[i]]++;
        int ge = 0;
        for (int j = 0; j < 3; j++) if (s[j] > n / 2.0) ge = j;
        for (int i = 0; i < N; i++) for (int j = 0 ; j < 3; j++) to[j][i] = {0xc0c0c0c0, 0};
        for (int i = 1; i <= n; i++) if (mxi[i] == ge) {
            for (int j = 0; j < 3; j++) if (j != ge)
                to[j][i] = {-a[i][ge] + a[i][j], i};
        }
        for (int j = 0; j < 3; j++)
            sort(to[j] + 1, to[j] + n + 1, greater<pair<int, int>> {});
        int ptr[3] = {1, 1, 1};
        int ans = 0;
        for (int i = 1; i <= n; i++) ans += a[i][mxi[i]];
        // cout << "ge: " << ge << '\n';
        // for (int i = 1; i <= n; i++, cout << '\n')
        //     for (int j = 0; j < 3; j++)
        //         cout << to[j][i].first << ' ';
        // cout << "no lim: " << ans << endl;
        // cout << s[0] << " " << s[1] << " " << s[2] << '\n';
        // cout << "n=" << n << ", s[ge]=" << s[ge] << '\n';
        while (s[ge] > n / 2.0) {
            int mxj = 0;
            for (int j = 0; j < 3; j++)
                while (ptr[j] <= n && vis[to[j][ptr[j]].second]) ptr[j]++;
            for (int j = 0; j < 3; j++) if (j != ge)
                if (to[mxj][ptr[mxj]].first < to[j][ptr[j]].first) mxj = j;
            vis[to[mxj][ptr[mxj]].second] = 1;
            // cout << "mark" << to[mxj][ptr[mxj]].second << '\n';
            ans += to[mxj][ptr[mxj]++].first;
            // cout << "ans += " << to[mxj][ptr[mxj] - 1].first << '\n';
            s[ge]--;
        } 
        cout << ans << '\n';
    }
    return 0;
}
// 100pts