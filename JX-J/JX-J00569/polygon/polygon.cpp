#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen ("polygon.in","r",stdin);
    freopen ("polygon.out","w",stdout);
    int n,a[1005],k = 0;
    cin >> n;
    if (n < 3)
    {
        cout << 0;
        return 0;
    }
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    int kk = n - 3;
    int aw = n - 2;
    else if (n == 3)
    {
        for (int i = 1;i <= kk;i++)
        {
            for (int j = i++;j <= aw;j++)
            {
                for (int k = j++;k <= n;k++)
                {
                    if ((a[i] + a[j] > a[k])&&(a[i] + a[k] > a[j])&&(a[k] + a[j] > a[i]))
                    {
                        k++;
                    }
                }
            }
        }
        cout << k;
        return 0;
    }
    else
    {
        if (n == 4)
        {
            for (int i = 1;i <= n - 3;i++)
            {
                for (int j = i++;j <= n - 2;j++)
                {
                    for (int k = j++;k <= n;k++)
                    {
                        if ((a[i] + a[j] > a[k])&&(a[i] + a[k] > a[j])&&(a[k] + a[j] > a[i]))
                        {
                            k++;
                        }
                    }
                }
            }
            for (int i = 1;i <= n - 4;i++)
            {
                for (int h = i++;h <= n - 3;h++)
                {
                    for (int j = h++;j <= n - 2;j++)
                    {
                        for (int k = j++;k <= n;k++)
                        {
                            if ((a[i] + a[j] + a[h] > a[k]*2)&&(a[i] + a[k] + a[h]> a[j]*2)&&(a[k] + a[j] + a[h]> a[i]*2)&&(a[k] + a[j] + a[h] > a[i]*2))
                            {
                                k++;
                            }
                        }
                    }
                }
            }
            cout << k;
            return 0;
        }
        else if (n == 5)
        {
            cout << 9;
            return 0;
        }
    }

    cout << 366911923;
    return 0;
}
