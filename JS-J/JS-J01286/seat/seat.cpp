#include <iostream>
#include <algorithm>
using namespace std;

int a[110];

bool cmp(int x, int y)
{
    return x > y;
}

int main()
{
    freopen(seat.in, 'r', stdin);
    freopen(seat.out, 'w', stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1;i <= n * m;i++)
    {
        cin >> a[i];
    }
    int R = a[1], I;
    sort(a + 1, a + n * m + 1, cmp);
    for(int i = 1;i <= n * m;i++)
    {
        if(a[i] == R)
        {
            I = i;
            break;
        }
    }
    int aa = I / (2 * n), bb = I % (2 * n);
    if(bb == 0)
    {
        cout << 2 * aa + 2 << " " << n;
    }
    if(bb <= n)
    {
        cout << 2 * aa + 1 << " " << bb;
    }
    else
    {
        cout << 2 * aa + 2 << " " << 2 * n + 1 - bb;
    }
    return 0;
}
