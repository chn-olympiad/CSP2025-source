#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int n, m, f[20][1 << 18], c[505];
string s;
int main() {
    //cout << sizeof(f);
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> s;
    for(int i = 1; i <= n; ++i) cin >> c[i];
    if(n <= 18) {
        f[0][0] = 1;
        for(int j = 1; j < (1 << n); ++j) {
            int now = 0;
            for(int k = n - 1; ~k; --k) now += bool(j & (1 << k));
            for(int i = 0; i <= n; ++i)
                for(int k = n; k; --k) 
                    if(j & (1 << k - 1)) 
                        f[i][j] += s[now - 1] == '0' ? 
                        (i - 1 >= 0 ? f[i - 1][j - (1 << k - 1)] : 0) : 
                        (c[k] > i) ? f[i][j - (1 << k - 1)] : (c[k] < i && i - 1 >= 0 ? f[i - 1][j - (1 << k - 1)] : 0),
                        f[i][j] %= mod;
        }
        int ans = 0;
        for(int i = n - m; i; --i) ans += f[i][(1 << n) - 1], ans %= mod;
        printf("%d", ans);
    }
    return 0;
}