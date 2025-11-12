#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;

long long a[5010];

const int MOD = 998244353;

bool is_p(int n)
{
    long long sum = 0, maxn = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += a[i];
        maxn = max(maxn, a[i]);
    }
    return (sum > 2 * maxn);
}

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if (n == 3)
    {
        if (is_p(3)) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}
