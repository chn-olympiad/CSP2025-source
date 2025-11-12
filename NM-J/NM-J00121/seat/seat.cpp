#include <bits/stdc++.h>
using namespace std;
int n, m, a[105];
bool cmp(int d, int b)
{
    return d > b;
}
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n * m; ++i)
        cin >> a[i];
    int p = a[1];
    sort(a + 1, a + n * m + 1, cmp);
    int h = 1;
    int l = 1;
    for (int i = 1; i <= n * m; ++i)
    {
        if (a[i] != p)
        {
            if (l % 2 == 1)
            {
                if (h != n)
                {
                    ++h;
                }
                else if (h == n)
                {
                    ++l;
                }
            }
            else
            {
                if (h != 1)
                {
                    --h;
                }
                else if (h == 1)
                {
                    ++l;
                }
            }
        }
        else if (a[i] == p)
        {
            cout << l << " " << h;
            return 0;
        }
    }
    return 0;
}
