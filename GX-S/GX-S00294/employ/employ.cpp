#include <bits/stdc++.h>
using namespace std;
int n,m,c[505],ans=1,sum=1;
long long mod = 998244353;
char s[505];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    cin >> s;
    int aa = n;
    int bb = n;
    for (int i = 1;i <= n;i++)
    {
         cin >> c[i];
         if (c[i] == 0)
         {
             aa--;
         }
    }
    for (int i = aa;i >= 1;i--)
    {
        ans *= aa%mod;
    }
    if (m == n)
    {
        cout << 0;
        return 0;
    }
    if (m == 1)
    {
        for (int i = 0;i < n;i++)
        {
            int y = 0;
            if (s[i] == '0' || c[i] == 0 || y >= c[i])
            {
                y++;
            }
            else
            {
                sum*=bb%mod;
            }
            bb--;
        }
        cout << sum;
        return 0;
    }
    cout << ans;
    return 0;
 }
