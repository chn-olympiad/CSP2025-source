#include <bits/stdc++.h>
using namespace std;
string s;
int cnt[15];
signed main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if ('0' <= s[i] && s[i] <= '9') {
            cnt[s[i] - '0']++;
        }
    }
    for (int i = 9; i >= 0; i--) {
        for (int j = 1; j <= cnt[i]; j++) {
            cout << i;
        }
    }
    cout << "\n";
    return 0;
}
