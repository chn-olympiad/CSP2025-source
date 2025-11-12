

#include <bits/stdc++.h>

using namespace std;

const long long mod = 998244353;
int _n, _m;
string _s;
int _c[29];
long long _f[300009][29], _res;

int main () {
    int tmp, c;

    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> _n >> _m >> _s;

    for (int i = 1; i <= _n; i++) {
        cin >> _c[i];
    }

    _f[0][0] = 1;

    for (int i = 0; i < (1 << _n) - 1; i++) {
        tmp = i;
        c = 0;

        while (tmp) {
            if (tmp & 1) {
                c++;
            }

            tmp >>= 1;
        }

        for (int j = 0; j <= _n; j++) {
            if (!_f[i][j]) {
                continue;
            }

            //cout << i << ' ' << j << ' ' << _f[i][j] << endl;

            for (int k = 1; k <= _n; k++) {
                if (!(i & (1 << (k - 1)))) {
                    if (j < _c[k] && _s[c] == '1') {
                        _f[i | (1 << (k - 1))][j] += _f[i][j];
                        _f[i | (1 << (k - 1))][j] %= mod;
                    }

                    else {
                        _f[i | (1 << (k - 1))][j + 1] += _f[i][j];
                        _f[i | (1 << (k - 1))][j + 1] %= mod;
                    }
                }
            }
        }
    }

    for (int i = 0; i <= _n - _m; i++) {
        _res += _f[(1 << _n) - 1][i];
    }

    cout << _res << endl;

    return 0;
}
