#include <bits/stdc++.h>
#define rep(x, y, z) for (int x = y; x <= z; x++)
using namespace std;
using ll = long long;
constexpr int N = 514;
constexpr ll mod = 998244353;

namespace Otaku {
    int n, m, A;
    int s[N], c[N], ans, ze;
    ll mul[N], cal[N][N];

    void init() {
        cin >> n >> m;

        for (int i = 1; i <= n; i++) {
            char c;
            cin >> c;
            s[i] = c - '0';
            A+=s[i];
        }

        for (int i = 1; i <= n; i++) {
            cin >> c[i];
            if (c[i] == 0) ze++;
        }
        
        mul[0]=mul[1]=1;
        rep(i, 2, n) {
            mul[i] = (mul[i - 1] * i) % mod;
        }
        cal[0][0]=cal[1][0]=cal[1][1]=1;
        rep(i, 2, n) {
            cal[i][0]=cal[i][i] = 1;
            rep(j, 1, i - 1) cal[i][j] =(cal[i-1][j]+cal[i-1][j-1]) % mod;
        }

        if (m == n) {
            if (ze) cout << 0;
            else if (A < n) cout << 0;
            else {
                cout << (mul[n] % mod);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    Otaku::init();

    return 0;
}

// 16.18 finished I am sick