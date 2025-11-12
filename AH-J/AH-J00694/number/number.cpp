//J00694 at here
#include <bits/stdc++.h>
#define int long long

using namespace std;

int f[10086];

signed main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string s;
    getline(cin,s);
    for(int i = 0;i < s.size();i++)
    {
        if(!('0' <= s[i] && s[i] <= '9')) continue;
        int x = s[i] - '0';
        if(0 <= x && x <= 9) f[x]++;
    }

    for(int i = 9;i >= 0;i--)
    {
        for(int j = 1;j <= f[i];j++)
        {
            cout << i;
        }
    }

    return 0;
}
/*
Oi
*/
