#include <bits/stdc++.h>
using namespace std;

int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (!isdigit(c))
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (isdigit(c))
        x *= 10, x += c - '0', c = getchar();
    return x * f;
}

void write(long long x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}

const long long mod = 998244353;

int n, m;
string s;
int a[505];
int f[505];
// int f[20][300005];
bool book[505];
vector<int> tmp;
long long res = 0;

void dfs(int x)
{
    if (n - f[x - 1] < m)
        return ;
    if (x > n)
    {
        res++;
        res %= mod;
        return ;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!book[i])
        {
            book[i] = true;
            f[x] = f[x - 1] + (s[x] == '0' or f[x - 1] >= a[i]);
            dfs(x + 1);
            book[i] = false;
        }
    }
}

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> s;
    s = ' ' + s;
    bool flag = true;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] != '1')
        {
            flag = false;
            break;
        }
    }
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (flag)
    {
        res = 1;
        for (int i = 1; i <= n; i++)
            res = res * i % mod;
    }
    else if (n <= 11)
    {
        dfs(1);
        // f[0][0] = 1;
        // for (int S = 0; S < (1 << n); S++)
        // {
        //     for (int i = (S == 0); i <= n; i++)
        //     {
        //         if (__builtin_popcount(S) < i)
        //             continue;
        //         for (int p = 1; p <= n; p++)
        //         {
        //             if (S & (1 << (p - 1)))
        //             {
        //                 auto ss = S - (1 << (p - 1));
        //                 if (i - 1 >= a[p] or s[__builtin_popcount(S) + 1] == '0')
        //                 {
        //                     if (i)
        //                         f[i][S] += f[i - 1][ss];
        //                 }
        //                 else
        //                     f[i][S] += f[i][ss];
        //             }
        //         }
        //     }
        // }
        // for (int i = 0; i <= n - m; i++)
        //     res = (res + f[i][(1 << n) - 1]) % mod;
    }
    cout << res << "\n";
}