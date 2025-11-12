#include <bits/stdc++.h>
using namespace std;

int t[15];
string s;

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    int len = s.size(), flag = 0;
    for (int i = 0; i < len; ++i) {
        if (isdigit(s[i])) {
            t[s[i] - '0']++;
            if (s[i] != '0') flag = 1;
        }
    }
    if (!flag) {
        cout << 0;
        return 0;
    }
    for (int i = 9; i >= 0; --i) {
        for (int j = 1; j <= t[i]; ++j) {
            cout << i;
        }
    }
    return 0;
}
