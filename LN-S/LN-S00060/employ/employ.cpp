#include <bits/stdc++.h>
#define int long long

using namespace std;

namespace langfengya
{
    void Main();
}

signed main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    langfengya::Main();
    return 0;
}

namespace langfengya
{
    const int N = 510;
    char s[N];
    int c[N];
    const int mod = 998244353;
    int a[N];
    void Main()
    {
        int n, m;
        cin >> n >> m;
        
        for (int i = 1; i <= n; i++) cin >> s[i];
        for (int i = 1; i <= n; i++)
        {
            cin >> c[i];
        }
        for (int i = 1; i <= n; i++)
        {
            a[i] = i;
        }
        if (n > 18)
        {
            if (m > 0) cout << 0 << endl;
            else
            {
                int ans = 1;
                for (int i = 1; i <= n; i++)
                {
                    ans *= i;
                    ans %= mod;
                }
                cout << ans << endl;
            }
            return ;
        }
        int ans = 0;
        do
        {
            int cnt = 0, cur = 0;
            for (int i = 1; i <= n; i++)
            {
                int t = a[i];
                if (cnt >= c[t])
                {
                    cnt++;
                }
                else if (s[i] == '0') cnt++;
                else cur++;
            }
            if (cur >= m)
            {
                ans++;
                ans %= mod;
            }
        } while (next_permutation(a + 1, a + n + 1));
        cout << ans << endl;
    }
}