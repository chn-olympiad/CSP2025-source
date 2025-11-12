#include <bits/stdc++.h>
using namespace std;

int n, q;
pair<string, string> s[200007], t;
string x, y, z;

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> s[i].first >> s[i].second;
    }
    for (int i = 1; i <= q; i++) {
        int num = 0;
        cin >> t.first >> t.second;
        int t_len = t.first.length();
        for (int a = 0; a < t_len; ++a) {
            for (int b = 1; b <= t_len - a; ++b) {
                for (int k = 1; k <= n; ++k) {
                    if (t.first.substr(a, b) == s[k].first) {
                        y = t.first;
                        y.replace(a,b, s[k].second);
                        if (y == t.second) num++;
                    }
                }
            }
        }
        cout << num << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
