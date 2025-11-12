#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 55;
int T, n, a[N][5], mx[N], smx[N], t[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> v[5];
        int sum = 0;
        for (int i = 1;i <= n;i++) {
            cin >> a[i][1] >> a[i][2] >> a[i][3];
            if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) {
                mx[i] = a[i][1], t[i] = 1;
                if (a[i][2] >= a[i][3]) smx[i] = a[i][2];
                else smx[i] = a[i][3];
            } else if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) {
                mx[i] = a[i][2], t[i] = 2;
                if (a[i][1] >= a[i][3]) smx[i] = a[i][1];
                else smx[i] = a[i][3];
            } else {
                mx[i] = a[i][3], t[i] = 3;
                if (a[i][2] >= a[i][1]) smx[i] = a[i][2];
                else smx[i] = a[i][1];
            }
            v[t[i]].push_back(mx[i] - smx[i]);
            sum += mx[i];
        }
        for (int i = 1;i <= 3;i++) {
            sort(v[i].begin(), v[i].end());
            if (v[i].size() > n / 2) {
                int p = v[i].size() - 1, cnt = 0;
                while (p >= 0 && cnt <= n / 2) p--, cnt++;
                for (int j = p + 1;j >= 0;j--) sum -= v[i][j];
            }
        }
        cout << sum << "\n";
    }
    return 0;
}
