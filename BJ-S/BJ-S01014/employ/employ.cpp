#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
bool s[510];
int c[510];
int order[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
long long C[510] = {0, 1};
void init()
{
    for (int i = 2; i <= 501; ++i)
    {
        C[i] = C[i - 1] * i % mod;
    }
}
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    init();
    bool flagA = true, flagB = true;
    string t;
    cin >> t;
    int cnt1 = 0;
    for (int i = 1; i <= n; ++i)
    {
        s[i] = int(t[i - 1] - '0');
        if (!s[i]) flagA = false;
        else flagB = false, ++cnt1;
    }
    for (int i = 1; i <= n; ++i) cin >> c[i];
    if (cnt1 < m)
    {
        cout << 0;
        return 0;
    }
    if (flagB)
    {
        cout << 0;
        return 0;
    }
    if (flagA)
    {
        int cntc = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (!c[i])
            {
                ++cntc;
            }
        }
        if (cntc == 0) cout << C[n];
        else cout << C[n - cntc];
        return 0;

    }
    if (m == 1)
    {
        long long sum = C[n];
    }
    if (m == n)
    {
        cout << 0;
        return 0;
    }
    if (n <= 10)
    {
        long long ans = 0;
        do
        {
            int luyong = 0, jujue = 0;
            for (int i = 1; i <= n; ++i)
            {
                if (jujue >= c[order[i]])
                {
                    ++jujue;
                    continue;
                }
                if (s[i]) ++luyong;
                else ++jujue;
            }
            if (luyong >= m)
            {
                ++ans;
                ans %= mod;
            }
        }while (next_permutation(order + 1, order + n + 1));
        cout << ans;
    }
    return 0;
}
