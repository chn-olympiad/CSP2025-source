#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,sum = 0;
    cin >> n;
    int a[n + 1];
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for (int i = 3;i <= n;i++)
    {

        for (int j = 0;j <= n - i + 1;j++)
        {
            int num = 0;
            for (int z = j + 1;z <= i + j;z++)
            {
                num += a[z];
            }
            if (num > a[i + j] * 2)
            {
                sum++;
            }
        }
    }
    cout << sum + 1;
    return 0;
}
