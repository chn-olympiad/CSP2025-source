#include <bits/stdc++.h>
using namespace std;
long long a[100005][5], ans;
long long n;
void dfs(long long x, long long sum, long long s1, long long s2, long long s3) {
    if (s1 > n / 2 || s2 > n / 2 || s3 > n / 2) {
        return;
    }
    if (x == n) {
        ans = max(sum, ans);
        return;
    }
    dfs(x + 1, sum + a[x + 1][1], s1 + 1, s2, s3);
    dfs(x + 1, sum + a[x + 1][2], s1, s2 + 1, s3);
    dfs(x + 1, sum + a[x + 1][3], s1, s2, s3 + 1);
}
int main () {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for (long long i = 1; i <= n; i++) {
            cin >> a[i][1] >> a[i][2] >> a[i][3];
        }
        dfs(0, 0, 0, 0, 0);
        cout << ans << "\n";
        ans = 0;
    }
    return 0;
}
