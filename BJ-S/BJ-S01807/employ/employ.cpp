# include <iostream>
using namespace std;
char sc[566];
int s[566];
int c[566];
int n, m;
int ans = 0;
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    cin >> n >> m;
    if (n > -1)
    {
        int x;
        for (int i = 1; i <= n; i ++)
        {
            cin >> sc[i];
            s[i] = sc[i] - '0';
        }
        for (int i = 1; i <= n; i ++)
        {
            cin >> c[i];
        }
        long long ans = 1;
        int q = n;
        for (int i = 1; i <= n; i ++)
        {
            if (c[i] == 0) continue;
            ans *= q--;
            ans %= 998244353;
        }
        cout << ans;
        return 0;
    }

    return 0;
}
