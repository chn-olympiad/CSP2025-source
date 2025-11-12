#include <bits/stdc++.h>
using namespace std;
string s;
long long a[1100000], sum;
bool cmp(int x, int y)
{
    return x > y;
}
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if ('0' <= s[i] && s[i] <= '9')
        {
            a[sum] = s[i] - '0';
            sum++;
        }
    }
    sort(a, a + sum, cmp);
    for (int i = 0; i < sum; i++)
        cout << a[i];
    return 0;
}
