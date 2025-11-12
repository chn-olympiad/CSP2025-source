#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
string s;
LL a[15];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9') a[s[i] - '0']++;
    }
    for (int i = 9; i >= 0; i--)
    {
        for (int j = 0; j < a[i]; j++) cout << i;
    }
    return 0;
}
