#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
struct stu
{
    long long a, b, c, ca, maxc, maxs;
} d[100005];
bool cmpa(stu a, stu b)
{
    if (a.maxc == b.maxc)
    {
        if (a.ca == b.ca)
            return a.a > b.a;
        return a.ca > b.ca;
    }
    else
        return ((b.maxc != 1) || (a.maxc == 1));
}
bool cmpb(stu a, stu b)
{
    if (a.maxc == b.maxc)
    {
        if (a.ca == b.ca)
            return a.b > b.b;
        return a.ca > b.ca;
    }
    else
        return ((b.maxc != 2) || (a.maxc == 2));
}
bool cmpc(stu a, stu b)
{
    if (a.maxc == b.maxc)
    {
        if (a.ca == b.ca)
            return a.c > b.c;
        return a.ca > b.ca;
    }
    else
        return ((b.maxc != 3) || (a.maxc == 3));
}
int T;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> T;
    while (T--)
    {
        int cnt[40] = {}, cntj[20][40] = {};
        for (int i = 1; i <= n; i++)
            d[i].a = d[i].b = d[i].c = d[i].ca = d[i].maxc = d[i].maxs = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> d[i].a >> d[i].b >> d[i].c;
        for (int i = 1; i <= n; i++)
        {
            long long maxj = max({d[i].a, d[i].b, d[i].c});
            d[i].maxs = maxj;
            if (maxj == d[i].a)
                d[i].maxc = 1, cnt[1]++, d[i].ca = (d[i].a - max(d[i].b, d[i].c)),
                cntj[1][1] += ((d[i].a == d[i].b) ? 1 : 0),
                cntj[2][1] += ((d[i].a == d[i].c) ? 1 : 0);
            else if (maxj == d[i].b)
                d[i].maxc = 2, cnt[2]++, d[i].ca = (d[i].b - max(d[i].a, d[i].c)),
                cntj[1][2] += ((d[i].b == d[i].a) ? 1 : 0),
                cntj[2][2] += ((d[i].b == d[i].c) ? 1 : 0);
            else
                d[i].maxc = 3, cnt[3]++, d[i].ca = (d[i].c - max(d[i].b, d[i].a));
        }
        long long ans = 0;

        if (!((((cnt[1] - cntj[1][1] - cntj[1][2]) <= (n / 2) && ((cntj[1][1] + cnt[2]) <= (n / 2)) && (cnt[3] + cntj[1][2]) <= (n / 2))) || cnt[1] <= n / 2))
        {
            sort(d + 1, d + n + 1, cmpa);
            for (int i = 1; i <= n / 2; i++)
                ans += d[i].a;
            for (int i = n / 2 + 1; i <= n; i++)
                ans += max(d[i].b, d[i].c);
            cout << ans << "\n";
            continue;
        }

        else if (!((((cnt[2] - cntj[2][2]) <= (n / 2)) && cnt[3] + cntj[2][2] <= n) || cnt[2] <= n / 2))
        {
            sort(d + 1, d + n + 1, cmpb);
            for (int i = 1; i <= n / 2; i++)
                ans += d[i].b;
            for (int i = n / 2 + 1; i <= n; i++)
                ans += max(d[i].a, d[i].c);
            cout << ans << "\n";
            continue;
        }
        else if (cnt[3] > n / 2)
        {
            sort(d + 1, d + n + 1, cmpc);
            for (int i = 1; i <= n / 2; i++)
                ans += d[i].c;
            for (int i = n / 2 + 1; i <= n; i++)
                ans += max(d[i].b, d[i].a);
            cout << ans << "\n";
            continue;
        }
        else
        {
            for (int i = 1; i <= n; i++)
                ans += d[i].maxs;
            cout << ans << "\n";
        }
    }
    return 0;
}