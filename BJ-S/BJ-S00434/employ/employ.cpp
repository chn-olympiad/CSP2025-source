#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 505;
const int mod = 998244353;
#define ll long long
int p[N], c[N];
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m;
    string s;
    cin >> n >> m >> s;
    s = " " + s;
    for (int i = 1; i <= n; i++) cin >> c[i], p[i] = i;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (s[i] == '1') cnt++;
    if (cnt < m) { cout << "0" << endl; return 0; }
    cnt = 0;
    for (int i = 1; i <= n; i++)
        if (c[i] != 0) cnt++;
    if (cnt < m) { cout << "0" << endl; return 0; }
    if (n > 10) {
        ll mul = 1;
        for (int i = 1; i <= n; i++) mul = mul * i % mod;
        cout << mul << endl;
        return 0;
    }
    int ans = 0;
    do {
        int cnt = 0, num = 0;
        for (int i = 1; i <= n; i++)
            if (num >= c[p[i]] || s[i] == '0') num++;
            else cnt++;
        if (cnt >= m) ans++;
    } while (next_permutation(p + 1, p + n + 1));
    cout << ans << endl;
    return 0;
}