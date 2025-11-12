#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    int x[s.size()] = {0};
    int o = 0;
    for(int i = 0;i < s.size();i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            x[o] = s[i] - '0';
            o++;
        }
    }
    int js[10] = {0};
    for(int i = 0;i < o;i++)
        js[x[i]]++;
    for(int i = 9;i >= 0;i--)
    {
        for(int j = 0;j < js[i];j++)
            cout << i;
    }
    return 0;
}
