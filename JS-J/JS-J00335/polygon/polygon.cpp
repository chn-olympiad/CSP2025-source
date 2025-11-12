#include <bits/stdc++.h>
using namespace std;
const int N = 998244353;
int a[5005], f[5005], p[1000005];
int sum;
int main()
{
    //freopen("polygon.in", "r", stdin);
    //freopen("polygon.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        f[i] = a[i] + f[i-1];
    }
    if (n == 3)
    {
        if (a[3] < a[2] + a[1])
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
        return 0;
    }
    for (int i = 3; i <= n; i++)
    {
        memset(p, N, sizeof(p));
        int x = 0, b = i - 1;
        if (a[i] >= f[i - 1])
        {
            continue;
        }
        sum = (sum+1) % N;
        int P = f[i - 1] - a[i];
        for (int j = 1; j <= i - 1; j++)
        {
            if (a[j] >= P)
            {
                b = j - 1;
                break;
            }
            x++;
        }
        for (int j = 1; j <= b; j++)
        {
            for (int k = j; k <= b; k++)
            {
                if (a[k] + a[j] < P)
                {

                }
            }
        }
    }
    return 0;
}
