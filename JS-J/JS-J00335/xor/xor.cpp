#include <bits/stdc++.h>
using namespace std;
int n, k, sum;
int a[50005];
int b(int x, int y)
{
    int P = x ^ a[y];
    if (x ^ a[y] == k)
    {
        sum++;
    }
    else
    {
        b(P, y+1);
    }
    return y;
}
void f(int now)
{
    if (now > n)
    cout << 1 << endl;
    if (a[now] == k)
    {
        sum++;
        cout << sum + 1 << endl;
        f(now+1);
    }
    else
    {
        f(b(a[now], now+1) + 1);
    }
    return;
}
int main()
{
    //freopen("xor.in", "r", stdin);
    //freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        if (a[i] == k)
        {
            sum++;
            continue;
        }

    }
    cout << 1 << endl;
    cout << sum;
    return 0;
}
