#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 505, MOD = 998244353;
int n, m, c[N], p[N];
string s;

int32_t main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) p[i] = i;
    if (n <= 10) {
        int ans = 0;
        do {
            int cnt = 0, cnt1 = 0;
            //for (int i = 1; i <= n; i++) cout << c[p[i]] << " ";
            for (int i = 1; i <= n; i++) {
                if (cnt >= c[p[i]]) cnt++;
                else {
                    if (s[i - 1] == '0') cnt++;
                    else cnt1++;
                }
            }
            //cout << cnt1 << "\n";
            if (cnt1 >= m) ans = (ans + 1) % MOD;
        } while(next_permutation(p + 1, p + n + 1));
        cout << ans << "\n";
    }
    
}