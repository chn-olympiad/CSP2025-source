#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
int T, n, ans, a[N][3], ord[N][3];
multiset<int> s[3];

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> n;
        ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < 3; j++)
                cin >> a[i][j];
        for (int i = 0; i < 3; i++) s[i].clear();
        for (int i = 1; i <= n; i++) {
            iota(ord[i], ord[i] + 3, 0);
            sort(ord[i], ord[i] + 3, [&] (int x, int y) { return a[i][x] > a[i][y]; });
            ans += a[i][ord[i][0]];
            s[ord[i][0]].emplace(a[i][ord[i][0]] - a[i][ord[i][1]]);
        }
        // printf("Stage 1: %d\n", ans);
        int p = -1;
        for (int i = 0; i < 3 && p == -1; i++) {
            // printf("s[%d].size() = %d\n", i, s[i].size());
            if (s[i].size() > n / 2)
                p = i;
        }
        // printf("p = %d\n", p);
        if (p != -1) {
            int cnt = s[p].size() - n / 2;
            for (const auto& x : s[p]) {
                ans -= x, cnt--;
                if (cnt == 0) break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}