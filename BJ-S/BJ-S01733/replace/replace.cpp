#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
string s1[1000005], s2[1000005];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> s1[i] >> s2[i];
    while (m --) {
        string x, y; cin >> x >> y;
        // cout << x << " " << y << "\n";
        int k = x.size();
        int cnt = 0;
        for (int i = 0; i < k; i ++) {
            for (int l = 1; l <= n; l ++) {
                int j = s1[l].size();
                                    if (x.substr(i, j) == s1[l] && y.substr(i, j) == s2[l]) {
                        string xx, yy;
                        xx = x.substr(0, i);
                        yy = x.substr(i + j, k - (i + j));
                        // cout << xx << " " << s1[l] << " " << yy << "\n";
                        if (xx + s2[l] + yy == y) cnt ++;
                    }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}