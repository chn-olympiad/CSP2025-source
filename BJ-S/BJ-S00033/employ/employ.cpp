#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505, mod = 998244353;
int n, s[N], c[N], m, speA, p[N], ans, cnt, res;
signed main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    speA = 1;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        char x;
        cin >> x;
        s[i] = x - '0';
        if (s[i] == 0) speA = 0;
    }
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) p[i] = i;
    do
    {
        cnt = res = 0;
        for (int i = 1; i <= n; i++)
        {
            if (cnt >= c[p[i]])
            {
                cnt++;
                continue;
            }
            if (s[i] == 0) cnt++;
            else res++;
        }
        if (res >= m) ans = (ans + 1) % mod;
    }
    while (next_permutation(p + 1, p + n + 1));
    cout << ans;
    return 0;
}
