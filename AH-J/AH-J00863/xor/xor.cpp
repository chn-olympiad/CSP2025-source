#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n, k;
int a[N];
int f[N];
int sum[N];
map <int, int> mp;
int maxn = 0;
signed main(void) {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    mp[0] = 0;
    for (int i = 1; i <= n; i ++) cin >> a[i], sum[i] = sum[i - 1] ^ a[i];
    for (int i = 1; i <= n; i ++) {
        f[i] = maxn;
        int ng = sum[i] ^ k;
        if(mp.count(ng)) {
            f[i] = max(f[i], f[mp[ng]] + 1);
        }
        mp[sum[i]] = i;
        maxn = max(maxn, f[i]);
    }
    cout << f[n] << endl;
    return 0;
}
