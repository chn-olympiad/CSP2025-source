#include <bits/stdc++.h>
using namespace std;
long long a[5005];
long long sum = 0;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++)
        cin >> a[i];
    if (n <= 20)
    {
        for (int i = 3;i <= n;i++)
        {
            for (int j = i+1;j <= n;j++)
            {
                for (int k = j+1;k <= n;k++)
                {
                    if(a[i]+a[j]+a[k] > max(max(a[i],a[j]),a[k]));
                    {
                        sum++;
                    }
                }
            }
        }
        cout << sum%998244353;
        return 0;
    }
    for (int i =3;i <= n;i++)
    {
        long long sunn = 1,sunnn = 1;;
        for (int j = n;j >= n-i;j++)
        {
            sunn  = (sunn*j) % 998244353;
        }
        for (int j = 1;j <= i;j++)
            sunnn = (sunnn*j) % 998244353;
        sum += (sunn/sunnn) %998244353;
    }
    cout << sum;
    return 0;
}
