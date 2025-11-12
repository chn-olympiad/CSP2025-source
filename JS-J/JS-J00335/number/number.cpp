#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int f[N];
int sum = 0;
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    memset(f, 10, sizeof(f));
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 48 && s[i] <= 57)
        {
            f[i] = s[i] - '0';
            sum++;
        }
    }
    sort(f, f + s.size());
    for (int i = sum - 1; i >= 0; i--)
    {
        cout << f[i];
    }
    return 0;
}
