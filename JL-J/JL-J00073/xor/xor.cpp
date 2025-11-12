#include <bits/stdc++.h>
using namespace std;

int a[1005][1005], b[1005][1005];
int n, k;

int xor(int x, int y)
{
    int z1 = 0, z2 = 0;
    while (x != 0)
    {
        z1 = 10 * z1 + (x % 2);
        z2 = 10 * z2 + (y % 2);
        x /= 2;
        y /= 2;
    }
    int sum = z1 + z2;
    sum = (string)sum;
    for (int i = 1; i <= sum.length(); i++)
    {
        if (sum[i] == 2)
        {
            sum[i] = 0;
        }
    }

    int sum2 = 0;
    for (int i = 1; i <= sum.length(); i++)
    {
        sum2 += (int)sum[i] * pow(2, i);
    }

    return sum2;
}

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        b[i] = b[i] + xor(a[i], b[i]);
    }

    int maxn = -1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (b[i] - b[j - 1] == k && i - j + 1 > maxn)
            {
                maxn = i - j + 1;
            }
        }
    }

    cout << maxn << endl;

    return 0;
}
