

#include <bits/stdc++.h>

using namespace std;

const long long p = 29, m = 1e9 + 7;
int _n, _q;
string _s1[200009], _s2[200009], _t1[200009], _t2[200009];
long long _pw[200009];
vector<long long> _hs1[200009], _hs2[200009], _ht1[200009], _ht2[200009];
int _lls[200009], _mls[200009], _rls[200009], _ls[200009], _rs[200009], _ms1[200009], _ms2[200009];

long long Hash (int op, int p, int l, int r) {
    if (r < l) {
        return 0;
    }

    if (op == 1) {
        return (_hs1[p][r] - _hs1[p][l - 1] * _pw[r - l + 1] % m + m) % m;
    }

    else if (op == 2) {
        return (_hs2[p][r] - _hs2[p][l - 1] * _pw[r - l + 1] % m + m) % m;
    }

    else if (op == 3) {
        return (_ht1[p][r] - _ht1[p][l - 1] * _pw[r - l + 1] % m + m) % m;
    }

    else {
        return (_ht2[p][r] - _ht2[p][l - 1] * _pw[r - l + 1] % m + m) % m;
    }
}

int main () {
    int c, l, r, m1, m2, ans;

    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> _n >> _q;

    for (int i = 1; i <= _n; i++) {
        cin >> _s1[i] >> _s2[i];
    }

    for (int i = 1; i <= _q; i++) {
        cin >> _t1[i] >> _t2[i];
    }

    _pw[0] = 1;

    for (int i = 1; i <= _n; i++) {
        _pw[i] = _pw[i - 1] * p % m;
    }

    for (int i = 1; i <= _n; i++) {
        l = _s1[i].size();
        _hs1[i].push_back(0);

        for (int j = 0; j < l; j++) {
            _hs1[i].push_back((_hs1[i][j] * p + _s1[i][j] - 'a' + 1) % m);
        }

        l = _s2[i].size();
        _hs2[i].push_back(0);

        for (int j = 0; j < l; j++) {
            _hs2[i].push_back((_hs2[i][j] * p + _s2[i][j] - 'a' + 1) % m);
        }

        c = _s1[i].size();
        l = 0;

        for (int j = 0; j < c; j++) {
            if (_s1[i][j] != _s2[i][j]) {
                r = j + 1;

                if (!l) {
                    l = j + 1;
                }
            }
        }

        _lls[i] = l - 1;
        _mls[i] = r - l + 1;
        _rls[i] = c - r;
        _ls[i] = Hash(1, i, 1, l - 1);
        _rs[i] = Hash(1, i, r + 1, c);
        _ms1[i] = Hash(1, i, l, r);
        _ms2[i] = Hash(2, i, l, r);

        //cerr << l << ' ' << r << ' ' << _ms1[i] << ' ' << _ms2[i] << endl;
    }

    for (int i = 1; i <= _q; i++) {
        l = _t1[i].size();
        _ht1[i].push_back(0);

        for (int j = 0; j < l; j++) {
            _ht1[i].push_back((_ht1[i][j] * p + _t1[i][j] - 'a' + 1) % m);
        }

        l = _t2[i].size();
        _ht2[i].push_back(0);

        for (int j = 0; j < l; j++) {
            _ht2[i].push_back((_ht2[i][j] * p + _t2[i][j] - 'a' + 1) % m);
        }

        if (_t1[i].size() != _t2[i].size()) {
            cout << 0 << endl;
            continue;
        }

        c = _t1[i].size();
        l = 0;

        for (int j = 0; j < c; j++) {
            if (_t1[i][j] != _t2[i][j]) {
                r = j + 1;

                if (!l) {
                    l = j + 1;
                }
            }
        }

        m1 = Hash(3, i, l, r);
        m2 = Hash(4, i, l, r);
        ans = 0;

        //cerr << l << ' ' << r << ' ' << m1 << ' ' << m2 << endl;

        for (int j = 1; j <= _n; j++) {
            if (r - l + 1 == _mls[j] && m1 == _ms1[j] && m2 == _ms2[j]) {
                if (_lls[j] <= l - 1 && _ls[j] == Hash(3, i, l - _lls[j], l - 1)) {
                    if (_rls[j] <= c - r && _rs[j] == Hash(3, i, r + 1, r + _rls[j])) {
                        ans++;
                    }
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
