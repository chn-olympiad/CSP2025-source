#include <bits/stdc++.h>
using namespace std;
string s;
int num[1000001], c;
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {

        if (int(s[i] <= 57 && int(s[i]) >= 48))
        {

            num[c] = s[i] - 48;

            c += 1;
        }
    }
    sort(num, num + c);
    for (int i = c - 1; i >= 0; i--)
    {
        cout << num[i];
    }
    return 0;
}