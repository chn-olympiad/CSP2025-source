#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define dep(i, a, b) for (int i = (a); i >= (b); i--)
#define il inline
using namespace std;
using ll = long long;
int n, m, a[105], jv[105][105];
il bool cmp(int a, int b) {
    return a > b;
}
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int len = n * m;
    rep(i, 1, len) cin >> a[i];
    int cnt = 1, pos = a[1], idx = 0;
    sort (a + 1, a + len + 1, cmp);
    rep(i, 1, m) {
        if (cnt % 2 == 1) {
            rep(j, 1, n) {
                jv[cnt][j] = a[++idx];
            }
        } else {
            dep(j, n, 1) {
                jv[cnt][j] = a[++idx];
            }
        }
        cnt++;
    }
    rep(i, 1, n) {
        rep(j, 1, m) {
            if (jv[i][j] == pos) {
                cout << i << " " << j << endl;
            }
        }
    }
    return 0;
}
/*
2 2
99 100 97 98
*/
