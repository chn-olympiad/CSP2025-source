#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
const int N = 18;
const int MaxM = (1 << 18) + 5;
int n, m, s[N], c[N];
int popcnt[MaxM], dp[MaxM][N];
unordered_map<int, int> lg;
// dp[i][j] : 面试人员状态为i，j人未通过，总的方案数
void solve(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    popcnt[0] = 0;
    for (int i = 1;i < (1 << n);i++){
        popcnt[i] = popcnt[i ^ (i & -i)] + 1;
    }
    for (int i = 0;i <= 20;i++)
        lg[1 << i] = i;
    int sm, k, t, t1, add;
    dp[0][0] = 1;
    for (int i = 1;i < (1 << n);i++){
        sm = popcnt[i];
        for (int j = 0;j <= sm;j++){
            dp[i][j] = 0;
            k = i;
            while (k > 0){
                t1 = k & -k;
                t = lg[t1];
                if (s[sm - 1] == 1 && j < c[t]){ // 能通过
                    if (j == sm) add = 0;
                    else add = dp[i ^ t1][j];
                }
                else if (s[sm - 1] == 0 || j - 1 >= c[t]){
                    if (j == 0) add = 0;
                    else add = dp[i ^ t1][j - 1];
                }
                else add = 0;
                // cout << i << ' ' << j << ' ' << t << ' ' << add << ' ' << s[sm - 1] << ' ' << sm - j << endl;
                dp[i][j] = (dp[i][j] + add) % mod;
                k ^= t1;
            }
        }
    }
    /*
    for (int i = 0;i < (1 << n);i++){
        for (int j = 0;j <= popcnt[i];j++){
            cout << i << ' ' << j << ' ' << dp[i][j] << endl;
        }
    }
    */
    int ans = 0;
    for (int i = 0;i <= n - m;i++){
        ans = (ans + dp[(1 << n) - 1][i]) % mod;
    }
    cout << ans;
    exit(0);
}
signed main(){
    cin >> n >> m;
    string st; cin >> st;
    for (int i = 0;i < n;i++) s[i] = st[i] - '0';
    for (int i = 0;i < n;i++) cin >> c[i];
    if (n <= 18) solve();
}
/*
20 pts
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
2204128
RP++
*/
