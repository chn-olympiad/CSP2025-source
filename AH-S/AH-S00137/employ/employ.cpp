#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
int m,n,ans = 1;
int c[505];
string s;

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    cin >> s;
    for (int i = 1;i <= n;i++)
        cin >> c[i];
    for (int i = 0;i <= s.length();i++)
    {
        if (s[i] == '0')
        {
            cout << 0;
            return 0;
        }
    }
    for (int i = 1;i <= n;i++)
    {
        if (c[i] == 0)
        {
            cout << 0;
            return 0;
        }
    }
    for (int i = 1;i <= n;i++)
    {
        ans = ans * i % MOD;
    }
    cout << ans;
    return 0;
}

