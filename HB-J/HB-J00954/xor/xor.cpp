#include <bits/stdc++.h>
// #define int long long
#define loop(i, a, b) for(int i = (a) ; i <= (int)(b) ; i++)
#define rloop(i, a, b) for(int i = (b) ; i >= (int)(a) ; i--)
#define chkmin(a, b) (a = min(a, b))
#define chkmax(a, b) (a = max(a, b))
using namespace std;
const int N = 5e5 + 5;
const int A = 1 << 20;
int n, k, a[N], dp[N], lst[A];
void solve() {
    cin >> n >> k;
    memset(lst, 0xff, sizeof(lst));
    lst[0] = 0;
    loop(i, 1, n) {
        cin >> a[i], a[i] ^= a[i - 1];
        int x = lst[a[i] ^ k];
        chkmax(dp[i], dp[i - 1]);
        if(x != -1) chkmax(dp[i], dp[x] + 1);
        lst[a[i]] = i;
    }
    cout << dp[n] << '\n';
}
signed main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    // int t; cin >> t; while(t--)
    solve();
    return 0;
}