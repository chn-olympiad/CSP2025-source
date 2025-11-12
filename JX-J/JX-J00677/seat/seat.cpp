#include <bits/stdc++.h>
using namespace std;
int n, m, a[110];
int num;
bool cmp(int f, int g)
{
    return f > g;
}
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++)
        cin >> a[i];
    int x = a[1];
    sort(a + 1, a + n * m + 1, cmp);
    for (int i = 1; i <= n * m; i++)
        if (a[i] == x)
        {
            num = i;
            break;
        }
    if (num % n == 0)
        if ((num / n) % 2 == 1)
            cout << num / n << " " << n;
        else
            cout << num / n << " " << 1;
    else
    {
        if (((num - num % n) / n) % 2 == 0)
            cout << num / n + 1 << " " << num % n;
        else
            cout << num / n + 1 << " " << n - (num % n - 1);
    }
    return 0;
}
