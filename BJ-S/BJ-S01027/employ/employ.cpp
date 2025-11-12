//LMY bao you bao li bie gua!!!~~~
#include <bits/stdc++.h>
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define lop(i, x, y) for (int i = x; i >= y; i--)
using namespace std;
const int MOD = 998244353;
const int NR = 502;
void upd(int &x, int y){
    x = (x + y) % MOD;
}
int n, m;
char df[NR];
int c[NR];
int zy_dp[(1 << 18)][20];
void zhuangya_DP(){
    zy_dp[0][0] = 1;
    rep(s, 0, (1 << n) - 1){
        int tmp = __builtin_popcount(s);
        rep(ly, 0, tmp){
            if (zy_dp[s][ly] == 0) continue;
            rep(i, 1, n){
                if ((s >> (i - 1)) & 1) continue;
                int d;
                if (ly <= tmp - c[i] || df[tmp + 1] == '0') d = 0;
                else d = 1;
                upd(zy_dp[s | (1 << (i - 1))][ly + d], zy_dp[s][ly]);
            }
        }
    }
    int ans = 0;
    rep(i, m, n){
        upd(ans, zy_dp[(1 << n) - 1][i]);
    }
    cout << ans << endl;
}
signed main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    rep(i, 1, n){
        cin >> df[i];
    }
    rep(i, 1, n){
        cin >> c[i];
    }
    if (n <= 18){
        zhuangya_DP();
        return 0;
    }
    return 0;
}
