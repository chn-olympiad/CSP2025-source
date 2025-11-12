#include <bits/stdc++.h>
using namespace std;
int n, t, yy[300005];
bool xx[300005];
struct A
{
    int val, nxx, nyy;
} a[300005];
bool cmp(A x, A y)
{
    return x.val > y.val;
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        memset(a, 0, sizeof(a));
        memset(xx, 0, sizeof(xx));
        memset(yy, 0, sizeof(yy));
        int num = 0;
        int sum = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= 3; j++)
            {
                cin >> a[++num].val;
                a[num].nxx = i;
                a[num].nyy = j;
            }
        }
        sort(a + 1, a + num + 1, cmp);
        int cishu = 0;
        for (int i = 1; i <= num; i++)
        {
            if ((!xx[a[i].nxx]) && (yy[a[i].nyy] + 1 <= n / 2))
            {
                xx[a[i].nxx] = 1;
                yy[a[i].nyy]++;
                cishu++;
                sum += a[i].val;
            }
            if (cishu == n)
            {
                break;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
