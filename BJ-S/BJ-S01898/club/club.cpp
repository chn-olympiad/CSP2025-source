

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define rep(i, s, t) for(int i = s; i <= t; i++)
#define per(i, s, t) for(int i = t; i >= s; i--)
#define fi first
#define se second

const int MAXN = 1e5 + 9;

struct Node {

    int x[4];
    int id1, id2, id3;
    int choose1, choose2, choose3;

};

int n;
Node a[MAXN];

pair<pair<int, int>, int> Calc (int x, int y, int z) {

    if (x <= y) {
        if (y <= z) {
            return {{1, 2}, 3};
        }

        if (x <= z) {
            return {{1, 3}, 2};
        }

        return {{3, 1}, 2};
    }

    if (y > z) {
        return {{3, 2}, 1};
    }

    if (x > z) {
        return {{2, 3}, 1};
    }

    return {{2, 1}, 3};

}

vector<Node> v[4];
int res = 0;

bool Cmp1 (Node x, Node y) {

    if (x.x[x.choose1] - x.x[x.choose2] == y.x[y.choose1] - y.x[y.choose2]) {
        return x.x[x.choose2] - x.x[x.choose3] > y.x[y.choose2] - y.x[y.choose3];
    }

    return x.x[x.choose1] - x.x[x.choose2] > y.x[y.choose1] - y.x[y.choose2];

}

void Solve () {

    v[1].clear(), v[2].clear(), v[3].clear();
    res = 0;

    cin >> n;

    rep (i, 1, n) {
        cin >> a[i].x[1] >> a[i].x[2] >> a[i].x[3];

        pair<pair<int, int>, int> cur = Calc(a[i].x[1], a[i].x[2], a[i].x[3]);

        a[i].id1 = cur.fi.fi, a[i].id2 = cur.fi.se, a[i].id3 = cur.se;
        a[i].choose1 = cur.se, a[i].choose2 = cur.fi.se, a[i].choose3 = cur.fi.fi;
        v[cur.se].push_back(a[i]);
        res += a[i].x[a[i].choose1];
    }

    while (true) {
        if (v[1].size() > n / 2) {
            sort(v[1].begin(), v[1].end(), Cmp1);

            per (i, n / 2, v[1].size() - 1) {
                Node cur = v[1][i];

                v[1].pop_back();
                res -= cur.x[cur.choose1];
                cur.choose1 = cur.choose2;
                cur.choose2 = cur.choose3;
                res += cur.x[cur.choose1];
                v[cur.choose1].push_back(cur);
            }
        }

        if (v[2].size() > n / 2) {
            sort(v[2].begin(), v[2].end(), Cmp1);

            per (i, n / 2, v[2].size() - 1) {
                Node cur = v[2][i];

                v[2].pop_back();
                res -= cur.x[cur.choose1];
                cur.choose1 = cur.choose2;
                cur.choose2 = cur.choose3;
                res += cur.x[cur.choose1];
                v[cur.choose1].push_back(cur);
            }
        }

        if (v[3].size() > n / 2) {
            sort(v[3].begin(), v[3].end(), Cmp1);

            per (i, n / 2, v[3].size() - 1) {
                Node cur = v[3][i];

                v[3].pop_back();
                res -= cur.x[cur.choose1];
                cur.choose1 = cur.choose2;
                cur.choose2 = cur.choose3;
                res += cur.x[cur.choose1];
                v[cur.choose1].push_back(cur);
            }
        }

        if (v[1].size() <= n / 2 && v[2].size() <= n / 2 && v[3].size() <= n / 2) {
            break;
        }
    }

    cout << res << '\n';

}

int main () {

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int t;

    cin >> t;

    while (t--) {
        Solve();
    }

    return 0;

}