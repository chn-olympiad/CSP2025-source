#include <bits/stdc++.h>
using namespace std;
const int S = 1e6 + 7;
string s;
int num[S], sum;
bool cmp (int x, int y)
{
    return x > y;
}
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            num[++sum] = s[i] - '0';
        }
    }
    sort (num + 1, num + sum + 1, cmp);
    if (num[1] == 0)
    {
        cout << 0;
        return 0;
    }
    for (int i = 1; i <= sum; i++)
    {
        cout << num[i];
    }
    return 0;
}
