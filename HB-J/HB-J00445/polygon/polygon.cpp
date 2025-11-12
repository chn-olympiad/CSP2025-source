#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;
ull n, a[5005], f[5005], mod = 998244353;

bool cmp(int x, int y)
{
    return x < y;
}

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    f[0] = 0;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= n; i++) f[i] = f[i - 1] + a[i];
    ull ans = 0;
    for(int i = 3; i <= n; i++)
    {
        for(int j = 1; j <= i - 2; j++)
        {
            if(f[i] - f[j - 1] > 2 * a[i])
            {
                ans++;
            }
        }
    }
    cout << ans % mod << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
