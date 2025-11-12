#include <bits/stdc++.h>
using namespace std;

int jsq[205];

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++)
    {
        if('0' <= s[i] <= '9')
        {
            jsq[int(s[i])]++;
        }
    }
    for(int i = int('9'); i >= int('0'); i--)
    {
        for(int j = 1; j <= jsq[i]; j++)
        {
            cout << char(i);
        }
    }
    return 0;
}


