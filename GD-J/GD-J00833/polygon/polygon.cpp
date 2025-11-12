#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 3, mod = 998244353;
int n, a[MAXN], dp[MAXN * 2];

void Add(int &x, int y){ ((x += y) >= mod) && (x -= mod); }

signed main(){
    freopen("polygon.in", "r", stdin), freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n; for(int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    dp[0] = 1; int ans = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = a[i] + 1; j <= 10001; ++j) Add(ans, dp[j]);
        for(int j = 10001; j >= 0; --j){
            Add(dp[min(j + a[i], 10001)], dp[j]);
        }
    }
    cout << ans;

    return 0;
}