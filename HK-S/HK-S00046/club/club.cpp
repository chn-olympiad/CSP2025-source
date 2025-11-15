#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    int cnt[3] = {0, 0, 0};
    int a[n+1][3], sel[n+1], ans = 0;
    for (int i=1;i<=n;i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        sel[i] = max_element(a[i], a[i] + 3) - a[i];
        ans += a[i][sel[i]], cnt[sel[i]]++;
    }
    for (int j=0;j<3;j++) if (cnt[j] > n/2) {
        vector<int> vec;
        for (int i=1;i<=n;i++) if (sel[i] == j) {
            int mx = 0;
            for (int k=0;k<3;k++) if (k != j) mx = max(a[i][k], mx);
            vec.push_back(-a[i][j] + mx);
        }

        sort(vec.rbegin(), vec.rend());
        int sz = vec.size();
        for (int i=0;i<sz - n/2;i++) ans += vec[i];
    }
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) solve();
}