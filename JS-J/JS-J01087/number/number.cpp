#include <bits/stdc++.h>
using namespace std;
string s, t;
signed main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            t += s[i];
        }
    }
    sort(t.begin(), t.end());
    reverse(t.begin(), t.end());
    cout << t;
    return 0;
}
