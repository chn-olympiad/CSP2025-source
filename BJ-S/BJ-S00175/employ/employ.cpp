#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
int p[510], c[510];
signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m, ans = 0;
    string s;
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++) cin >> c[i], p[i] = i;
    if (m == 1) {
        int ans = 1;
        for (int i = 1; i <= n; i++) ans *= i;
        cout << ans;
        return 0;
    }
    do {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (sum >= c[p[i]]) sum++;
            else if (s[i - 1] == '0') sum++;
        }
        (ans += (n - sum >= m ? 1 : 0)) %= mod;
    } while(next_permutation(p + 1, p + n + 1));
    cout << ans;
    return 0;
}
// 罢了，如此便好
// AFOed