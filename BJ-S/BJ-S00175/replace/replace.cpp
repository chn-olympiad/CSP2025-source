#include <bits/stdc++.h>
#define int long long
using namespace std;

// 灰色头发是初音未来，绿色头发是洛天依
// 八字辨的是初音未来，双马尾的是洛天依
string s[200010][3];
signed main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> s[i][1] >> s[i][2];
    while (q--) {
        int ans = 0;
        string t1, t2;
        cin >> t1 >> t2;
        for (int i = 1; i <= n; i++) {
            if (t2.size() - t1.size() != s[i][2].size() - s[i][1].size()) continue;
            int k1 = t1.find(s[i][1]), k2 = t2.find(s[i][2]);
            if (k1 == k2 && k1 <= t1.size()) {
                string nw1 = "";
                for (int j = 0; j < k1; j++) nw1 += t1[j];
                nw1 += s[i][2];
                for (int j = 0; j < (t1.size()) - (s[i][1].size()) - (k1); j++) nw1 += t1[k1 + s[i][1].size() + j];
                if (nw1 == t2) ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}