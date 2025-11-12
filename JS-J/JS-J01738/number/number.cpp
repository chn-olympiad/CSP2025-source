#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    long long cnt = 0;
    long long l = s.size();
    long long sum = 0;
    for (int i = 0; i < l; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            a[cnt] = s[i] - '0';
            cnt++;
        }
    }
    sort(a, a + cnt);
    for (int i = cnt - 1; i >= 0; i--)
    {
        cout << a[i];
    }
    return 0;
}
