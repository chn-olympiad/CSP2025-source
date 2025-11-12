#include<iostream>
#define int long long
using namespace std;
signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, s;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s;
    for (int i = 1; i <= n; i++)
        cin >> s;
    int ans = 1;
    for (int i = n; i > 0; i--)
        ans = ans*i%998244353;
    cout << ans;
    return 0;
}
