#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 100005

int t, n, ans; int a[MAXN][3], d[MAXN];

signed main(){
    freopen("club.in", "r", stdin); freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (cin >> t; t; --t){
        cin >> n; for (int i(1); i<=n; ++i) for (auto j: {0, 1, 2}) cin >> a[i][j]; int ct[3] = {0, 0, 0}; ans = 0;
        for (int i(1); i<=n; ++i) d[i] = a[i][0] > max(a[i][1], a[i][2]) ? 0 : 1+(a[i][2] > a[i][1]), ++ct[d[i]], ans += a[i][d[i]];
        if (max({ct[0], ct[1], ct[2]}) <= n/2){cout << ans << '\n'; continue;} int p(ct[0] > n/2 ? 0 : 1+(ct[2] > n/2));
        vector<int> vec; for (int i(1); i<=n; ++i) if (d[i] == p) vec.push_back(a[i][d[i]]-max(a[i][(d[i]+1)%3], a[i][(d[i]+2)%3]));
        sort(vec.begin(), vec.end()); for (int i(0); i<ct[p]-n/2; ++i) ans -= vec[i]; cout << ans << '\n';
    }

    return 0;
}