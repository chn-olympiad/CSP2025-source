#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, ans = 0;
int cnt[3];
struct node
{
    int c[3], mx, delta;
    inline void dec()
    {
        delta = 0x3f3f3f3f3f3f3f3f;
        if (c[0] >= c[1] && c[0] >= c[2])
            mx = 0;
        else if (c[1] >= c[0] && c[1] >= c[2])
            mx = 1;
        else
            mx = 2;
        for (int i = 0; i < 3; i++)
        {
            if (i == mx)
                continue;
            if (delta > c[mx] - c[i])
                delta = c[mx] - c[i];
        }
    }
} a[100005];
vector <int> v;
signed main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int _;
    scanf("%lld", &_);
    while (_--)
    {
        scanf("%lld", &n);
        cnt[0] = cnt[1] = cnt[2] = 0;
        v.clear();
        ans = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld %lld %lld", &a[i].c[0], &a[i].c[1], &a[i].c[2]);
            a[i].dec();
            cnt[a[i].mx]++;
            ans += a[i].c[a[i].mx];
        }
        if (cnt[0] > n / 2 || cnt[1] > n / 2 || cnt[2] > n / 2)
        {
            int num = 0;
            if (cnt[1] > n / 2)
                num = 1;
            else if (cnt[2] > n / 2)
                num = 2;
            int cc = cnt[num] - n / 2;
            for (int i = 1; i <= n; i++)
            {
                if (a[i].mx == num)
                    v.emplace_back(a[i].delta);
            }
            stable_sort(v.begin(), v.end());
            for (int i = 0; i < cc; i++)
            {
                ans -= v[i];
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}