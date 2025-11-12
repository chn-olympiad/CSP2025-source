#include <bits/stdc++.h>
using namespace std;
int cnt[15];
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen ("number.in", "r", stdin);
    freopen ("number.out", "w", stdout);
    string s;
    cin >> s;
    bool all_zero = true;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            cnt[s[i] - '0']++;
            if (s[i] != '0') {
                all_zero = false;
            }
        }
    }
    if (all_zero) {
        cout << 0;
        return 0;
    }
    for (int i = 9; i >= 0; i--) {
        while (cnt[i]--) {
            cout << char(i + '0');
        }
    }
    return 0;
}
