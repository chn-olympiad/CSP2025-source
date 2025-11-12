#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int T;
    cin >> T;

        while (T--) {

        int n, ans = 0;
        cin >> n;

        vector<vector<int>> a(n + 1, vector<int>(3));

        vector<int> cnt(3, 0);
        priority_queue<pair<int, int>> pq;

        for (int i = 1; i <= n; ++i) {
            int mina = 1e9;
            for (int j = 0; j < 3; ++j) {
                cin >> a[i][j];
                mina = min(mina, a[i][j]);
            }
            ans += mina;
            for (int j = 0; j < 3; ++j) {
                a[i][j] -= mina;
                pq.push({a[i][j], j});
            }
        }

        int abcd = 0;

        while (!pq.empty()) {
            auto pr = pq.top(); pq.pop();
            int u = pr.first;
            int v = pr.second;
            if (cnt[v] < n / 2) {
                cnt[v]++;
                abcd++;
                ans += u;
                if (abcd == n) {
                    break;
                }
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
