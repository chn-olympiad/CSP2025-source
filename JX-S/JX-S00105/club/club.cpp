#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t, n;
    cin >> t >> n;
    for(int i = 1; i <= t; i++)
    {
        int a[100005][5], b = 0, c = 0, d = 0, sum = 0;
        for(int j = 1; j <= n; j++)
        {
            for(int k = 1; k <= 3; k++)
            {
                cin >> a[j][k];
            }
        }
        for(int j = 1; j <= n; j++)
        {
            int n = a[j][1];
            if(a[j][1] <= a[j][2] && a[j][2] >= a[j][3])
            {
                n = a[j][2];
                sum += a[j][2];
                c++;
            }
            if(a[j][1] <= a[j][3] && a[j][2] <= a[j][3])
            {
                n = a[j][3];
                sum += a[j][3];
                d++;
            }
            if(a[j][1] >= a[j][2] && a[j][1] >= a[j][3])
            {
                n = a[j][1];
                sum += a[j][1];
                b++;
            }
        }
        if(c <= n / 2 && d <= n / 2 && b <= n / 2)
        {
            cout << sum << endl;
        }
        else
        {
            int e[10000], f[10000], g[10000], o[10000], p[10000],q[10000];
            for(int j = 1; j <= n; j++)
            {
                int h = 0, m = 0, l = 0;
                for(int k = 1; k <= 3; k++)
                {
                    e[k] += a[j][k];
                    f[k] += a[j][k];
                    g[k] += a[j][k];
                }
            }
            sort(e, e + 3 * n + 1);
            sort(f, f + 3 * n + 1);
            sort(g, g + 3 * n + 1);
            b = 0;
            c = 0;
            d = 0;
            for(int j = 3 * n - 1; j >= 1; j--)
            {
                o[j] = e[b];
                f[j] = f[c];
                q[j] = g[d];
            }
            int r = o[0];
            r = max(r, f[0]);
            r = max(r, q[0]);
            if(r == 0)
            {
                cout << sum << endl;
            }
            else
            {
                cout << r << endl;
            }
        }
    }
    return 0;
}
