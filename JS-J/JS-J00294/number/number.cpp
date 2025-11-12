#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    int l = s.size();
    int x = 1;
    for (int i = 0; i < l; i++) {
        if ('0' <= s[i] && s[i] <= '9') {
            a[x++] = s[i] - '0';
        }
    }
    sort(a + 1, a + l + 1, cmp);
    for (int i = 1; i < x; i++) {
        cout << a[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
