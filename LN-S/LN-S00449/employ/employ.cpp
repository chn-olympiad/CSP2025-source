#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(register int i = a; i <= b; ++i)
#define rep_(i, a, b) for(register int i = a; i >= b;  --i)
typedef long long ll;
namespace Kx {
    ll n, ans;
    constexpr int mod = 998244353;
    void main() {
        freopen("employ.in", "r", stdin);
        freopen("employ.out", "w", stdout);
        cin >> n;
        ans = 1;
        rep(i, 1, n) {
            ans = ans * i % mod;
        }
        cout << ans;
        return;
    }
}
int main() {
    Kx :: main();
    return 0;
}