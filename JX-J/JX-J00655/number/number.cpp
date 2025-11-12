#include <bits/stdc++.h>
using namespace std;
int a[1000006];
bool cmp(int x, int y) {
    return x > y;
}
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    int k = 0;
    for (int i = 0;i < s.size();i ++) {
        if (s[i] <= '9' && s[i] >= '0') {
            a[k ++] = s[i] - '0';
        }
    }
    sort(a, a + k, cmp);
    for (int i = 0;i < k;i ++) {
        cout << a[i];
    }
    return 0;
}
