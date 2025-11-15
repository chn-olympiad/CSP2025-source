#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 998244353;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i=1;i<=n;i++) {
        int x;
        cin >> x;
        cnt += (x != 0);
    }
    if (cnt < m) cout << "0\n";
    else {
        int ans = 1;
        for (int i=1;i<=n;i++) ans = ans * i % M;
        cout << ans << '\n';
    }
}