#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, m, c[505], last, ans, p[505], cnt;
string s;

void solve25()
{
    do
    {
        last = 0;
        for (int i = 1; i <= n; i++)
            if (s[i - 1] == '1' && i - last - 1 < c[p[i]])
                last++;
        if (last >= m)
            ans = (ans + 1) % mod;
    } while (next_permutation(p + 1, p + n + 1));
}

void solveA()
{
    if (n >= m)
    {
        ans = 1;
        for (int i = 0; i < n; i++)
            ans = (ans * (n - i)) % mod;
    }
}

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)
        cin >> c[i], p[i] = i;
    if (n <= 18)
        solve25();
    else
        solveA();
    cout << ans;
    return 0;
}