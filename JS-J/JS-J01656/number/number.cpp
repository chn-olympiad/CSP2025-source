#include <bits/stdc++.h>
using namespace std;
char a[1000005];
bool cmp(int x, int y) {
    return x > y;
}
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    int cur = 0;
    for (int i = 0; i < s.size(); i++) {
        if ('0' <= s[i] && s[i] <= '9') {
            cur++;
            a[cur] = s[i];
        }
    }
    sort(a + 1, a + cur + 1, cmp);
    if (a[1] == '0') cout << 0 << endl;
    else for (int i = 1; i <= cur; i++) cout << a[i];
    return 0;
}
