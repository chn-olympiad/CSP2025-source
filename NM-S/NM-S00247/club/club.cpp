#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5+5;
const int INF = 0x3f3f3f3f;
int a[MAXN][4];
int dp[205][205][205];
int n;
void init(){
    memset(a, 0, sizeof(a));
    n = 0;
}
void BF(){
    for (int c = 1; c <= n; ++c){
        for (int i = 0; i <= n / 2; ++i){
            for (int j = 0; j <= n / 2; ++j){
                if (c - i - j > 0) dp[c][i][j] = dp[c - 1][i][j] + a[c][1];
                else dp[c][i][j] = -INF;
                if (i) dp[c][i][j] = max(dp[c][i][j], dp[c - 1][i - 1][j] + a[c][2]);
                if (j) dp[c][i][j] = max(dp[c][i][j], dp[c - 1][i][j - 1] + a[c][3]);
                //printf("dp[%d][%d][%d]=%d\n", c, i, j, dp[c][i][j]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= n / 2; ++i){
        for (int j = 0; j <= n / 2 && j <= n - i; ++j){
            int k = n - i - j;
            if (k < 0 || k > n / 2) continue;
            ans = max(ans, dp[n][i][j]);
        }
    }
    printf("%d\n", ans);
}
void foo(){
    vector<int> v = {};
    for (int i = 1; i <= n; ++i) v.push_back(a[i][2] - a[i][1]);
    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = n - 1; i >= n / 2; --i) ans += v[i];
    for (int i = 1; i <= n; ++i) ans += a[i][1];
    printf("%d\n", ans);
}
void solve(){
    scanf("%d", &n);
    bool flag = true;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= 3; ++j)
            scanf("%d", &a[i][j]);
        if (a[i][3]) flag = false;
    }
    if (n <= 200) BF();
    else if (flag) foo();
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    //freopen("club2.in", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) solve();
    return 0;
}
