#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 505, MOD = 998244353;
int n, m, ans, a[MAXN], p[MAXN];
string s;
bool f[MAXN];
signed main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < s.size(); i++) f[i + 1] = s[i] - '0';
    if (find(f + 1, f + n + 1, 0) == f + n + 1)
    {
        ans = 1;
        for (int i = 1; i <= n; i++) ans = ans * i % MOD;
        cout << ans << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++) p[i] = i;
    do
    {
        int t = 0, k = 0;
        for (int i = 1; i <= n; i++)
        {
            if (f[i] && t < a[p[i]]) k++;
            else t++;
        }
        if (k >= m) ans = (ans + 1) % MOD;
    } while (next_permutation(p + 1, p + n + 1));
    cout << ans << endl;
    return 0;
}