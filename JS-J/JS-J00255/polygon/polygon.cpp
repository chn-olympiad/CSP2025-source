#include <bits/stdc++.h>
using namespace std;
int n;
long long ans;
long long a[5010], fal[5010], fal1[5010];
bool vis[5010];

void dfs(int x, int t, int lst) {// t: 选几个
    if (x > t) {
        long long sum = 0, maxx = 0;
        //cout << "x = " << x << ", t = " << t << endl;
        for (int i = 1; i <= t; i++) {
            //cout << fal[i] << " ";
            sum += fal[i];
            maxx = max(maxx, fal[i]);
        }
        //cout << endl;
        if (sum > 2 * maxx) {
            ans++;
            ans %= 998244353;
            //cout << "ans = " << sum << " " << maxx << " " << ans << endl;
        }
        return ;
    }
    for (int i = lst + 1; i <= n; i++) {
        if (!vis[i]) {
            fal[x] = a[i];
            vis[i] = true;
            dfs(x + 1, t, i);
            fal[x] = 0;
            vis[i] = false;
        }
    }
}

int main() {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (n == 3) {
        long long sum = 0, maxx = -1;
        for (int i = 1; i <= n; i++) {
            maxx = max(maxx, a[i]);
            sum += a[i];
        }
        if (sum > maxx * 2) {
            cout << 1;
        }
        else cout << 0;
    } else if (n <= 20) {
        for (int i = 3; i <= n; i++) {
            memset(vis, false, sizeof vis);
            dfs(1, i, 0);
        }
        cout << ans;
        return 0;
    }
}
// 十年霸榜无人知，清者自清万认识 ---- 少羽
// 风雨难改我初心，不忘三字桂家军 ---- 桂哥
// 龙争虎斗彼岸花，桂哥给你一个家 ---- 桂哥
