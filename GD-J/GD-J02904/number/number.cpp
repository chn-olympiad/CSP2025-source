#include <bits/stdc++.h>
using namespace std;
long long a[1000005], cnt;
bool cmp(long long x, long long y)
{
    return x > y;
}
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s; cin >> s;
    int n = s.size();
    for (long long i = 0; i < n; i ++)
    {
        if ('0' <= s[i] && s[i] <= '9')
        {
            a[++ cnt] = s[i] - '0';
        }
    }
    sort(a + 1, a + cnt + 1, cmp);
    if (a[1] == 0)
    {
        cout << 0;
        return 0;
    }
    for (long long i = 1; i <= cnt; i ++)
    {
        cout << a[i];
    }
    return 0;
}