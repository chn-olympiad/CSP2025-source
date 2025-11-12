#include <bits/stdc++.h>
using namespace std;
int n, m, temp, cnt;
vector<int> a;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    a.resize(n * m + 5);
    for (int i = 1; i <= n * m; ++i)
    {
        cin >> a[i];
        if (i == 1)
        {
            temp = a[i];
        }
        else
        {
            if (a[i] > temp)
            {
                ++cnt;
            }
        }
    }
    ++cnt;
    int c = cnt / n;
    if (cnt % n == 0)
    {
        if (c % 2 == 1)
        {
            cout << c << " " << n;
        }
        else
        {
            cout << c << " " << 1;
        }
    }
    else
    {
        ++c;
        if (c % 2 == 1)
        {
            cout << c << " " << cnt % n;
        }
        else
        {
            cout << c << " " << n - cnt % n + 1;
        }
    }
    return 0;
}