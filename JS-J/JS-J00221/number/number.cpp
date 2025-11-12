#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 3;
int a[N];
bool cmp (int a, int b) {
    return a > b;
}
int main () {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    memset(a, -1, sizeof(-1));
    string s;
    cin >> s;
    int l = s.size();
    int len = 0;
    for (int i = 0; i < l; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            a[len] = s[i] - '0';
            len++;
        }
    }
    sort(a, a + len, cmp);
    for (int i = 0; i < len; i++) cout << a[i];
    return 0;
}
