#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,sum = 0;
    int a[n+1];
    for (int  i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    cout << max(1,2,3);
    if (n == 3)
    {
        cout << "1";
    }
    else
    {
        for (int i = 1;i <= n;i++)
        {
            for (int j = i + 1;j <= n;j++)
            {
                for (int z = j + 1;z <= n;z++)
                {
                    if (a[i] + a[j] + a[z] > 2 * max(a[i],a[j],a[z]))
                    {
                        sum++;
                    }
                }
            }
        }
        for (int i = 1;i <= n;i++)
        {
            for (int j = i + 1;j <= n;j++)
            {
                for (int z = j + 1;z <= n;z++)
                {
                    for (int c = z + 1;c <= n;c++)
                    {
                        if (a[i] + a[j] + a[z] + a[c]> 2 * max(a[i],a[j],a[z],a[c]))
                        {
                            sum++;
                        }
                    }
                }
            }
        }
    }
    cout << sum;
    return 0;
}
