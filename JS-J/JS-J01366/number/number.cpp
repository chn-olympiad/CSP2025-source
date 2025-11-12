#include <bits/stdc++.h>
using namespace std;

int a[1000005], n;

bool cmp(int x, int y)
{
    return x > y;
}

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 48 && s[i] <= 57)
        {
            n++;
            a[n] = s[i] - 48;
        }
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        cout << a[i];
    }
    return 0;
}
