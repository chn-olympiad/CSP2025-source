#include <iostream>
#include <algorithm>
using namespace std;
int x, y, m, num[100];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[10][10];
    cin >> x >> y;
    for (int i = 1;i <= x * y;i++)
    {
        cin >> num[i];
    }
    m = num[1];
    sort(num + 1,num + x * y + 1);
    for (int i = x * y;i >= 1;i--)
    {
        if (num[i] == m)
        {
            m = x * y - i + 1;
            break;
        }
    }
    if (m % x == 0)
    {
        cout << m / x << ' ' << x;
    }
    else
    {
        cout << m / x + 1 << ' ';
        if (m / x % 2 == 0) cout << m % x;
        else cout << y - m % x + 1;
    }
    return 0;
}
