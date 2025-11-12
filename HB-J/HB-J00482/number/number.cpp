#include <bits/stdc++.h>
using namespace std;
string s;
bool cmp(int a, int b)
{
    return a > b;
}
int n, cnt, a[1000005];
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    n = s.size();
    for (int i = 0;i < n;i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            if (s[i] == '0')
                cnt++;
            else
                a[i] = s[i] - '0';
        }
    }
    sort(a, a + n, cmp);
    for (int i = 0;i < n;i++)
    {
        if (a[i] != 0)
            cout << a[i];
    }
    for (int i = 1;i <= cnt;i++)
        cout << 0;
    return 0;
}
