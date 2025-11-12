#include <bits/stdc++.h>
using namespace std;

int main () {

    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<array<array<int, 2>, 3>> a(n + 5);
        vector<int> cnts[3];
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i][0][0] >> a[i][1][0] >> a[i][2][0];
            a[i][0][1] = 0; a[i][1][1] = 1; a[i][2][1] = 2;
            sort(a[i].begin(), a[i].end(), greater<>());
            cnts[a[i][0][1]].emplace_back(i);
            ans += a[i][0][0];
        }
        for (int i = 0; i < 3; i++) if (cnts[i].size() > n >> 1) {
            vector<int> tmps;
            for (int j : cnts[i]) {
                tmps.emplace_back(a[j][0][0] - a[j][1][0]);
            }
            sort(tmps.begin(), tmps.end());
            int len = cnts[i].size() - (n >> 1);
            for (int j = 0; j < len; j++) {
                ans -= tmps[j];
            }
            break;
        }
        cout << ans << '\n';
    }
    return 0;
}

// freopen("club.in", "r", stdin);
// freopen("club.out", "w", stdout);
// wei zhuang yi xia, neng bu neng shang mi huo xing wei da shang ne?
