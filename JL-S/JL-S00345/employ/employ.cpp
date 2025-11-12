#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, l, r) for(int i = (int) l; i <= (int) r; i++)
#define per(i, r, l) for(int i = (int) r; i >= (int) l; i--)
#define PII pair<int, int>

const int mod = 998244353;
const int N = 510;
int n, m, c[N];
char s[N];
int dp[N][N][N][2];

int main() {
    freopen("employ1.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%d%d%s", &n, &m, s + 1);
    rep(i, 1, n)
        scanf("%d", &c[i]);
    rep(i, 1, n) {
        rep(k, 0, i) {
            rep(j, 1, n) {
                if(s[i] == '0') {
                    int sum = 0;
                    rep(l, 1, j - 1)
                        sum = (sum + max(dp[i - 1][l][k - 1][0], dp[i - 1][l][k - 1][1])) % mod;
                    dp[i][j][k][0] += sum;
                } else if(k >= c[j]) {
                    int sum = 0;
                    rep(l, 1, j - 1)
                        sum = (sum + max(dp[i - 1][l][k - 1][0], dp[i - 1][l][k - 1][1])) % mod;
                    dp[i][j][k][0] = (dp[i][j][k][0] + sum) % mod;
                } else {
                    int sum = 0;
                    rep(l, 1, j - 1)
                        sum = (sum + max(dp[i - 1][l][k][0], dp[i - 1][l][k][1])) % mod;
                    dp[i][j][k][1] = (dp[i][j][k][1] + sum + 1) % mod;
                }
            }
        }
    }
    int ans = 0;
    rep(i, 1, n)
        rep(j, 1, n - m)
            ans = max({ans, dp[n][i][j][0], dp[n][i][j][1]});
    printf("%d\n", ans);
}
