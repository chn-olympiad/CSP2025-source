#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int t, n, a[N][3], fl[N], d[N], cnt[4];
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) {
        cnt[1] = cnt[2] = cnt[3] = 0;
        int ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 3; j++) cin >> a[i][j];
            if (a[i][1] >= a[i][2] &&
            a[i][1] >= a[i][3]) fl[i] = 1;
            else if (a[i][2] >= a[i][3]) fl[i] = 2;
            else fl[i] = 3;
            d[i] = 0;
            for (int j = 1; j <= 3; j++)
                if (j != fl[i]) d[i] = max(d[i], a[i][j]);
            d[i] = a[i][fl[i]] - d[i];
            cnt[fl[i]]++, ans += a[i][fl[i]];
        }
        for (int i = 1; i <= 3; i++)
            if (cnt[i] > n / 2) {
                int now = cnt[i] - (n / 2);
                vector <int> v;
                for (int j = 1; j <= n; j++)
                    if (fl[j] == i) v.push_back(d[j]);
                sort(v.begin(), v.end());
                for (int i = 0; i < now; i++) ans -= v[i];
            }
        cout << ans << '\n';
    }
    return 0;
}
