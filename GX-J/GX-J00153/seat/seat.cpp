#include <bits/stdc++.h>
using namespace std;
bool cmp (int a, int b)
{
    return a > b;
}
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    long long a[10005];
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++)
    {
        cin >> a[i];
    }
    int ans = a[1];
    sort(a + 1, a + (n * m) + 1, cmp);
    for (int i = 1; i <= n * m; i++)
    {
        if (a[i] == ans)
        {
            if (i % (m * 2) == 0)
            {
                cout << i / (m * 2) * 2 << " " << m;
            }
            else if (i % (m * 2) > m)
            {
                cout << i / (m * 2) * 2 + 2 << " " << (i - 1) % (m * 2);
            }
            else if (i % (m * 2) <= m)
            {
                cout << i / (m * 2) * 2 + 1 << " " << i % (m * 2);
            }
        }
    }
    return 0;
}
