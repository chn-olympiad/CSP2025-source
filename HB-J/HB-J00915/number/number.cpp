#include <bits/stdc++.h>
using namespace std;
int num[10];
string s;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    cin >> s;
    for(int i = 0;i < s.size();i++)
    {
        if(s[i] <= '9' && s[i] >= '0')
        {
            num[s[i]-'0']++;
        }
    }
    s = "";
    for(int i = 9;i >= 0;i--)
    {
        for(int j = 1;j <= num[i];j++)
        {
            s = s + char(i + '0');
        }
    }
    cout << s;
}
