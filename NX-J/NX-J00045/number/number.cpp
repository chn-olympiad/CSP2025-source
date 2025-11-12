#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string x;
    cin >> x;
    long a[x.length()], num = 0;
    for (long i = 0; i < x.length(); i++)
    {
        if ((x[i] >= '0') && (x[i] <= '9'))
        {
            num++;
            if (x[i] == '0')
            {
                a[num] = 0;
            }
            else if (x[i] == '1')
            {
                a[num] = 1;
            }
            else if (x[i] == '2')
            {
                a[num] = 2;
            }
            else if (x[i] == '3')
            {
                a[num] = 3;
            }
            else if (x[i] == '4')
            {
                a[num] = 4;
            }
            else if (x[i] == '5')
            {
                a[num] = 5;
            }
            else if (x[i] == '6')
            {
                a[num] = 6;
            }
            else if (x[i] == '7')
            {
                a[num] = 7;
            }
            else if (x[i] == '8')
            {
                a[num] = 8;
            }
            else if (x[i] == '9')
            {
                a[num] = 9;
            }
        }
    }
    sort(a + 1, a + num + 1);
    sort(a + 1, a + num + 1);
    sort(a + 1, a + num + 1);
    sort(a + 1, a + num + 1);
    sort(a + 1, a + num + 1);
    sort(a + 1, a + num + 1);
    sort(a + 1, a + num + 1);
    sort(a + 1, a + num + 1);
    for (long i = num; i >= 1; i--)
    {
        cout << a[i];
    }
    return 0;
}
