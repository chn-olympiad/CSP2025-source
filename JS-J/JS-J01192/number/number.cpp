#include <iostream>
#include <cstdio>
using namespace std;

int num[15];

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if ('0' <= s[i] && s[i] <= '9') num[s[i] - '0']++;
    }
    for (int i = 9; i >= 0; i--)
    {
        while (num[i])
        {
            cout << i;
            num[i]--;
        }
    }
    return 0;
}
