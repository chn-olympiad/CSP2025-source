#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

const int N = 5e3 + 10;

int n, m, c[N], s[N], p[N], ans;

signed main()
{
    if (1)
    {
        freopen("employ.in", "r", stdin);
        freopen("employ.out", "w", stdout);
    }
    cin.tie(0)->sync_with_stdio(0), cout << fixed << setprecision(10);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        char ch;
        cin >> ch;
        s[i] = ch == '1';
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> c[i], p[i] = i;
    }
    do
    {
        int cnt = 0;
        for (int _ = 1; _ <= n; ++_)
        {
            int i = p[_];
            cnt += (cnt >= c[i]) || !s[_];
        }
        if (n - cnt >= m)
        {
            ++ans;
        }
    } while (next_permutation(p + 1, p + 1 + n));
    cout << ans << '\n';
}