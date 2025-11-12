#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 55;
int n, q;
string s[N][2];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    /*
    wo yao shang mi huo xing wei da shang!!!
    */
    cin >> n >> q;
    for (int i = 1;i <= n;i++) cin >> s[i][0] >> s[i][1];
    while (q--) {
        string t1, t2;
        cin >> t1 >> t2;
        if (t1.size() != t2.size()) {
            cout << "0\n";
            continue;
        }
        int len = t1.size(), sum = 0;
        for (int i = 0;i < len;i++) {
            for (int j = i;j < len;j++) {
                if (j + 1 < len && t1.substr(j + 1, len - j) != t2.substr(j + 1, len - j)) continue;
                string sub1 = t1.substr(i, j - i + 1);
                string sub2 = t2.substr(i, j - i + 1);
                for (int k = 1;k <= n;k++) {
                    if (sub1 == s[k][0] && sub2 == s[k][1]) {
                        sum++;
                    }
                }
            }
        }
        cout << sum << "\n";
    }
    return 0;
}
