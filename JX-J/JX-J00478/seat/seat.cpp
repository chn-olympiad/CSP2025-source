#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n, m, a[101], r;
bool cmp(int x, int y)
{
    return x > y;
}
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++)
    {
        cin >> a[i];
    }
    r = a[1];
    sort(a + 1, a + n * m + 1, cmp);
    for (int i = 1; i <= n * m; i++)
    {
        if (a[i] = r)
        {
            cout << (i / n) + 1 << " " << i % n;
            return 0;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
