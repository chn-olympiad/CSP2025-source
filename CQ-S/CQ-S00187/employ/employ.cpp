#include <bits/stdc++.h>
using namespace std;
int n, m, c[505];
long long ans;
bool a[505], flag[505];
string s;
void f(int num, int x)
{
    if (num > n)
    {
        if (x >= m)
        {
            ans++;
        }
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!flag[i])
        {
            flag[i] = 1;
            if (a[num] && num - x - 1 < c[i])
            {
                f(num + 1, x + 1);
            }
            else
            {
                f(num + 1, x);
            }
            flag[i] = 0;
        }
    }
}
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)
    {
        a[i] = s[i - 1] - '0';
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    f(1, 0);
    cout << ans;
    return 0;
}