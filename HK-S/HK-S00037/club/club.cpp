#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pll pair<int, int>
#define vll vector<int>
#define all(x) (x).begin(), (x).end()
#define fpb push_back

struct info {
    int d[3];
};

int n, ans;
void solve() {
    cin >> n;
    info a[n + 5];
    ans = 0; vll x, y, z;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].d[0] >> a[i].d[1] >> a[i].d[2];
        if (a[i].d[0] > a[i].d[1]) {
            if (a[i].d[0] > a[i].d[2]) {
                ans += a[i].d[0];
                x.fpb(i);
            }else {
                ans += a[i].d[2];
                z.fpb(i);
            }
        }else {
            if (a[i].d[1] > a[i].d[2]) {
                ans += a[i].d[1];
                y.fpb(i);
            }else {
                ans += a[i].d[2];
                z.fpb(i);
            }
        }
    }
    vll v;
    if (x.size() > n / 2) {
        for (auto &i : x) {
            int aaa = a[i].d[0] - max(a[i].d[1], a[i].d[2]);
            v.fpb(aaa);
        }
        sort(all(v));
        for (int i = 0; i < x.size() - n / 2; i++) ans -= v[i];
    }else if (y.size() > n / 2) {
        for (auto &i : y) {
            int aaa = a[i].d[1] - max(a[i].d[0], a[i].d[2]);
            v.fpb(aaa);
        }
        sort(all(v));
        for (int i = 0; i < y.size() - n / 2; i++) ans -= v[i];
    }else if (z.size() > n / 2) {
        for (auto &i : z) {
            int aaa = a[i].d[2] - max(a[i].d[1], a[i].d[0]);
            v.fpb(aaa);
        }
        sort(all(v));
        for (int i = 0; i < z.size() - n / 2; i++) ans -= v[i];
    }
    cout << ans << '\n';
}


signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); int t1 = 1;
    cin >> t1; // remove if 1 case
    while (t1--) solve();
}