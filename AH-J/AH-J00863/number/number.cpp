#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;
const int N = 1e6 + 10;
int a[N], cnt;
signed main(void) {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    for (int i = 0; i < s.size(); i ++) {
        if(isdigit(s[i])) a[++ cnt] = s[i] - '0';
    }
    sort(a + 1, a + cnt + 1);
    for (int i = cnt; i > 0; i --) {
        cout << a[i];
    }
    return 0;
}
