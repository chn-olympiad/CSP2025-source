

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define rep(i, s, t) for(int i = s; i <= t; i++)
#define per(i, s, t) for(int i = t; i >= s; i--)

const int MAXN = 1e4 + 9;
const int MAXM = 1e7 + 1e6 + 9;
const int MAXK = 2e7 + 2e4 + 9;

struct Edge {

    int from;
    int to;
    ll dis;
    int vil = 0;

    bool operator < (const Edge &e) const {
        return dis < e.dis;
    }

};

int n, m, k;
Edge e1[MAXM << 1];
int fa[MAXN];
Edge e2[MAXK];
int cnt = 0;

int Find (int cur) {

    if (fa[cur] == cur) {
        return cur;
    }

    return fa[cur] = Find(fa[cur]);

}

void Kruskal () {

    rep (i, 1, n) {
        fa[i] = i;
    }

    sort(e1 + 1, e1 + 2 * m + 1);

    rep (i, 1, 2 * m) {
        int fu = Find(e1[i].from), fv = Find(e1[i].to);

        if (fu == fv) {
            continue;
        }

        e2[++cnt] = {e1[i].from, e1[i].to, e1[i].dis};
        e2[++cnt] = {e1[i].to, e1[i].from, e1[i].dis};

        fa[fv] = fu;

        if (cnt == 2 * n - 2) {
            return;
        }
    }

}

bool build[19];
ll a[19][MAXN];
ll c[19];
ll res = 0x3f3f3f3f3f3f3f3f;

ll Kruskal2 () {

    ll ans = 0;
    int cur = 0;

    rep (i, 1, n) {
        fa[i] = i;
    }

    sort(e2 + 1, e2 + cnt + 1);

    rep (i, 1, cnt) {
        int fu = Find(e2[i].from), fv = Find(e2[i].to);

        if (fu == fv) {
            continue;
        }

        ans += e2[i].dis;
        fa[fv] = fu;
        cur++;

        if (cur == n - 1) {
            return ans;
        }
    }
    
    return 0x3f3f3f3f3f3f3f3f;

}

int main () {

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    ifstream cin("road.in");
    ofstream cout("road.out");

    cin >> n >> m >> k;

    rep (i, 1, m) {
        cin >> e1[i * 2 - 1].from >> e1[i * 2 - 1].to >> e1[i * 2 - 1].dis;

        e1[i * 2] = {e1[i * 2 - 1].to, e1[i * 2 - 1].from, e1[i * 2 - 1].dis, 0};
    }

    rep (i, 1, k) {
        cin >> c[i];

        rep (j, 1, n) {
            cin >> a[i][j];
        }
    }

    if (m <= (int) 1e5) {
        Kruskal();

        ll maxi = pow(2, k) - 1;

        rep (x, 0, maxi) {
            int cur = 1;
            int tmp = x;

            memset(build, 0, sizeof(build));

            while (tmp) {
                if (tmp & 1) {
                    build[cur] = 1;
                }

                tmp >>= 1;
                cur++;
            }

            cnt = 2 * n - 2;
            ll plus = 0;

            rep (l, 1, k) {
                if (build[l]) {
                    plus += c[l];

                    rep (i, 1, n) {
                        rep (j, 1, n) {
                            if (i != j) {
                                e2[++cnt] = {i, j, a[l][i] + a[l][j], l};
                                e2[++cnt] = {j, i, a[l][i] + a[l][j], l};
                            }
                        }
                    }
                }
            }

            res = min(res, plus + Kruskal2());
        }

        cout << res << '\n';
    }
    
    else {
        res = 0;
        m <<= 1;

        rep (l, 1, k) {
            rep (i, 1, n) {
                if (a[l][i] == 0)
                    rep (j, 1, n) {
                        if (i != j) {
                            e1[++m] = {i, j, a[l][i] + a[l][j], l};
                            e1[++m] = {j, i, a[l][i] + a[l][j], l};
                        }
                    }
            }
        }

        rep (i, 1, n) {
            fa[i] = i;
        }
        
        sort(e1 + 1, e1 + m + 1);

        rep (i, 1, m) {
            int fu = Find(e1[i].from), fv = Find(e1[i].to);

            if (fu == fv) {
                continue;
            }

            res += e1[i].dis;
            fa[fv] = fu;
            cnt++;

            if (cnt == n - 1) {
                break;
            }
        }

        rep (i, 1, k) {
            if (build[i]) {
                res += c[i];
            }
        }

        cout << res << '\n';
    }

    cin.close();
    cout.close();

    return 0;

}