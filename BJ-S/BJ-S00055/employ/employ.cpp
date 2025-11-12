#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 500 + 5;
const int mod = 998244353;
int n, m, c[N], t[N], pre[N];
string s;
LL dp[(1<<18)+5][25];
int one_cnt(int x) {
    int cnt = 0;
    while (x) {
        if (x % 2) cnt++;
        x /= 2;
    }
    return cnt;
}
void solve1() {
    dp[0][0] = 1;
    for(int i = 0; i < (1 << n)-1; i++) {
        int cnt = one_cnt(i);
        for(int j = 0; j <= cnt; j++) {
            for(int k = 1; k <= n; k++) {
                if (((i >> (n-k)) & 1) == 0) {
                    int to = i + (1 << (n-k));
                    if (c[k] <= j) dp[to][j+1] += dp[i][j], dp[to][j+1] %= mod;
                    else {
                        if (s[cnt+1] == '0') dp[to][j+1] += dp[i][j], dp[to][j+1] %= mod;
                        else dp[to][j] += dp[i][j], dp[to][j] %= mod;
                    }
                }
            }
        }
    }
    LL ans = 0;
    for(int i = 0; i <= n-m; i++) {
        ans += dp[(1<<n)-1][i], ans %= mod;
    }
    printf("%lld\n", ans);
}
void solve2() {
    for(int i = 1; i <= n; i++) {
        if (s[i] == '0') {
            cout << "0\n";
            return;
        }
    }
    for(int i = 1; i <= n; i++) {
        if (c[i] == 0) {
            cout << "0\n";
            return;
        }
    }
    LL ans = 1;
    for(int i = 1; i <= n; i++) {
        ans *= i, ans %= mod;
    }
    cout << ans << "\n";
}
void solve3() {
    LL ans = 1;
    LL totans = 1;
    for(int i = 1; i <= n; i++) {
        totans *= i, totans %= mod;
    }
    for(int i = 1; i <= n; i++) {
        t[c[i]]++;
    }
    for(int i = 0; i <= n; i++) {
        pre[i] = pre[i-1] + t[i];
    }
    int cnt = 0, cnt0 = 0;
    for(int i = 1; i <= n; i++) {
        if (s[i] == '0') cnt0++;
        else ans *= (pre[i-1]-cnt), ans %= mod, cnt++;
    }
    for(int i = 1; i <= cnt0; i++) {
        ans *= i, ans %= mod;
    }
    ans = totans-ans+mod, ans %= mod;
    printf("%lld\n", ans);
}
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%d%d", &n, &m);
    cin >> s;
    s = "." + s;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
    }
    if (n <= 18) {
        solve1();
    } else if (m == n) {
        solve2();
    } else if (m == 1) {
        solve3();
    }
    return 0;
}
