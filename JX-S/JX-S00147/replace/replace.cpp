#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, q;
string s[N], t[N];
int main () {
    freopen ("replace.in", "r", stdin);
    freopen ("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie (0), cout.tie (0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> s[i] >> t[i];
    }
    while (q--) {
        string temp, p; cin >> temp >> p;
        int ans = 0;
        for (int y = 0; y < temp.size (); y++) {
            for (int len = 1; len + y <= temp.size (); len++) {
                string temp_t = temp.substr (y, len);
                for (int i = 1; i <= n; i++) {
                    if (temp_t == s[i]) {
                        string temp_s = temp.substr (0, y) + t[i] + temp.substr (y + len, temp.size () - y);
                        if (temp_s == p) ++ ans;
                    }
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
