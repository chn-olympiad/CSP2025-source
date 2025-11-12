#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int N = 1e6 + 10;
int a[N];
bool cmp(int x, int y) {
    return x > y;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    int n = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            a[++n] = s[i] - '0';
        }
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        cout << a[i];
    }
    return 0;
}