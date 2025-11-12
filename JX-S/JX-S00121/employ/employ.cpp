#include <bits/stdc++.h>
using namespace std;

const int N = 505;
const int MOD = 998244353;

int n, m;
string s;
int d[N], c[N], p[N];
int ans;
long long f[N];

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    for (int i = 1; i <= n; i++)
    {
        d[i] = (s[i - 1] ^ 48);
    }
    bool flagA = true;
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == 0)
        {
            flagA = false;
            break;
        }
    }
    if (flagA)
    {
        f[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            f[i] = (f[i - 1] * i) % MOD;
        }
        cout << f[n] << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
    }
    do
    {
        int fail = 0;
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (fail >= c[p[i]])
            {
                fail++;
            }
            else if (d[i] == 0)
            {
                fail++;
            }
            else
            {
                cnt++;
            }
            if (cnt >= m)
            {
                break;
            }
            if (fail > n - m)
            {
                break;
            }
        }
        if (cnt >= m)
        {
            ans = (ans + 1) % MOD;
        }
    }
    while (next_permutation(p + 1, p + n + 1));
    cout << ans << endl;
    return 0;
}