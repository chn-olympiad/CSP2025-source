#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygen.out","w",stdout);
    int n,a[5003],nim = -1,ans = 0;
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
        if (a[i] > nim)
        {
            nim = a[i];
        }
    }
    for (int i = 1;i <= n;i++)
    {
        ans += a[i];
    }
    if (ans / nim <= 2)
    {
        cout << 0;
        return 0;
    }
    else if (n < 3)
    {
        cout << 0;
    }
    else if (n == 3)
    {
        cout << 1;
    }
    return 0;
}
