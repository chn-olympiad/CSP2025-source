#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> a;
vector<int> vis(3);
int n, ans;
void dfs(int depth, int sum) {
    if (depth == n) {
        ans = max(ans, sum);
    } else {
        int m = n / 2;
        for (int i = 0; i < 3; i++) {
            if (vis[i] == m)
                continue;

            vis[i]++;
            dfs(depth + 1, sum + a[depth + 1][i]);
            vis[i]--;
        }
    }
}

bool cmp(vector<int> &a, vector<int> & b) {
    return a[0] > b[0];
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        ans = 0;
        cin >> n;

        int type = 1;

        a.resize(n + 1, vector<int>(3));
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < 3; j++)
                cin >> a[i][j];
        for (int i = 1; i <= n; i++) {
            if (a[i][1] != a[i][2])
                type = 0;
        }

        if (type == 0) {
            dfs(0, 0);
        }
        if (type == 1) {
            sort(a.begin(), a.end(), cmp);
            ans = ans + a[0][0] + a[1][0];
        }
        cout << ans << endl;
    }
    return 0;
}
