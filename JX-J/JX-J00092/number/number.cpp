#include <bits/stdc++.h>
using namespace std;

int main () {

    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size(), cnts[10] = {};
    for (char ch : s) {
        if (ch >= '0' && ch <= '9') cnts[ch - '0']++;
    }
    for (int i = 9; ~i; i--) {
        for (int j = 0; j < cnts[i]; j++) {
            cout << i;
        }
    }
    return 0;
}
