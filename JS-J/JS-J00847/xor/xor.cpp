#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 23169;
int n, k, pre[maxn], a[maxn];
int dp[maxn][maxn];
int sum(int b, int e) {
    return pre[e] ^ pre[b - 1];
}
int dfs(int i, int j) {
    if (j <= 23168 && dp[i][j] != dp[maxn - 1][maxn - 1]) return dp[i][j];
    int res = 0;
    if (sum(i, j) == k) res = 1;
    for (int it = i; it < j; it++) {
        res = max(res, dfs(i, it) + dfs(it + 1, j));
    }
    dp[i][j] = res;
    return res;
}
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    memset(dp, 0x80, sizeof dp);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i == 1) pre[i] = a[i];
        else pre[i] = a[i] ^ pre[i - 1];

        if (a[i] == k) dp[i][i] = 1;
        else dp[i][i] = 0;
    }
    cout << dfs(1, n);
    return 0;
}
