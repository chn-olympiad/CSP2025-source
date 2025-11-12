#include <bits/stdc++.h>
using namespace std;
int n, ans;
long long k, a[500007], sum[500007];
bool vis[1005][105][3][1005];
long long xo(long long x, long long y) {
    if (x == 0) return y;
    if (y == 0) return x;
    vector<int> x_2, y_2, ans;
    while (x > 0) {
        x_2.push_back(x % 2);
        x /= 2;
    }
    if (x) x_2.push_back(x);
    while (y > 0) {
        y_2.push_back(y % 2);
        y /= 2;
    }
    long long X = x_2.size(), Y = y_2.size();
    if (y) y_2.push_back(y);
    if (X > Y) {
        for (long long i = 1; i <= X - Y; i++) y_2.push_back(0);
    } else if (Y > X){
        for (long long i = 1; i <= Y - X; i++) x_2.push_back(0);
    }
    for (long long i = 0; i < max(X, Y); i++) {
        ans.push_back((x_2[i] + y_2[i]) % 2);
    }
    long long ret = 0, cnt = 1;
    for (long long i = 0; i < ans.size(); i++) {
        ret += ans[i] * cnt;
        cnt <<= 1;
    }
    return ret;
}
void dfs(int p, int cnt, bool ch, int l) {
    if (vis[p][cnt][ch][l]) return ;
    if (p == n - 1 && cnt < ans - 1) return ;
    vis[p][cnt][ch][l] = true;
    if (p > n) {
        ans = max(ans, cnt);
        return ;
    }
    if (ch) {
        if (xo(sum[p], sum[l - 1]) == k) {
            dfs(p + 1, cnt + 1, 0, 0);
            dfs(p + 1, cnt + 1, 1, p + 1);
        } else {
            dfs(p + 1, cnt, 1, l);
        }
    } else {
        dfs(p + 1, cnt, 0, 0);
        dfs(p + 1, cnt, 1, p + 1);
    }
}
int main() {
    freopen("xor.in", "w", stdin);
    freopen("xor.out", "r", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    sum[1] = a[1];
    for (int i = 2; i <= n; i++) {
        sum[i] = xo(sum[i - 1], a[i]);
    }
    dfs(1, 0, 1, 1);
    dfs(1, 0, 0, 0);
    printf("%d", ans);
    return 0;
}
