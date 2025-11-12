

#include <bits/stdc++.h>

using namespace std;

struct edge {
    int u, v, w;

    bool operator < (const edge & _) const {
        return w < _.w;
    }
}_e[1000009], _g[10009], _a[19][10009], _tmp[200009];

int _n, _m, _k;
int _c[19];
int _f[10009];
int _cnt;
long long _res;

void Init () {
    for (int i = 1; i <= _n + _k; i++) {
        _f[i] = i;
    }
}

int Fa (int x) {
    if (_f[x] != x) {
        _f[x] = Fa(_f[x]);
    }

    return _f[x];
}

int main () {
    int u, v, w, fu, fv;
    long long ans;

    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> _n >> _m >> _k;

    for (int i = 1; i <= _m; i++) {
        cin >> _e[i].u >> _e[i].v >> _e[i].w;
    }

    for (int i = 1; i <= _k; i++) {
        cin >> _c[i];

        for (int j = 1; j <= _n; j++) {
            cin >> _a[i][j].w;

            _a[i][j].u = _n + i;
            _a[i][j].v = j;
        }
    }

    sort(_e + 1, _e + _m + 1);
    Init();
    ans = 0;

    for (int i = 1; i <= _m; i++) {
        u = _e[i].u;
        v = _e[i].v;
        w = _e[i].w;

        fu = Fa(u);
        fv = Fa(v);

        if (fu == fv) {
            continue;
        }

        ans += w;
        _cnt++;
        _g[_cnt].u = u;
        _g[_cnt].v = v;
        _g[_cnt].w = w;

        _f[fu] = fv;
    }

    _res = ans;

    for (int i = 1; i < (1 << _k); i++) {
        _cnt = 0;
        ans = 0;

        for (int j = 1; j <= _n; j++) {
            _cnt++;
            _tmp[_cnt].u = _g[j].u;
            _tmp[_cnt].v = _g[j].v;
            _tmp[_cnt].w = _g[j].w;
        }

        for (int j = 1; j <= _k; j++) {
            if ((i & (1 << (j - 1))) != 0) {
                ans += _c[j];

                for (int k = 1; k <= _n; k++) {
                    _cnt++;
                    _tmp[_cnt].u = _a[j][k].u;
                    _tmp[_cnt].v = _a[j][k].v;
                    _tmp[_cnt].w = _a[j][k].w;
                }
            }
        }

        sort(_tmp + 1, _tmp + _cnt + 1);
        Init();

        for (int i = 1; i <= _cnt; i++) {
            u = _tmp[i].u;
            v = _tmp[i].v;
            w = _tmp[i].w;

            fu = Fa(u);
            fv = Fa(v);

            if (fu == fv) {
                continue;
            }

            ans += w;
            _f[fu] = fv;
        }

        _res = min(_res, ans);
    }

    cout << _res << endl;

    return 0;
}
