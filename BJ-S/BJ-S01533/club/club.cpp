#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
typedef long long ll;
#define endl "\n"
int n;
int a[4][N];

inline ll dfs(int u, int n1, int n2, int n3, int res) {
    if (u > n) {
        return res;
    }
    ll ret = res;
    // 1
    if (n1 < n / 2 && n1 + n2 + n3 < n) {
        ret = max(ret, dfs(u + 1, n1 + 1, n2, n3, res + a[0][u]));
    }
    // 2
    if (n2 < n / 2 && n1 + n2 + n3 < n) {
        ret = max(ret, dfs(u + 1, n1, n2 + 1, n3, res + a[1][u]));
    }
    // 3
    if (n3 < n / 2 && n1 + n2 + n3 < n) {
        ret = max(ret, dfs(u + 1, n1, n2, n3 + 1, res + a[2][u]));
    }/*
    if (u == n && n1 + n2 + n3 == n) {

    }*/
    return ret;
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        bool is_all_0 = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> a[j][i];
            }
            if (a[1][i] != 0 || a[2][i] != 0) is_all_0 = 0;
        }
        if (is_all_0) {
            sort(a[0] + 1, a[0] + 1 + n, greater<int>());
            ll res = 0;
            for (int i = 1; i <= n / 2; i++) {
                res += a[0][i];
            }
            cout << res << endl;
        }
        else {
            cout << dfs(1, 0, 0, 0, 0) << endl;
        }
    }

    return 0;
}
