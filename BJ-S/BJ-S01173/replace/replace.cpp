#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
string s1[N], s2[N], t1[N], t2[N];

int main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> s1[i] >> s2[i];
    for (int i = 1; i <= q; i++) cin >> t1[i] >> t2[i];
    if (n <= 100 && q <= 100) {
        for (int i = 1; i <= q; i++) {
            int m = t1[i].size();
            t1[i] = " " + t1[i];
            int ans = 0;
            for (int len = 1; len <= m; len++) {
                for (int l = 1; l + len - 1 <= m; l++) {
                    for (int j = 1; j <= n; j++) {
                        if (s1[j].size() < len) continue;
                        if (s1[j] == t1[i].substr(l, len) && t1[i].substr(1, l - 1) + s2[j] + t1[i].substr(l + len, m) == t2[i]) ans++;
                    }
                }
            }
            cout << ans << endl;
        }
        return 0;
    }
    for (int i = 1; i <= q; i++) {
        cout << (t1 == t2) << endl;
    }
  return 0;
}