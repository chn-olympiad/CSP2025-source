#include <bits/stdc++.h>
using namespace std;
int a[100005][3], n, res;
vector<int> sol[3];
void dfs(int u, int sum, int useda, int usedb, int usedc) {
    if (u > n) {
        res = max(res, sum);
        return ;
    }
    if (useda < n / 2) {
        dfs(u + 1, sum + a[u][0], useda + 1, usedb, usedc);
    }
    if (usedb < n / 2) {
        dfs(u + 1, sum + a[u][1], useda, usedb + 1, usedc);
    }
    if (usedc < n / 2) {
        dfs(u + 1, sum + a[u][2], useda, usedb, usedc + 1);
    }
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        int maxn = max(max(a[i][0], a[i][1]), a[i][2]);
        if (maxn == a[i][0]) {
            sol[0].push_back(i);
        } else if (maxn == a[i][1]) {
            sol[1].push_back(i);
        } else {
            sol[2].push_back(i);
        }
    }

    int sum = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < min<int>(sol[i].size(), n / 2); j++) {
            sum += a[sol[i][j]][i];
        }
    }

    int pt1 = -1, pt2 = -1, sma = -1;
    if (sol[0].size() <= n / 2) {
        pt1 = 1, pt2 = 2;
        sma = 0;
    } else if (sol[1].size() <= n / 2) {
        pt1 = 0, pt2 = 2;
        sma = 1;
    } else if (sol[2].size() <= n / 2) {
        pt1 = 0, pt2 = 1;
        sma = 2;
    } else {
        cout << sum << endl;
        return ;
    }
    if (sol[1].size() == 0 && sol[2].size() == 0) {
        sort(sol[0].begin(), sol[0].end(), [](int x, int y){return a[x][0] > a[y][0];});
        sum = 0;
        for (int i = 0; i < n / 2; i++) {
            sum += a[sol[0][i]][0];
        }
        cout << sum << endl;
    }
    res = 0;
    dfs(1, 0, 0, 0, 0);
    cout << res << endl;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
