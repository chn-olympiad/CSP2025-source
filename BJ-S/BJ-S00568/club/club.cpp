#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int t;

struct node
{
    long long a, b, c;
    int mx, minx;
}z[100010];

bool acmp(node x, node y)
{
    if (x.mx != 1) return false;
    if (y.mx != 1) return true;
    return x.minx < y.minx;
}

bool bcmp(node x, node y)
{
    if (x.mx != 2) return false;
    if (y.mx != 2) return true;
    return x.minx < y.minx;
}

bool ccmp(node x, node y)
{
    if (x.mx != 3) return false;
    if (y.mx != 3) return true;
    return x.minx < y.minx;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        int n, an = 0, bn = 0, cn = 0;
        long long ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> z[i].a >> z[i].b >> z[i].c;
            ans += max(z[i].a, max(z[i].b, z[i].c));
            if (z[i].a > z[i].b)
            {
                if (z[i].c > z[i].a)
                {
                    cn++;
                    z[i].mx = 3, z[i].minx = z[i].c - z[i].a;
                }
                else
                {
                    an++;
                    z[i].mx = 1, z[i].minx = z[i].a - max(z[i].b, z[i].c);
                }
            }
            else
            {
                if (z[i].c > z[i].b)
                {
                    cn++;
                    z[i].mx = 3, z[i].minx = z[i].c - z[i].b;
                }
                else
                {
                    bn++;
                    z[i].mx = 2, z[i].minx = z[i].b - max(z[i].a, z[i].c);
                }
            }
        }
        if (an > n / 2)
        {
            sort(z + 1, z + n + 1, acmp);
            for (int i = 1; n / 2 + i <= an; i++) ans -= z[i].minx;
        }
        if (bn > n / 2)
        {
            sort(z + 1, z + n + 1, bcmp);
            for (int i = 1; n / 2 + i <= bn; i++) ans -= z[i].minx;
        }
        if (cn > n / 2)
        {
            sort(z + 1, z + n + 1, ccmp);
            for (int i = 1; n / 2 + i <= cn; i++) ans -= z[i].minx;
        }
        cout << ans << endl;
    }
    return 0;
}
