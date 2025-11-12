#include <bits/stdc++.h>
using namespace std;

char c[510];
int p[510];
long long ans = 1;

long long jie(long long n)
{
    long long ans = 1;
    for (long long i = n; i >= 1; i--)
    {
        ans = ans % (988 * 244 * 353) * i;
        ans %= (988 * 244 * 353);
    }
    return ans % (988 * 244 * 353);
}

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    long long m, n;
    bool flag = true;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        if (c[i] != '1') flag = false;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    if (flag)
    {
        cout << jie(n) << endl;
    }
    return 0;
}
