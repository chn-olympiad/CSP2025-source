#include<iostream>
#include<algorithm>
using namespace std;
const int N = 5e4 + 5;
const int mod = 998244353;
int n, ans, a[N];
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    if(n < 3) cout << 0;
    for(int i = 1; i <= n - 2; i ++) {
        ans = ans % mod + i % mod;
    }
    cout << ans;
    return 0;
}
