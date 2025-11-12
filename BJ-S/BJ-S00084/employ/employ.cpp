#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
const int MOD = 998244353;

inline void add(int &a, int b) { a += b; if(a >= MOD) a -= MOD; }
int n, m;

namespace baoli {
    const int N = 20;
    int s[N + 5], c[N + 5];
    int cnt[1 << N], f[1 << N][N + 5];
    void work() {
        for(int i = 1; i <= n; i++) {
            char c; cin >> c;
            s[i] = c == '1';
        }
        for(int i = 1; i <= n; i++) cin >> c[i];
        for(int i = 1; i < (1 << n); i++) cnt[i] = cnt[i >> 1] + (i & 1);
        f[0][0] = 1;
        for(int t = 0; t < (1 << n) - 1; t++) {
            for(int i = 0; i <= cnt[t]; i++) {
                for(int j = 1; j <= n; j++) {
                    if((t >> j - 1) & 1) continue;
                    add(f[t | (1 << j - 1)][i + (!s[cnt[t] + 1] || i >= c[j])], f[t][i]);
                }
            }
        }
        int ans = 0;
        for(int i = m; i <= n; i++) add(ans, f[(1 << n) - 1][n - i]);
        cout << ans << '\n';
    }
}

namespace m1 {
    const int N = 510;
    int s[N], c[N];
    void work() {
        for(int i = 1; i <= n; i++) {
            char c; cin >> c;
            s[i] = c == '1';
        }
        for(int i = 1; i <= n; i++) cin >> c[i];
        sort(c + 1, c + 1 + n);
        int f = 1, g;
        for(int i = 1; i <= n; i++) {
            if(i <= c[i]) { f = 0; break; }
            g = (ll)f * (i - c[i]) % MOD;
            swap(f, g);
        }
        int ans = 1;
        for(int i = 1; i <= n; i++) ans = (ll)ans * i % MOD;
        cout << ans - f << '\n';
    }
}

int main() {

    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    cin >> n >> m;
    if(n <= 20) baoli::work();
    // else if(m == 1) m1::work();

    return 0;
}