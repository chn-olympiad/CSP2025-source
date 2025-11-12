#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#define int long long
using namespace std;
int n, m;
int id[1010], c[1010];
bool used[1010];
int ans = 0;
string s;
void dfs(int stp) {
    if(stp > n) {
        int eli = 0, cnt = 0;
        for(int i = 1; i <= n; i++) {
            if(eli >= c[id[i]]) {
                eli++;
                continue;
            }
            if(s[i - 1] == '0') {
                eli++;
                continue;
            }
            cnt++;
        }
        if(cnt >= m) ans++;
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(!used[i]) {
            id[stp] = i;
            used[i] = 1;
            dfs(stp + 1);
            id[stp] = 0;
            used[i] = 0;
        }
    }
}
int h[1010];
int sm[1010];
int dp[1010][1010];
signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    for(int i = 1; i <= n; i++) cin >> c[i];
    if(m == n) {
        bool f = 1;
        int ansss = 1;
        for(int i = 0; i < n; i++) {
            if(s[i] != '1' || c[i + 1] == 0) f = 0;
        }
        if(!f) cout << 0;
        else {
            for(int i = 1; i <= n; i++) {
                ansss *= i;
                ansss %= 998244353;
            }
            cout << ansss;
        }
        return 0;
    }
    else if(m == 1) {
        for(int i = 1; i <= n; i++) h[c[i]]++;
        for(int i = 1; i <= n; i++) sm[i] = sm[i - 1] + h[i];
        int cnt1 = 0;
        int ansss = 1;
        for(int i = 0; i < n; i++) {
            if(s[i] == 1) {
                int t = sm[i] - cnt1;
                if(t < 0) t = 0;
                ansss *= t;
                ansss %= 998244353;
                cnt1++;
            }
        }
        for(int i = 1; i <= n - cnt1; i++) {
            ansss *= i;
            ansss %= 998244353;
        }
        cout << ansss;
        return 0;
    }
    bool fl = 0;
    for(int i = 0; i < n; i++) if(s[i] == '0') fl = 1;
    if(!fl) {
        for(int i = 1; i <= n; i++) h[c[i]]++;
        for(int i = 1; i <= n; i++) sm[i] = sm[i - 1] + h[i];
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= i; j++) {
                dp[i][j] = dp[i - 1][j] * (sm[n] - sm[j]);
                dp[i][j] %= 998244353;
                if(j > 0) dp[i][j] += dp[i - 1][j - 1] * sm[j - 1], dp[i][j] %= 998244353;
            }
        }
        int sss = 0;
        for(int i = m; i <= n; i++) sss += dp[n][i];
        cout << sss;
        return 0;
    }
    dfs(1);
    cout << ans;
    return 0;
}