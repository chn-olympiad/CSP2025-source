#include <bits/stdc++.h>
using namespace std;
int c[510];
long long C = 998244353;
int main () {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int a = 0;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
        ans *= i;
        ans = ans % C;
    }
    cout << ans;
    return 0;
}