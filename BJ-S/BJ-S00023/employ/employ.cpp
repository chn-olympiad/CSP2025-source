#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
char s[510];
int c[510], b[510], tree[510];

int lowbit(int x)
{
    return x & -x;
}

void add(int x)
{
    while (x <= 501)
    {
        tree[x]++;
        x += lowbit(x);
    }
}

int getsum(int x)
{
    int ret = 0;
    while (x)
    {
        ret += tree[x];
        x -= lowbit(x);
    }
    return ret;
}

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &c[i]);
        b[i] = b[i - 1] + s[i] - '0';
    }
    if (b[n] < m)
    {
        cout << 0 << endl;
        return 0;
    }
    sort(c + 1, c + n + 1);
    if (n <= 10)
    {
        int sum = 0, lim = 1;
        for (int i = 1; i <= n; i++)
        {
            lim *= i;
        }
        for (int i = 1; i <= lim; i++)
        {
            int cnt = 0;
            for (int i = 1; i <= n; i++)
            {
                if (s[i] == '0' || c[i] <= cnt)
                {
                    cnt++;
                }
            }
            if (cnt + m <= n) sum++;
            next_permutation(c + 1, c + n + 1);
        }
        cout << sum << endl;
        return 0;
    }
    if (m == 1)
    {
        long long mul1 = 1, mul2 = 1;
        for (int i = 1; i <= n; i++)
        {
            mul1 = mul1 * i % MOD;
        }
        for (int i = n; i >= 1; i--)
        {
            if (i - b[c[i]] > 0) mul2 = mul2 * (n - b[c[i]] - (n - i)) % MOD;
            else mul2 = 0;
        }
        cout << (mul1 - mul2 + MOD) % MOD << endl;
        return 0;
    }
    if (m == n)
    {
        long long mul = 1;
        for (int i = 1; i >= n; i--)
        {
            if (n - b[c[i]] > i - 1) mul = mul * (n - b[c[i]] - (i - 1)) % MOD;
            else mul = 0;
        }
        cout << mul << endl;
        return 0;
    }
    cout << 0 << endl;
    return 0;
}


