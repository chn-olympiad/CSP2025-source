#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
char a[N];
int num;
string s, ans;

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for (char c : s)
    {
        if (c >= '1' && c <= '9')
        {
            num++;
            a[num] = c;
        }
    }
    sort(a + 1, a + 1 + num);
    for (int i = num; i >= 1; i--)
    {
        ans += a[i];
    }
    cout << ans;
    return 0;
}
