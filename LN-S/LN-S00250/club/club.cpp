#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long T, n, num, x[5], m;
struct mz
{
    long long a, b, c, cha, x, y, xa, ya;
} a[N];
bool cmp(mz a, mz b)
{
    if (a.cha != b.cha)
        return a.cha > b.cha;
    else if (a.x != b.x)
        return a.x > b.x;
    else
        return a.y > b.y;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> T;
    while (T--)
    {
        num=0;
        x[1] = x[2] = x[3] = 0;
        cin >> n;
        m = n / 2;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].a >> a[i].b >> a[i].c;
            if (a[i].a > a[i].b)
            {
                a[i].x = a[i].a;
                a[i].xa = 1;
                a[i].y = a[i].b;
                a[i].ya = 2;
            }
            else
            {
                a[i].x = a[i].b;
                a[i].xa = 2;
                a[i].y = a[i].a;
                a[i].ya = 1;
            }
            if (a[i].c > a[i].x)
            {
                a[i].y = a[i].x;
                a[i].ya = a[i].xa;
                a[i].x = a[i].c;
                a[i].xa = 3;
            }
            else if (a[i].y < a[i].c)
            {
                a[i].y = a[i].c;
                a[i].ya = 3;
            }
            a[i].cha = a[i].x - a[i].y;
        }
        sort(a + 1, a + 1 + n, cmp);
        for (int i = 1; i <= n; i++)
        {
            if (x[a[i].xa] < m)
            {
                x[a[i].xa]++;
                num += a[i].x;
            }
            else
            {
                x[a[i].ya]++;
                num += a[i].y;
            }
        }
        cout << num << '\n';
    }
    return 0;
}