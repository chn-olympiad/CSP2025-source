#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 2e5 + 5, M = 1 << 18, mod = 998244353;
int n, m, c[N];
char s[N];
int id[15];
int f[M][18]; // 当前状态，放弃个数
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    for(int i = 0; i < n; i++) cin >> c[i];
    if (n <= 10) {
        for(int i=0; i<n;i++)id[i]=i;
        int ans = 0;
        do{
            int t = 0;
            for (int i = 0; i < n; i++)
                if (s[i] == '0' || t >= c[id[i]]) t++;
            ans += (n - t >= m);
        }while(next_permutation(id, id+n));
        cout << ans << '\n';
    } else if (n <= 18) {
        f[0][0] = 1;
        for (int cur = 0; cur < (1ll << n); cur++) {
            int L = __builtin_popcountll(cur);
            for (int j = 0; j < n; j++) if (!(cur >> j & 1)) {
                int nxt = cur | 1ll << j;
                for (int i = 0; i <= L; i++) {
                    int nxtc = (i >= c[j] || s[L] == '0') + i;
                    // cout << nxt << "," << nxtc << " <- " << cur << "," << i << '\n';
                    f[nxt][nxtc] = (f[nxt][nxtc] + f[cur][i]) % mod;
                }
            }
        }
        // for (int cur = 0; cur < (1 << n); cur++) {
        //     cout << "cur=" << cur << ": ";
        //     for (int i = 0; i < n; i++) cout << f[cur][i] << ' ';
        //     cout << '\n';
        // }
        int ans = 0;
        for (int i = 0; i <= n - m; i++)
            ans = (ans + f[(1 << n) - 1][i]) %mod;
        cout <<ans << '\n';
    }
    return 0;
}
// 20pts