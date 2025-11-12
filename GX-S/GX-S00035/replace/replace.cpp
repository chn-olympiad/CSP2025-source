#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, q;
string s[3][N];
map<string, vector<string>> m;
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> s[1][i] >> s[2][i];
        m[s[1][i]].push_back(s[2][i]);
    }
    for (int _ = 1; _ <= q; _++) {
        string t1, t2;
        cin >> t1 >> t2;
        if (t1.size() != t2.size()) {
            cout << "0\n";
            continue;
        }
        int ans = 0;
        for (int i = 0; i < t1.size(); i++) {
            for (int j = i + 1; j < t1.size(); j++) {
                string x = t1.substr(0, i);
                string y = t1.substr(i, j - i + 1);
                string z = t1.substr(j + 1);
                if (!m.count(y)) continue;
                for (string &t : m[y]) {
                    string nt = x + t + z;
                    ans += nt == t2;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
