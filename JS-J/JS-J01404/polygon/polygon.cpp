#include <bits/stdc++.h>
using namespace std;
int const mod = 998244353;
int n,a[5005],sum,b[5005],ans;
int main()
{
    //freopen("polygon.in","r",stdin);
    //freopen("polygon.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    if (n <= 3)
    {
        for (int i = 1;i <= n-2;i++)
        {
            for (int j = i+1;j <= n-1;j++)
            {
                for (int k = j+1;k <= n;k++)
                {
                    if (a[i] + a[j] + a[k] > 2*max(a[i],max(a[j],a[k])))
                    {
                        sum++;
                    }
                }
            }
        }
        cout << sum;
        return 0;
    }
    for (int i = n;i >= 1;i--)
    {
        sum = 0;
        for (int j = 1;j <= i;j++)
        {
            sum += j;
        }
        ans += sum * (n - i + 1);
        break;
    }
    cout << ans;
    return 0;
}
