#include <bits/stdc++.h>
using namespace std;

string s;
int a[10000005];

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    int l = s.size();
    int cnt = 1;
    for (int i = 0; i <= l - 1; i ++)
    {
        if (isdigit(s[i]))
        {
            a[cnt ++] = s[i] - '0';
        }
    }
    sort(a + 1, a + cnt + 1, cmp);
    for (int i = 1; i < cnt; i ++)
    {
        cout << a[i];
    }
    return 0;
}
