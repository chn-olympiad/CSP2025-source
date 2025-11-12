#include <bits/stdc++.h>
using namespace std;
#define int long long
const int Nc = 5e2 + 5;
int n, m, a[Nc], c[Nc];
string s;
signed main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s; s = ' ' + s;
    bool subtask1 = 1;
    for (int i = 1; i < (int)s.size(); i++)
        if (s[i] != '1') subtask1 = 0;
    if (subtask1)
    {
        long long x = 1;
        for (long long i = 1; i <= n; i++) x = x * i % 998244353ll;
        cout << x << "\n";
    }
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) c[i] = i;
    int ans = 0;
    do
    {
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i - 1 - cnt >= a[c[i]] || s[i] == '0') continue;
            cnt++; if (cnt >= m) break;
        }
        if (cnt >= m) ans++;
    }while (next_permutation(c + 1, c + n + 1));
    cout << ans << "\n";
    return 0;
}
