#include <bits/stdc++.h>
using namespace std;
int t, n, sum, B, C, D;
int a[100100][5];
struct mem
{
    int num, f, s, t;
}m[100100];
mem b[100100], c[100100], d[100100];
bool cmp(mem x, mem y)
{
    return x.f - x.s > y.f - y.s;
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        sum = B = C = D = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i][1] >> a[i][2] >> a[i][3];
            m[i].num = i;
            m[i].t = min(a[i][1], min(a[i][2], a[i][3]));
            m[i].f = max(a[i][1], max(a[i][2], a[i][3]));
            m[i].s = a[i][1] + a[i][2] + a[i][3] - m[i].t - m[i].f;
        }
        for (int i = 1; i <= n; i++)
        {
            if (m[i].f == a[i][1]) B++, b[B] = m[i], sum += m[i].f;
            else if (m[i].f == a[i][2]) C++, c[C] = m[i], sum += m[i].f;
            else if (m[i].f == a[i][3]) D++, d[C] = m[i], sum += m[i].f;
        }
        if (B > n / 2)
        {
            sort (b + 1, b + B + 1, cmp);
            for (int i = n / 2 + 1; i <= B; i++) sum -= b[i].f - b[i].s;
        }
        if (C > n / 2)
        {
            sort (c + 1, c + C + 1, cmp);
            for (int i = n / 2 + 1; i <= C; i++) sum -= c[i].f - c[i].s;
        }
        if (D > n / 2)
        {
            sort (d + 1, d + D + 1, cmp);
            for (int i = n / 2 + 1; i <= D; i++) sum -= d[i].f - d[i].s;
        }
        cout << sum << endl;
    }
    return 0;
}
