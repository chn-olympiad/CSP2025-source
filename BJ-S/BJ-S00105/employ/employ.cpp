#include <iostream>
#include <string>
using namespace std;

const long long mod = 998244353;

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    string s;
    int n, m;
    cin >> n >> m >> s;
    bool flag = 0;
    for (int i = 1;i <= n; i++)
    {
        int x;
        cin >> x;
        if (x != 1) flag = 1;
    }
    if (!flag)
    {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1') cnt++;
            else break;
        }
        if (cnt < m)
        {
            cout << 0;
            return 0;
        }
        long long ans = 1;
        for (int i = 0; i <= cnt; i++)
        {
            ans *= (n - i);
            ans %= mod;
        }
        for (int i = 1; i <= cnt - m; i++)
        {
            ans /= i;
        }
        cout << ans;
    }
    return 0;
}
