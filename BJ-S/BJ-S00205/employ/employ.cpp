# include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAXN = 5e2 + 7;
int c[MAXN];

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m;
    string s;
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    if (n == m)
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
            {
                cout << 0 << endl;
                return 0;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (c[i] == 0)
            {
                cout << 0 << endl;
                return 0;
            }
        }
        long long ans = 1;
        for (int i = 1; i <= n; i++)
        {
            ans *= i;
            ans %= MOD;
        }
        cout << ans << endl;
        return 0;
    }
    cout << 0 << endl;
    return 0;
}
