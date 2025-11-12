#include <bits/stdc++.h>
using namespace std;
#define ll long long
int read() {
    int x = 0;char ch = getchar();
    while (ch < '0' || ch > '9') ch  =getchar();
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x;
}
const int MAXN = 500, mod = 998244353;
void inc(int &a, int b) {
    (a += b);
    (a >= mod) && (a -= mod);
    return ;
}
int n, m;
char ss[MAXN + 5];
int c[MAXN + 5];
namespace SOLVE1 {
    const int MAXN = 18;
    int dp[MAXN + 5][(1 << MAXN) + 5];
    void solve() {
        dp[0][0] = 1;
        for (int s = 0; s < (1 << n) - 1; s ++) {
            for (int j = 0; j <= n; j ++) {
                // cout<<s<<' '<<j<<' '<<dp[j][s]<<endl;
                int i = 0;
                for (int j = 1; j <= n; j ++)
                    if (s >> (j - 1) & 1) i ++;
                for (int k = 1; k <= n; k ++) {
                    if (!(s >> (k - 1) & 1)) {
                        if (ss[i + 1] == '0' || c[k] <= j)
                            inc(dp[j + 1][s | (1 << (k - 1))], dp[j][s]);
                        
                        else
                            inc(dp[j][s | (1 << (k - 1))], dp[j][s]);
                    
                    }
                }
            }
        }
        int ans =0 ;
        for (int j = 0; j <= n - m; j ++) inc(ans, dp[j][(1 << n) - 1]);
        cout<<ans;
        return ;
    }
}
namespace SOLVE2 {
//     int fac[MAXN + 5];
//     int dp[MAXN + 5][MAXN + 5][MAXN + 5]; // 前 i 大的数，下降了 j 次, 钦定有 k 个数不满足条件
    void solve() {
//         fac[0] = 1;
//         for (int i = 1; i <= MAXN; i ++) fac[i] = (ll)fac[i - 1] * i % mod;
//         sort(c + 1, c + 1 + n, [](int a, int b) {
//             return a > b;
//         });
//         for (int i = 1; i <= n; i ++) {
//             for (int j = 0; j <= i; j ++) {
//                 for (int k = 0; k <= i; k ++) {
//                     // 
//                     // 最后一个数 上升
//                     inc(dp[i][j][k], (ll)dp[i - 1][j + 1][k] * max(0, ((n - 1 - c[i] + 1) - (i - 1 + k))) % mod);
//                     // 最后一个数 平 没有限制
//                     inc(dp[i][j][k], dp[i - 1][j][k]);
//                     // 最后一个数 平 限制 c_i <= cnt
//                     inc(dp[i][j][k], (ll)dp[i - 1][j][k - 1] * max(0, ((n - 1 - c[i] + 1) - (i - 1 + k - 1))) % mod);
//                 }
//             }
//         }
//         int ans = 0;
//         for (int j = 0; j <= n - m; j ++) {
//             for (int k = 0; k <= n; k ++) {
//                 dp[n][j][k] * fac[]
//             }
//         }
    }

}
namespace SOLVE3 {
    int fac[MAXN + 5];
    int f[MAXN + 5][MAXN + 5];
    int d[MAXN + 5];
    int ppp[MAXN + 5]; // 有多少个限制 >= i
    void solve() {
        fac[0] = 1;
        for (int i = 1; i <= MAXN; i ++) fac[i] = (ll)fac[i - 1] * i % mod;
        sort(c + 1, c + 1 + n, [](int a, int b) {
            return a > b;
        });
        int ans = 1;
        int cnt = 0;
        for (int i = n; i >= 1; i --) {
            if (ss[i] == '1') d[++ cnt] = i - 1;
        }
        for (int i = 0; i <= n; i ++) {
            for (int j = 1; j <= cnt; j ++) {
                if (d[j] >= i) ppp[i] ++;
            }
        }


        f[0][0] = 1;
        for (int i = 1; i <= n; i ++) {
            for (int j = 0; j <= cnt; j ++) {
                if (j >= 1)
                inc(f[i][j], (ll)f[i - 1][j - 1] * max(0, (ppp[c[i]] - (j - 1))) % mod);
                else
                inc(f[i][j], f[i - 1][j]);
            }
        }
        ans = (fac[n] - (ll)f[n][cnt] * fac[n - cnt] % mod + mod) % mod;
        cout<<ans;
        return ;
    }

}
int main() {
    #ifndef LOCAL
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    #else
    freopen("./employ/employ4.in", "r", stdin);
    freopen("code.out", "w", stdout);
    clock_t BEGINT = clock();
    #endif

    n = read(), m = read();
    scanf("%s", ss + 1);
    bool flag = 1;
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &c[i]);
        flag &= (ss[i] == '1');
    }
    if (n <= 18) {
        SOLVE1::solve();
        return 0;
    } 
    else 
    // if (flag) {
    //     SOLVE2::solve();
    // } else 
    if (m == 1) {
        SOLVE3::solve();
    } else if (m == n) {
        ll ans2 = 1;
        for (int i = 1; i <= n; i ++) {
            if (ss[i] == '0' || c[i] == 0) {
                cout<<0;
                return 0;
            }
            ans2 = (ll)ans2 * i % mod;
        }
        cout<<ans2;
        return 0;
    } 

    #ifdef LOCAL
    clock_t ENDT = clock();
    cerr<<endl<<fixed<<setprecision(3)<<(double)(ENDT - BEGINT) / CLOCKS_PER_SEC;
    #endif
    return 0;
}