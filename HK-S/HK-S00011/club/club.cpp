#include <bits/stdc++.h>
#define int long long
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

const int MAXN = 1e6 + 7;
int a[MAXN][3];

signed main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, sum = 0; cin >> n;
        vector<int> v0, v1, v2;
        for (int i = 1; i <= n; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
        for (int i = 1; i <= n; i++) {
            int mx = max(max(a[i][0], a[i][1]), a[i][2]);
            if (mx == a[i][0]) v0.push_back(i);
            else if (mx == a[i][1]) v1.push_back(i);
            else if (mx == a[i][2]) v2.push_back(i);
            sum += mx;
        }
        if (v0.size() <= n / 2 && v1.size() <= n / 2 && v2.size() <= n / 2) {
            cout << sum << '\n';
            continue;
        }
        vector<int> v; int extra = 0;
        if (v0.size() > n / 2) {
            extra = v0.size() - n / 2;
            for (int i : v0) v.push_back(min(a[i][0] - a[i][1], a[i][0] - a[i][2]));
        }
        else if (v1.size() > n / 2) {
            extra = v1.size() - n / 2;
            for (int i : v1) v.push_back(min(a[i][1] - a[i][0], a[i][1] - a[i][2]));
        }
        else if (v2.size() > n / 2) {
            extra = v2.size() - n / 2;
            for (int i : v2) v.push_back(min(a[i][2] - a[i][1], a[i][2] - a[i][0]));
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < extra; i++) sum -= v[i];
        cout << sum << '\n';
    }
}
