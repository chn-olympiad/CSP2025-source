#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int p = 998244353;
int n,m,c[505],cnt[505];
char s[505];
bool f = 1;
long long ans;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
        cin >> s[i];
        if (s[i] == '0') f = 0;
    }
    for (int i = 1;i <= n;i++)
    {
        cin >> c[i];
        cnt[c[i]]++;
    }
    if (m == n)
    {
        if (!f || cnt[0] != 0)
        {
            cout << 0;
            return 0;
        }
        ans = 1;
        for (int i = 1;i <= n;i++)
        {
            ans = (ans * i) % p;
        }
        cout << ans;
        return 0;
    }
    if (m == 1)
    {
        ans = 1;
        for (int i = 1;i <= n;i++)
        {
            ans = (ans * i) % p;
        }
        long long ans0 = 1;
        sort(c + 1,c + n + 1);
        for (int i = 1;i <= n;i++)
        {
            ans0 = (ans0 * (n - c[i])) % p;
        }
        cout << (ans + p - ans0) % p;
        return 0;
    }
    return 0;
}
