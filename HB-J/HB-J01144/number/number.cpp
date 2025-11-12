#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    if(s.length() == 1)
    {
        cout << s;
        return 0;
    }
    for(int num = 9;num >= 0;num--)
    {
        for(int i = 0;i <= s.length()-1;i++)
        {
            if(s[i] == '0' && num == 0)
                cout << 0;
            else if(s[i] == '1' && num == 1)
                cout << 1;
            else if(s[i] == '2' && num == 2)
                cout << 2;
            else if(s[i] == '3' && num == 3)
                cout << 3;
            else if(s[i] == '4' && num == 4)
                cout << 4;
            else if(s[i] == '5' && num == 5)
                cout << 5;
            else if(s[i] == '6' && num == 6)
                cout << 6;
            else if(s[i] == '7' && num == 7)
                cout << 7;
            else if(s[i] == '8' && num == 8)
                cout << 8;
            else if(s[i] == '9' && num == 9)
                cout << 9;
        }
    }
    return 0;
}
