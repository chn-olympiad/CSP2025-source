#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1000005;
string s;
int a[N], cnt;
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if ('0' <= s[i] && s[i] <= '9')
            a[++cnt] = s[i] - '0';
    }
    sort(a + 1, a + cnt + 1);
    for (int i = cnt; i >= 1; i--)
    {
        cout << a[i];
    }
    return 0;
}
