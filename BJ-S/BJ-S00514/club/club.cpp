

#include <bits/stdc++.h>

using namespace std;

int _n, _res;
vector<int> _m[3];

int main () {
    int T;
    int x, y, z, mx;

    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    while (T--) {
        _res = 0;
        _m[0].clear();
        _m[1].clear();
        _m[2].clear();

        cin >> _n;

        for (int i = 1; i <= _n; i++) {
            cin >> x >> y >> z;

            mx = max(x, max(y, z));
            _res += mx;

            if (x == mx) {
                _m[0].push_back(max(y - mx, z - mx));
            }

            else if (y == mx) {
                _m[1].push_back(max(x - mx, z - mx));
            }

            else {
                _m[2].push_back(max(x - mx, y - mx));
            }
        }

        if (_m[0].size() > _n / 2) {
            sort(_m[0].begin(), _m[0].end());

            for (int i = _n / 2; i < _m[0].size(); i++) {
                _res += _m[0][i];
            }
        }

        if (_m[1].size() > _n / 2) {
            sort(_m[1].begin(), _m[1].end());

            for (int i = _n / 2; i < _m[1].size(); i++) {
                _res += _m[1][i];
            }
        }

        if (_m[2].size() > _n / 2) {
            sort(_m[2].begin(), _m[2].end());

            for (int i = _n / 2; i < _m[2].size(); i++) {
                _res += _m[2][i];
            }
        }

        cout << _res << endl;
    }

    return 0;
}
