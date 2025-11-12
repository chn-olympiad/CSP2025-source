#include <bits/stdc++.h>
using namespace std;
const int N = 998244353;
int a[5005];
int main()
{
    freopen("polygon.in" , "r" , stdin);
    freopen("polygon.out" , "w" , stdout);
    int n;
    cin >> n;
    bool f = true;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] != 1)
        {
            f = false;
        }
    }
    sort(a + 1 , a + 1 + n);
    unsigned long long ans = 0;
    if (f)
    {
        ans = n;
        for (int i = 1; i < n; i++)
        {
            ans += ans * (n - i) / (i + 1);
            ans %= N;
        }
        cout << ans - n - n * (n - 1) / 2;
    }
    if (n >= 3)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                for (int k = j + 1; k <= n; k++)
                {
                    if (i + j > k)
                    {
                        ans ++;
                        ans %= N;
                    }
                }
            }
        }
    }
    else if (n >= 4)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                for (int k = j + 1; k <= n; k++)
                {
                    for (int l = k + 1; l <= n; k++)
                    {
                        if (i + j + k > l)
                        {
                            ans++;
                            ans %= N;
                        }
                    }
                }
            }
        }
    }
    else if (n >= 5)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                for (int k = j + 1; k <= n; k++)
                {
                    for (int l = k + 1; k <= n; l++)
                    {
                        for (int u = l + 1; u <= n; u++)
                        {
                            if (i + j + k + l > u)
                            {
                                ans++;
                                ans %= N;
                            }
                        }
                    }
                }
            }
        }
    }
    else if (n >= 6)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                for (int k = j + 1; k <= n; k++)
                {
                    for (int l = k + 1; l <= n; l++)
                    {
                        for (int u = l + 1; u <= n; u++)
                        {
                            for (int v = u + 1; v <= n; v++)
                            {
                                if (i + j + k + l + u > v)
                                {
                                    ans++;
                                    ans %= N;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if (n >= 7)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                for (int k = j + 1; k <= n; k++)
                {
                    for (int l = k + 1; l <= n; l++)
                    {
                        for (int u = l + 1; u <= n; u++)
                        {
                            for (int v = u + 1; v <= n; v++)
                            {
                                for (int r = v + 1; r <= n; r++)
                                {
                                    if (i + j + k + l + u + v > r)
                                    {
                                        ans++;
                                        ans %= N;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if (n >= 8)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                for (int k = j + 1; k <= n; k++)
                {
                    for (int l = k + 1; l <= n; l++)
                    {
                        for (int u = l + 1; u <= n; u++)
                        {
                            for (int v = u + 1; v <= n; v++)
                            {
                                for (int r = v + 1; r <= n; r++)
                                {
                                    for (int e = r + 1; e <= n; e++)
                                    {
                                        if (i + j + k + l + u + v + r > e)
                                        {
                                            ans++;
                                            ans %= N;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if (n >= 9)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                for (int k = j + 1; k <= n; k++)
                {
                    for (int l = k + 1; l <= n; l++)
                    {
                        for (int u = l + 1; u <= n; u++)
                        {
                            for (int v = u + 1; v <= n; v++)
                            {
                                for (int r = v + 1; r <= n; r++)
                                {
                                    for (int e = r + 1; e <= n; e++)
                                    {
                                        for (int q = e + 1; q <= n; q++)
                                        {
                                            if (i + j + k + l + u + v + r + e > q)
                                            {
                                                ans++;
                                                ans %= N;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if (n >= 10)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                for (int k = j + 1; k <= n; k++)
                {
                    for (int l = k + 1; l <= n; l++)
                    {
                        for (int u = l + 1; u <= n; u++)
                        {
                            for (int v = u + 1; v <= n; v++)
                            {
                                for (int r = v + 1; r <= n; r++)
                                {
                                    for (int e = r + 1; e <= n; e++)
                                    {
                                        for (int q = e + 1; q <= n; q++)
                                        {
                                            for (int z = q + 1; z <= n; z++)
                                            {
                                                if (i + j + k + l + u + v + r + e + q > z)
                                                {
                                                    ans++;
                                                    ans %= N;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}
