#include <bits/stdc++.h>
using namespace std;
long long num[15];
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            num[(int)s[i] - 48] ++;
        }
    }
    for (int i = 9; i >= 0; i--) {
        int len = num[i];
        for (int j = 1; j <= len ; j++) {
            cout << i;
        }
    }

    return 0;
}
