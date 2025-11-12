#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen ("polygon.in", "r", stdin);
    freopen ("polygon.out", "w", stdout);
    int n, a[5005], sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] + a[i + n - 1] > a[i + n])
        {
            sum++;
        }
        else if (a[i] + a[i + n - 2] + a[i + n - 1] > a[i + n])
        {
            sum++;
        }
        else if (a[i] + a[i + n - 3] + a[i + n - 2] + a[i + n - 1] >a[i + n])
        {
            sum++;
        }
        else
        {
            if (a[i] + a[i + n - 1] > a[i + n])
            {
                sum++;
            }
            else if (a[i] + a[i + n - 2] + a[i + n - 1] > a[i + n])
            {
                sum++;
            }
            else if (a[i] + a[i + n - 3] + a[i + n - 2] + a[i + n - 1] >a[i + n])
            {
                sum++;
            }
            else
            {
                if (a[i] + a[i + n - 1] > a[i + n])
                {
                    sum++;
                }
                else if (a[i] + a[i + n - 2] + a[i + n - 1] > a[i + n])
                {
                    sum++;
                }
                else if (a[i] + a[i + n - 3] + a[i + n - 2] + a[i + n - 1] >a[i + n])
                {
                    sum++;
                }
            }
        }
    }
    sum = sum % 998;
    sum = sum % 244;
    sum = sum % 353;
    cout << sum;
}
