#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int a[N], cnt = 0;
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    int len = s.size();
    for (int i = 0; i < len; i++)
    {
        if (s[i] <= '9' && s[i] >= '0')
            a[++cnt] = s[i] - '0';
    }
    sort(a + 1, a + cnt + 1);
    for (int i = cnt; i >= 1; i--)
        printf("%d", a[i]);
    printf("\n");
    return 0;
}