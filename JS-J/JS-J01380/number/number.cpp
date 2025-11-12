#include<bits/stdc++.h>
using namespace std;

int a[15];
string s;

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for (auto c: s) {
        if ('0' <= c && c <= '9') a[c-'0']++;
    }
    for (int i=9; i>=0; i--) {
        while (a[i]) a[i]--, cout << i;
    }
    return 0;
}
