#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    int a[10] = {};
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            a[s[i] - '0']++;
        }
    }

    bool flag = true;
    for (int i = 9; i >= 0; i--) {
        if (flag && i == 0) {
            cout << 0;
            break;
        }
        while (a[i]) {
            flag = false;
            cout << i;
            a[i]--;
        }
    }
    return 0;
}