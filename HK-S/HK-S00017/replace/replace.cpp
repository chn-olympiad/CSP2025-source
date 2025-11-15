#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int n, q, L1, L2;
string s[N][2], t[N][2];

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> s[i][0] >> s[i][1], L1 += s[i][0].size();
    for (int i = 1; i <= q; i++) cin >> t[i][0] >> t[i][1], L2 += t[i][0].size();
    if (n <= 100 && L1 <= 100 && L2 <= 100) {
        for (int ii = 1; ii <= q; ii++) {
            string t1 = t[ii][0], t2 = t[ii][1];
            int ans = 0;
            for (int i = 0; i < t1.size(); i++) {
                string tmp = "", ts[N];
                for (int j = 1; j <= n; j++) ts[j] = t1;
                for (int j = 0; i + j < t1.size(); j++) {
                    tmp += t1[i + j];
                    for (int k = 1; k <= n; k++) {
                        ts[k][i + j] = s[k][1][j];
                        if (tmp == s[k][0] && ts[k] == t2) ans++;
                        //cout << ts[k] << " ";
                    }
                    //cout << tmp << "\n";
                }
            }
            cout << ans << "\n";
        }
    }
}