#include <bits/stdc++.h>
using namespace std;
int t[10];
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    for(char i : s)
    {
        if('0' <= i && i <= '9')
        {
            t[i - '0']++;
        }
    }
    for(int i = 9; i >= 0; i--)
    {
        for(int j  =1; j <= t[i]; j++)
        {
            cout << i;
        }
    }
    return 0;
}