#include <bits/stdc++.h>
using namespace std;

#define EOL '\n'
#define int long long

struct Person
{
    int f, s, t, d;
    bool operator < (const Person &per) const
    {
        return d > per.d;
    }
};

Person p[100010];
int m;

int calc(int &c1, int a1, int &c2, int a2)
{
    if (c1 < m)
    {
        ++c1;
        return a1;
    }
    ++c2;
    return a2;
}

void join()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> p[i].f >> p[i].s >> p[i].t;
        int F = max(max(p[i].f, p[i].s), p[i].t), T = min(min(p[i].f, p[i].s), p[i].t), S = p[i].f + p[i].s + p[i].t - F - T;
        p[i].d = F - S;
    }
    sort(p + 1, p + n + 1);
    m = n >> 1;
    int c1 = 0, c2 = 0, c3 = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (p[i].d == 0)
        {
            ans += max(max(p[i].f, p[i].s), p[i].t);
            continue;
        }
        if (p[i].f == p[i].s)
        {
            if (c3 == m)
            {
                ans += p[i].f;
            }
            else
            {
                ++c3;
                ans += p[i].t;
            }
            continue;
        }
        if (p[i].f == p[i].t)
        {
            if (c2 == m)
            {
                ans += p[i].f;
            }
            else
            {
                ++c2;
                ans += p[i].s;
            }
            continue;
        }
        if (p[i].s == p[i].t)
        {
            if (c1 == m)
            {
                ans += p[i].s;
            }
            else
            {
                ++c1;
                ans += p[i].f;
            }
            continue;
        }
        if (p[i].f > p[i].s && p[i].s > p[i].t)
        {
            ans += calc(c1, p[i].f, c2, p[i].s);
        }
        if (p[i].f > p[i].t && p[i].t > p[i].s)
        {
            ans += calc(c1, p[i].f, c3, p[i].t);
        }
        if (p[i].s > p[i].f && p[i].f > p[i].t)
        {
            ans += calc(c2, p[i].s, c1, p[i].f);
        }
        if (p[i].s > p[i].t && p[i].t > p[i].f)
        {
            ans += calc(c2, p[i].s, c3, p[i].t);
        }
        if (p[i].t > p[i].f && p[i].f > p[i].s)
        {
            ans += calc(c3, p[i].t, c1, p[i].f);
        }
        if (p[i].t > p[i].s && p[i].s > p[i].f)
        {
            ans += calc(c3, p[i].t, c2, p[i].s);
        }
    }
    cout << ans << EOL;
}

signed main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        join();
    }
    return 0;
}
