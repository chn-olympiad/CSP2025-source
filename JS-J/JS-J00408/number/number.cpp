#include <bits/stdc++.h>
using namespace std;
int num[10];
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string a;
    cin >> a;
    for (int i = 0; i < a.length(); i++) {
        if ('0' <= a[i] && a[i] <= '9') {
            num[a[i] - '0']++;
        }
    }
    for (int i = 9; i >= 0; i--) {
        while (num[i]--) {
            cout << i;
        }
    }
    return 0;
}