#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
using pi = pair<int, int>;
const int N = 505, V = 300005;
const ll mod = 998244353;
int n, m, c[N], sms;
bitset<N> s;
int dp[V][20];
void Sub1()
{
    dp[0][0] = 1;
    for(int i = 0; i < (1 << n) - 1; i++)
    {
        int popc = __builtin_popcount(i);
        for(int pre = 0; pre <= n; pre++)
        {
            for(int j = 1; j <= n; j++)
            {
                if((i >> (j - 1)) & 1) continue;
                int vst = (i | (1 << (j - 1)));
                int vpre = pre + (pre >= c[j] || s[popc + 1] == 0);
                dp[vst][vpre] += dp[i][pre];
                if(dp[vst][vpre] >= mod) dp[vst][vpre] -= mod;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= n - m; i++)
    {
        ans += dp[(1 << n) - 1][i];
        if(ans >= mod) ans -= mod;
    }
    cout << ans;
}
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        s[i] = ch - '0';
        sms += s[i];
    }
    for(int i = 1; i <= n; i++) cin >> c[i];
    if(n <= 18)
    {
        Sub1();
        return 0;
    }
    cout << 0;
    return 0;
}