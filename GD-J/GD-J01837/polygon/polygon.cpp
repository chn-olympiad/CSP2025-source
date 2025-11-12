#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 10005
const int MOD(998244353);

int n, ans; int a[MAXN]; int f[4][MAXN], g[4][MAXN];

signed main(){
    freopen("polygon.in", "r", stdin); freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n; for (int i(1); i<=n; ++i) cin >> a[i]; sort(a+1, a+n+1); f[0][0] = 1;
    for (int i(1); i<=n; ++i){
        memset(g, 0, sizeof(g));
        for (int _: {0, 1, 2, 3}) for (int j(0); j<=10001; ++j){
            if (f[_][j]) (g[min(_+1, 3ll)][min(j+a[i], 10001ll)] += f[_][j]) %= MOD;
        }
        (ans += accumulate(g[3]+2*a[i]+1, g[3]+MAXN, 0ll)) %= MOD;
        for (int _: {0, 1, 2, 3}) for (int j(0); j<=10001; ++j) (f[_][j] += g[_][j]) %= MOD;
    }
    cout << ans;

    return 0;
}