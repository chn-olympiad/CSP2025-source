#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;cin >> s;
    int a[1000005];
    bool is[1000005];
    for (int i = 0;i < s.length();i++)
    {
        if(s[i] == '0')
            a[i] = 0;
        else if(s[i] == '1')
            a[i] = 1;
        else if(s[i] == '2')
            a[i] = 2;
        else if(s[i] == '3')
            a[i] = 3;
        else if(s[i] == '4')
            a[i] = 4;
        else if(s[i] == '5')
            a[i] = 5;
        else if(s[i] == '6')
            a[i] = 6;
        else if(s[i] == '7')
            a[i] = 7;
        else if(s[i] == '8')
            a[i] = 8;
        else if(s[i] == '9')
            a[i] = 9;
        else
        {
            is[i] = false;
            continue;
        }
        is[i] = true;
    }
    for (int i = 0;i < s.length();i++)
    {
        if (is[i])
        {
            cout << a[i];
        }
    }
    return 0;
}
