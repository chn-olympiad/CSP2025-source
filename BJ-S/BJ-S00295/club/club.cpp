#include <bits/stdc++.h>
using namespace std;

/*int a[100005][4] = {}, ans[100005] = {}, stp = 1, sum, n, pos[100005];

void dfs(int i, int x) {
    if (i == n) {
        if (pos[1]) sum = max(sum, ans[stp] + a[i][1]);
        if (pos[2]) sum = max(sum, ans[stp] + a[i][2]);
        if (pos[3]) sum = max(sum, ans[stp] + a[i][3]);
        stp++;
        return;
    }
    else if (x == 1) {
        if (pos[1]) {
            ans[stp] += a[i][1];
            pos[1]--;
            dfs(i + 1, 1);
            pos[1]++;
        }
        dfs(i, 2);
        dfs(i, 3);
    }
    else if (x == 2) {
        if (pos[2]) {
            ans[stp] += a[i][2];
            pos[2]--;
            dfs(i + 1, 2);
            pos[2]++;
        }
        dfs(i, 1);
        dfs(i, 3);
    }
    else if (x == 3) {
        if (pos[3]) {
            ans[stp] += a[i][3];
            pos[3]--;
            dfs(i + 1, 3);
            pos[3]++;
        }
        dfs(i, 1);
        dfs(i, 2);
    }
}*/
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t; cin >> t;
    while (t--) {
        /*memset(a, 0, sizeof a);
        memset(ans, 0, sizeof ans);
        memset(pos, 0, sizeof pos);
        stp = 1, sum = 0;*/
        int n, dp[205][5][105] = {}, a[100005] = {};
        cin >> n;
        int t1, t2, cnt = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i] >> t1 >> t2;
        }
        sort(a + 1, a + n + 1, cmp);
        for (int i = 1; i <= n / 2; i++) {
            cnt += a[i];
        }
        cout << cnt << endl;
    }
    return 0;
}
