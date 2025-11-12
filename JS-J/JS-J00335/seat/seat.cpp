#include <bits/stdc++.h>
using namespace std;
int f[105];
int R, num;
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++)
    {
        int x;
        cin >> x;
        if (i == 1)
        {
            R = x;
        }
        f[i] = x;
    }
    sort(f + 1, f + n * m + 1);
    for (int i = 1; i <= n * m; i++)
    {
        if (f[i] == R)
        {
            num = i;
            break;
        }
    }
    num = n * m - num + 1;
    int P = 0;
    while(1)
    {
        if (num <= n)
        {
            cout << P + 1 << " ";
            if (P % 2 == 0)
            {
                cout << num;
            }
            else
            {
                cout << n - num + 1;
            }
            break;
        }
        else
        {
            num -= n;
            P++;
        }
    }
    return 0;
}
