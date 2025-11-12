#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n;
int res[N];
int cnt[3];
int a[3][N];
int ans;

void dfs(int id) {
    if (id == n + 1) {
        int t = 0;
        for (int i = 1; i <= n; i++) t += a[res[i]][i];
        ans = max(ans, t);
        return;
    }
    for (int i = 0; i < 3; i++) {
        if (cnt[i] < n / 2) {
            res[id] = i;
            cnt[i]++;
            dfs(id + 1);
            cnt[i]--;
        }
    }
}

int main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            cin >> a[0][i] >> a[1][i] >> a[2][i];
            if (a[2][i]) flag = false;
        }
        if (flag) {
            sort(a[0] + 1, a[0] + n + 1, greater<int>());
            int ans = 0;
            for (int i = 1; i <= n / 2; i++) ans += a[i];
            cout << ans;
            continue;
        }
        ans = 0;
        cnt[0] = cnt[1] = cnt[2] = 0;
        dfs(1);
        cout << ans << endl;
    }
  fclose(stdin);
  fclose(stdout);
    return 0;
}