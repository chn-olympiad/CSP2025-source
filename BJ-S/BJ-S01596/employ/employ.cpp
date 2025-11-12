#include <iostream>
using namespace std;

#define int long long
const int P = 998244353;

signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin >> n >> m;
    char s[505];
    int c[505];
    for (int i = 1;i <= n;i++)
    {
        cin >> s[i];
    }
    for (int i = 1;i <= n;i++)
    {
        cin >> c[i];
    }
    if (m == n)
    {
        bool tmp = true;
        for (int i = 1;i <= n;i++)
        {
            if (c[i] == 0)
            {
                tmp = false;
                break;
            }
        }
        for (int i = 1;i <= n;i++)
        {
            if (s[i] != '1')
            {
                tmp = false;
                break;
            }
        }
        if (tmp)
        {
            int ans = n;
            for (int i = n - 1;i >= 1;i--)
            {
                ans *= i;
                ans %= P;
            }
            cout << ans << endl;
            return 0;
        }
        else
        {
            cout << 0 << endl;
            return 0;
        }
    }
    bool mark = true;
    for (int i = 1;i <= n;i++)
    {
        if (s[i] != '1')
        {
            mark = false;
            break;
        }
    }
    if (mark)
    {
        int cnt = 0;
        int num = 0;
        for (int i = 1;i <= n;i++)
        {
            if (c[i] == 0)  cnt++;
        }
        for (int i = 1;i <= n;i++)
        {
            if (c[i] > cnt)    num++;
        }
        if (num < m)
        {
            cout << 0 << endl;
            return 0;
        }
        else
        {
            int ans = n;
            for (int i = n - 1;i >= 1;i--)
            {
                ans *= i;
                ans %= P;
            }
            cout << ans << endl;
            return 0;
        }
    }
    return 0;
}
