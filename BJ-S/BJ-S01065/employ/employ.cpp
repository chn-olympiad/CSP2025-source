#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const int MAXN = 20, MAXS = 1 << 18;
ll MOD = 998244353;
ll f[MAXS][MAXN];
int a[MAXN], c[MAXN];
void add(ll &x, ll y){
    x = (x + y) % MOD;
}
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        char c;
        cin >> c;
        a[i] = c - '0';
    }
    for (int i = 1; i <= n; i++){
        cin >> c[i];
    }
    f[0][0] = 1;
    for (int s = 0; s < (1 << n) - 1; s++){
        int i = __builtin_popcount(s);
        for (int j = 1; j <= n; j++){
            if ((s >> (j - 1)) & 1){
                continue;
            }
            for (int k = 0; k <= i; k++){
                add(f[s | (1 << (j - 1))][k + (a[i + 1] == 0 || c[j] <= k)], f[s][k]);
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= n - m; i++){
        add(ans, f[(1 << n) - 1][i]);
    }
    cout << ans << '\n';
    return 0;
}