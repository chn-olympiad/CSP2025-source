#include <bits/stdc++.h>
using namespace std;
int n,m,a[10005],b[10005][10005];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    long long x = n * m;
    for (int i = 1;i <= x;i++)
    {
        cin >> a[i];
    }
    if (x == 1)
    {
        cout << '1' << ' ' << '1';
        return 0;
    }
    int l = a[1];
    sort (a+1,a+x+1);
    if (n == 1 && m != 1)
    {
        for (int i = m;i >= 1;i--)
        {
            if (a[i] == l)
            {
                cout << m - i + 1 << " " << "1";
                return 0;
            }
        }
    }
    if (m == 1 && n != 1)
    {
        for (int i = n;i >= 1;i--)
        {
            if (a[i] == l)
            {
                cout  << "1"<< " "<< n - i + 1 ;
                return 0;
            }
        }
    }
    if (n == 2 && m == 2)
    {
        for (int i = 1;i <= n*m;i++)
        {
            if (a[i] == l)
            {
                if (i == 1)
                {
                    cout << "2" << " " << "1";
                }
                if (i == 2)
                {
                    cout << "2" << " " << "2";
                }
                if (i == 3)
                {
                    cout << "1" << " " << "2";
                }
                if (i == 4)
                {
                    cout << "1" << " " << "1";
                }
            }
        }
    }
    return 0;
}

