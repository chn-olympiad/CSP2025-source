#include <bits/stdc++.h>
using namespace std;
long long n, ans, maxx, a[5001];
void dfs(long long x, long long big, long long sum, long long num) {
    if(x > n) {
        if(num >= 3 && sum > 2 * big) {
            ans++;
            if(ans == 998244353) ans = 0;
        }
        return;
    }
    dfs(x + 1, max(big, a[x]), sum + a[x], num + 1);
    dfs(x + 1, big, sum, num);
}
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(long long i = 1; i <= n; i++) {
        cin >> a[i];
        maxx = max(maxx, a[i]);
    }
    if(maxx == 1) {
        for(long long i = n; i >= 3; i--) {
            ans += (n - i + 2) * (n - i + 1) / 2;
            ans %= 998244353;
        }
    } else {
        dfs(1, 0, 0, 0);
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
