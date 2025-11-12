#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, a[100005][3];

void solve() {
    int ct0(0), ct1(0), rs(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j : {0, 1, 2}) cin >> a[i][j];
        if (a[i][0] >= a[i][1] && a[i][0] >= a[i][2]) ++ct0, rs += a[i][0];
        else if (a[i][1] >= a[i][0] && a[i][1] >= a[i][2]) ++ct1, rs += a[i][1];
        else rs += a[i][2];
    }
    if (ct0 > n / 2) {
        vector<int> c;
        for (int i = 1; i <= n; i++) {
            if (a[i][0] >= a[i][1] && a[i][0] >= a[i][2]) c.push_back(a[i][0] - max(a[i][1], a[i][2]));
        }
        sort(c.begin(), c.end());
        for (int i = 0; ct0 - i > n / 2; i++) {
            rs -= c[i];
        }
    } else if (ct1 > n / 2) {
        vector<int> c;
        for (int i = 1; i <= n; i++) {
            if (a[i][1] >= a[i][0] && a[i][1] >= a[i][2]) c.push_back(a[i][1] - max(a[i][0], a[i][2]));
        }
        sort(c.begin(), c.end());
        for (int i = 0; ct1 - i > n / 2; i++) {
            rs -= c[i];
        }
    } else if (n - ct0 - ct1 > n / 2) {
        vector<int> c;
        for (int i = 1; i <= n; i++) {
            if (a[i][2] >= a[i][0] && a[i][2] >= a[i][1]) c.push_back(a[i][2] - max(a[i][0], a[i][1]));
        }
        sort(c.begin(), c.end());
        for (int i = 0; n - ct0 - ct1 - i > n / 2; i++) {
            rs -= c[i];
        }
    }
    cout << rs << '\n';
}

signed main() {
#ifdef LARRIX
    freopen("sample.in", "r", stdin);
    freopen("sample.out", "w", stdout);
#else
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
/*
g++ -o club club.cpp -std=c++14 -O2 -DLARRIX ; if [ $? -eq 0 ]; then /usr/bin/time -f "%es, %MKB" ./club ; fi
*/