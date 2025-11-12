#include <bits/stdc++.h>
using namespace std;
int n;
bool f[5005];
int a[5005];
long long ans = 0;
bool is() {
    int maxn = -1;
    int sum = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (f[i]) cnt++;
        sum += f[i] * a[i];
        maxn = max(maxn, f[i] * a[i]);
    }
    if (cnt >= 3 && sum > maxn * 2 && maxn > 0) return 1;
    return 0;
}
void dfs(int x) {
    if (x > n) return;
    dfs(x + 1);
    f[x] = 1;
    ans += is();
    dfs(x + 1);
    f[x] = 0;
}
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    int amax = -1;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        amax = max(amax, a[i]);
    }
    if (amax == 1) {
        int cnt1 = 0;
        for (int i = 1; i <= n; i++) cnt1 += a[i];
        int t = 1;
        for (int i = 1; i <= cnt1; i++) {
            t *= 2;
            t %= 998244353;
        }
        t -= cnt1 * (cnt1 + 1) / 2 + 1;
        t = (t + 998244353) % 998244353;
        cout << t << endl;
    }
    else {
        dfs(0);
        cout << (ans / 2) % 998244353 << endl;
    }
    return 0;
}
