#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int kmax = 505;
const int Mod = 998244353;
int n, m;
string str;
int a[kmax];

namespace Sub1 {

    const int kmaxM = 19;

    long long f[1 << kmaxM][kmaxM];

    void Solve() {
        f[0][0] = 1;
        for(int i = 0; i < 1 << n; i++) {
            int ct = __builtin_popcount(i);
            for(int j = 0; j <= ct; j++) {
                if(!f[i][j]) continue;
                int rc = ct - j;
                for(int k = 0; k < n; k++) {
                    if(i & (1 << k)) continue;
                    if(str[ct + 1] == '1' && a[k + 1] > rc) {
                        f[i ^ (1 << k)][j + 1] += f[i][j];
                        if(f[i ^ (1 << k)][j + 1] >= Mod) f[i ^ (1 << k)][j + 1] -= Mod; 
                    } else {
                        f[i ^ (1 << k)][j] += f[i][j];
                        if(f[i ^ (1 << k)][j] >= Mod) f[i ^ (1 << k)][j] -= Mod;
                    }
                }
            }
        }
        long long res = 0;
        for(int i = m; i <= n; i++) {
            res += f[(1 << n) - 1][i];
            if(res >= Mod) res -= Mod;
        }
        cout << res << '\n';
    }
}

namespace Sub2 {

    void Solve() {
        for(int i = 1; i <= n; i++) {
            if(str[i] == '0') {
                cout << 0 << '\n';
                return;
            }
        }
        for(int i = 1; i <= n; i++) {
            if(a[i] == 0) {
                cout << 0 << '\n';
                return;
            }
        }
        long long res = 1;
        for(int i = 1; i <= n; i++) {
            res = res * i % Mod;
        }
        cout << res << '\n';
    }
}

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> str;
    str = ' ' + str;
    for(int i = 1; i <= n; i++) cin >> a[i];
    if(n <= 18) {
        Sub1::Solve();
    } else if(n == m) {
        Sub2::Solve();
    }
    return 0;
}