#include <bits/stdc++.h>
using namespace std;

int t, n;

struct node
{
    int a, b, c, maxn;
} s[100005];

bool cmp(node x, node y)
{
    return x.maxn > y.maxn;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        long long ans = 0, suma = 0, sumb = 0, sumc = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> s[i].a >> s[i].b >> s[i].c;
            s[i].maxn = max(s[i].a, max(s[i].b, s[i].c));
        }
        sort(s + 1, s + n + 1, cmp);
        for (int i = 1; i <= n; i++)
        {
            if (s[i].a == s[i].maxn)
            {
                if (suma < n * 1.0 / 2)
                {
                    ans += s[i].a;
                    suma += 1;
                }
                else
                {
                    if (s[i].b > s[i].c && sumb < n * 1.0 / 2)
                    {
                        ans += s[i].b;
                        sumb += 1;
                    }
                    else
                    {
                        ans += s[i].c;
                        sumc += 1;
                    }
                }
            }
            if (s[i].b == s[i].maxn)
            {
                if (sumb < n * 1.0 / 2)
                {
                    ans += s[i].b;
                    sumb += 1;
                }
                else
                {
                    if (s[i].a > s[i].c && suma < n * 1.0 / 2)
                    {
                        ans += s[i].a;
                        suma += 1;
                    }
                    else
                    {
                        ans += s[i].c;
                        sumc += 1;
                    }
                }
            }
            if (s[i].c == s[i].maxn)
            {
                if (sumc < n * 1.0 / 2)
                {
                    ans += s[i].c;
                    sumc += 1;
                }
                else
                {
                    if (s[i].b > s[i].a && sumb < n * 1.0 / 2)
                    {
                        ans += s[i].b;
                        sumb += 1;
                    }
                    else
                    {
                        ans += s[i].a;
                        suma += 1;
                    }
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
