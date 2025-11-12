# include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n, a[5001], cnt[5001];
long long ans = 0;
bool cmp(int x, int y) {
    return x < y;
}
void dfs(int x, int sum, int maxn) {
    int ans = 0;
    if(sum > maxn)
        ans++;
    if(x <= 0)
        return;
    dfs(x -1, sum + a[x], max(maxn, a[x]));
    dfs(x -1, sum, maxn);
}
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    sort(a + 1, a + n + 1, cmp);

    if(n == 3) {
        if(a[1] + a[2] > a[3])
            cout << (a[1] + a[2] + a[3]) % MOD;
        else
            cout << 0;
        return 0;
    }


    for(int i = 1;i <= n;i++)
        cnt[i] = dfs(i - 1, 0, a[i]);
    for(int i = 1;i <= n;i++)
        ans += cnt[i];
    cout << ans % MOD;
    return 0;
}
