#include<bits/stdc++.h>
using namespace std;
const int N = 500005;
int a[N], sum[N];
pair<int, int>x[N];
int dp[1000][2];
int tmp[1000][2];
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    bool flag = true;
    for (int i = 1;i <= n; i++) {
        cin >> a[i];
        if (a[i] > 1)flag = false;
    }

    if (n <= 1000) {
        sum[1] = a[1];
        for (int i = 2;i <= n;i ++) {
            sum[i] = a[i] ^ sum[i - 1];
        }
        int tot = 0;
        for (int i = 1; i<= n; i++) {
            for (int j = i; j <= n; j++) {
                if ((sum[j] ^ sum[i - 1]) == k) {
                    x[++tot] = {j, i};
                }
            }
        }
        if (tot == 0) {
            cout << 0;
            return 0;
        }
        sort (x + 1, x + tot + 1);
        int ans = 1;
        int r = x[1].first;
        for (int i = 2; i<= tot ;i++) {
            if (x[i].second > r) {
                r = x[i].first;
                ans++;
            }
        }
        cout << ans;
        return 0;
    }
    if (flag) {
        int ans = 0;
        for (int i = 2; i<=n;i++) {
            if ((a[i] ^ a[i - 1]) == k)ans++, i++;
        }
        cout << ans;
        return 0;
    }
    if (k <= 255) {
        for (int i = 1; i < 1000;i++)dp[i][0] = dp[i][1] = -1;
        if (a[1] == k) {
            dp[k][1] = 1;
        } else {
            dp[a[1]][1] = 0;
        }
        dp[0][0] = 0;
        for (int i = 2; i<= n;i ++) {
            for (int j = 0; j <= 500 ;j++) {
                if (dp[j][0] == -1 && dp[j][1]==-1)continue;
                tmp[j][0] = dp[j][0];
                int xx = dp[j][1] + ((j ^ a[i]) == k);
                int yy = dp[j][0] + (a[i] == k);
                tmp[j ^ a[i]][1] = max(xx, yy);
            }
            for (int j = 0; j <= 500 ;j++) {
                if (dp[j][0] == -1 && dp[j][1]==-1)continue;
                dp[j][0] = tmp[j][0];
                dp[j][1] = tmp[j][1];
            }
        }
        int ans = 0;
        for (int j = 0; j <= 500 ;j++) {
            if (dp[j][0] == -1 && dp[j][1]==-1)continue;
            ans = max(ans, max(dp[j][0], dp[j][1]));
        }
        cout << ans;
        return 0;
    }
    return 0;
}
