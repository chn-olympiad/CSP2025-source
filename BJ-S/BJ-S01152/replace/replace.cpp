#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;

string s[N][2];

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> s[i][1] >> s[i][2];
    while (q--) {
        string t1, t2;
        cin >> t1 >> t2;
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            
            for (int j = 0; j < t1.size() - s[i][1].size() + 1; ++j) {
                string g1 = t1, g2 = t2;
                string tmp = g1.substr(j, s[i][1].size());
                if (tmp == s[i][1]) {
                    int cur = 0;
                    for (int k = j; k <= j + s[i][1].size() - 1; ++k)
                        g1[k] = s[i][2][cur++];
                    if (g1 == g2) ans++;
                }
                
                
            }
            
            
        }
        cout << ans << endl;
    }
    return 0;
}