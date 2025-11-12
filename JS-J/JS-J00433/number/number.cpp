#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    int num = 0, b[1000003];
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            ++num;
            char a = s[i] - 48;
            b[num] = a;
        }
    }
    sort (b + 1, b + num + 1);
    for (int i = num; i > 0; --i) {
        cout << b[i];
    }
    return 0;
}
