#include <bits/stdc++.h>
using namespace std;

string s;
int a[15];
int i, j, k;

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for (i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            a[s[i]-'0']++;
        }
    }
    for (j = 9; j >= 0; j--)
    {
        for (k = 1; k <= a[j]; k++)
        {
            cout << j;
        }
    }
    return 0;
}
