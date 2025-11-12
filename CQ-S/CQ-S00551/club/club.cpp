#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define debug(x) cerr << #x << ' ' << x << '\n'
using LL = long long;
constexpr int MAXN = 1e5 + 5;
int n, a[3][MAXN], tot[3], b[3][MAXN];
int main() {
    IOS;
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T; cin >> T;
    while (T--) {
        cin >> n;
        for (int t : {0, 1, 2}) tot[t] = 0;
        LL ans = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[0][i] >> a[1][i] >> a[2][i];
            int mx = 0;
            if (a[1][i] > a[mx][i]) mx = 1;
            if (a[2][i] > a[mx][i]) mx = 2;
            int cur = 0;
            for (int t : {0, 1, 2}) if (t != mx) cur = max(cur, a[t][i]);
            b[mx][++tot[mx]] = a[mx][i] - cur;
            ans += a[mx][i];
        }
        int x = -1;
        for (int t : {0, 1, 2}) if (tot[t] > n / 2) x = t;
        if (x != -1) {
            sort(b[x] + 1, b[x] + 1 + tot[x]);
            for (int i = 1; i <= tot[x] && tot[x] - i + 1 > (n >> 1); ++i) ans -= b[x][i];
        }
        cout << ans << '\n';
    }
    return 0;
}