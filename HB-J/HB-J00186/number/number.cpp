#include <bits/stdc++.h>
using namespace std;
int book[20];
string s;
int main () {
    freopen ("number.in", "r", stdin);
    freopen ("number.out", "w", stdout);
    cin >> s;
    for (auto y : s) {
        if (isdigit(y)) {
            book[y - '0'] ++;
        }
    }
    for (char i = '9'; i >= '0'; i--) {
        int t = book[i - '0'];
        while (t --> 0)
            cout << i;
    }
    return 0;
}
