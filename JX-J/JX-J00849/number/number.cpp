#include <bits/stdc++.h>
using namespace std;
string s;
char c[1000005];
int cnt;
bool cmp(char x, char y) {
    return x > y;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for (char i : s) {
        if (i >= '0' && i <= '9') {
            c[cnt++] = i;
        }
    }
    sort(c, c + cnt, cmp);
    for (int i = 0; i < cnt; i++) {
        cout << c[i];
    }
    return 0;
}
