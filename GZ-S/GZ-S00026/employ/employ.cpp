// GZ-S00026 贵阳市观山湖区普瑞学校 何景睿
#include <iostream>
#include <cstring>

using namespace std;

const int max_n = 501;
const int max_m = 501;
const int mod = 998244353;

int c[max_n];

int read()
{
    int res = 0, neg = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            neg = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        res = res * 10 + (ch - '0');
        ch = getchar();
    }

    return res * neg;
}

long long A(int a, int b)
{
    long long ans = 1;
    for (int i = a; i >= a - b + 1; i--)
    {
        ans = ans * i % mod;
    }
    return ans;
}

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    int n = read(), m = read();

    string s;
    cin >> s;

    int sb = 0;
    for (int i = 1; i <= n; i++)
    {
        c[i] = read();
        if (c[i] == 0)
            sb++;
    }

    for (int i = 0; i < s.length(); i++)
        if (s[i] != '1')
        {
            cout << 0 << endl;
            return 0;
        }

    long long ans = A(n, n);

    if (m > n - sb + 1)
        cout << 0 << endl;
    else
        cout << ans << endl;

    return 0;
}
