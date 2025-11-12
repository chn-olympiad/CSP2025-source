#include <bits/stdc++.h>
using namespace std;
bool cmp (int a, int b)
{
    return a > b;
}
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string n;
    cin >> n;
    char a[1000005];
    int cnt = 0;
    for (int i = 0; i < n.size(); i++)
    {
        if ('0' <= n[i] && n[i] <= '9')
        {
            a[cnt] = n[i];
            cnt++;
        }
    }
    sort(a, a + cnt, cmp);
    for (int i = 0; i < cnt; i++)
    {
        cout << a[i];
    }
    return 0;
}
