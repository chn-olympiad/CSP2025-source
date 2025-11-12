#include <bits/stdc++.h>
using namespace std;
long long a[105];
pair <long long, long long> ans[105];
bool cmp(long long x, long long y)
{
    return x > y;
}
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    long long n, m; cin >> n >> m;
    for (long long i = 1; i <= n * m; i ++)
    {
        cin >> a[i];
    }
    long long x = a[1];
    sort(a + 1, a + n * m + 1, cmp);
    for (long long i = 1; i <= n * m; i ++)
    {
        if (a[i] == x)
        {
            x = i;
            break;
        }
    }
    long long cur = 0;
    for (long long j = 1; j <= m; j ++)
    {
        if (j & 1)
        {
            for (long long i = 1; i <= n; i ++)
            {
                ans[++ cur] = {j, i};
            }
        }
        else
        {
            for (long long i = n; i >= 1; i --)
            {
                ans[++ cur] = {j, i};
            }
        }
    }
    cout << ans[x].first << " " << ans[x].second;
    return 0;
}