#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 10;
string s1[N], s2[N];

signed main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> s1[i] >> s2[i];

    while (q--) {
        string t1, t2;
        cin >> t1 >> t2;

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int fd = t1.find(s1[i]);
            int sn = (int)s1[i].size();
            while (fd != string::npos) {
                string t3 = t1;
                for (int j = fd, k = 0; k < sn; j++, k++) t3[j] = s2[i][k];
                fd = t1.find(s1[i], fd + 1);

                if (t2 == t3) ans++;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
