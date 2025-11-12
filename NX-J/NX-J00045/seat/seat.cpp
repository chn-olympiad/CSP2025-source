#include <bits/stdc++.h>
using namespace std;
int a[101];
int main()
{
    freopen("seat.in","r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n*m; i++)
    {
        cin >> a[i];
    }
    int R = a[1];//R's seat
    sort(a + 1,a + n * m +1);
    int num, b[101], sum = n * m +1;
    for (int i = 1; i <= n*m; i++)
    {
        b[i] = a[sum - i];
    }
    for (int i = 1; i <= n*m; i++)
    {
        if (b[i] == R)
        {
            num = i;
        }
    }
    int c;
    if (num / n == 0)
    {
        c = num / n;
    }
    else
    {
        c = num / n + 1;
    }
    int r;
    if (c % 2 == 0)
    {
        r = n - num % n + 1;
    }
    else
    {
        if (num % n == 0)
        {
            r = n;
        }
        else
        {
            r = num % n;
        }
    }
    cout << c << " " << r;
    return 0;
}
