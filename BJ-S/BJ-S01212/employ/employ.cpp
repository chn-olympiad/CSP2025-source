#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 510;
const int MOD = 998244353;
template<typename T> T mod(T x) {
    return (x % MOD + MOD) % MOD;
}
int n, m, c[maxn], f[maxn], ans;
string s;
signed main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> s;
    for(int i = 1; i <= n; i++) cin >> c[i], f[i] = i;
    do {
        int num = 0, cur = 0;
        for(int i = 1; i <= n; i++) {
            if(s[i-1] == '0' || c[f[i]] <= num) {
                num++;
            } else cur++;
            if(cur >= m) {
                ans++;
                break;
            }
        }
    } while(next_permutation(f + 1, f + n + 1));
    cout << ans << endl;
    return 0;
}