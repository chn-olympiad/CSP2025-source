#include <bits/stdc++.h>
using namespace std;
int n, m, cnt, ans = 1;
char s[510];
int c[510], d[510];
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        if (s[i] == 1) cnt++;
    }
    for (int i = 1; i <= n; i++) cin >> c[i];
    int l = s.length();
    if (cnt < m)
    {
        cout << 0 << endl;
        return 0;
    }
    
    for (int i = 1; i <= n; i++)
    {
        cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            if (s[j] == 0) cnt++;
            if (cnt >= c[i]) 
            {
                d[i] = j - i;
                break;
            }
            d[i] = j;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (d[i] > i - 1) ans *= d[i] - i + 1;
        else ans *= d[i];
        ans = ans % 998244353;
    }
    cout << ans;
    return 0;
}
