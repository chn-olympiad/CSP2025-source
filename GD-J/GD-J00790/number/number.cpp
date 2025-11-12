#include <bits/stdc++.h>
using namespace std;
string s;
int mp[15];
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin>>s;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9')
        {
            mp[s[i] - '0']++;
        }
    }
    for(int i = 9; i >= 0; i--)
    {
        for(int j = 0; j < mp[i]; j++)
        {
            cout<<i;
        }
    }
    return 0;
}
