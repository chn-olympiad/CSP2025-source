#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 1e6 + 10;
int _t, n;
int a[N][3];
int d[N], ct[3];
int nd;

struct node{
    int w, id;

    bool operator < (const node &x) const {
        return w < x.w;
    }
}t[N];

signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios :: sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> _t;
    while (_t--) {
        cin >> n;
        nd = n / 2;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i][0] >> a[i][1] >> a[i][2];
            int mx = -1, mxp = 0;
            for (int j = 0; j < 3; j++) {
                if (mx <= a[i][j]) mx = a[i][j], mxp = j;
            }
            d[i] = mxp, ct[mxp]++;
            // cout << mxp << ' ';
            mx = -1;
            for (int j = 0; j < 3; j++) {
                if (j != mxp) mx = max(mx, a[i][j]);
            }
            t[i] = {a[i][mxp] - mx, i};
            ans += a[i][mxp];
        }
        bool fl = 0;
        int id = 0;
        for (int i = 0; i < 3; i++) {
            if (ct[i] > nd) { fl = 1; id = i; }
        }
        if (fl) {
            sort(t + 1, t + n + 1);
            int cnt = ct[id];
            for (int i = 1; i <= n; i++) {
                // cout << t[i].w << ' ' << d[t[i].id] << ' ' << cnt << '\n';
                if (cnt <= nd) break;
                if (d[t[i].id] == id) ans -= t[i].w, cnt--; 
            }
        }
        cout << ans << '\n';
        ct[0] = ct[1] = ct[2] = 0;
    }
    return 0;
}