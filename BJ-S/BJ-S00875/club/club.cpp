# include <bits/stdc++.h>
using namespace std;
# define int long long
const int MAXN = 1e5 + 10;
int T, a[MAXN][3], n;
vector <int> vec[3];
int tmp[MAXN], tot = 0;
signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> T;
    while (T--) {
        cin >> n;
        int ans = 0;
        for (int i = 0; i < 3; i++) vec[i].clear();
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 3; j++) cin >> a[i][j];
            int id = 0;
            for (int j = 0; j < 3; j++) {
                if (a[i][j] > a[i][id]) id = j;
            }
            vec[id].push_back(i);
            ans += a[i][id];
        }
        int mx = 0;
        for (int i = 0; i < 3; i++) {
            if (vec[i].size() > vec[mx].size()) mx = i;
        }
        if (vec[mx].size() > n / 2) {
            tot = 0;
            for (int i : vec[mx]) {
                tmp[++tot] = 1e18;
                for (int j = 0; j < 3; j++) {
                    if (mx == j) continue;
                    tmp[tot] = min(tmp[tot], a[i][mx] - a[i][j]);
                }
            }
            sort(tmp + 1, tmp + tot + 1);
            for (int i = 1; i <= vec[mx].size() - n / 2; i++) ans -= tmp[i];
            cout << ans << endl ;
        } else {
            cout << ans << endl ;
        }
    }
    return 0;
}