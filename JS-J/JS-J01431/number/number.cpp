#include<bits/stdc++.h>
using namespace std;
bool cmp(char s,char y)
{

    return s > y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    char c;
    while(cin >> c)
    {
        if(c >= '0' && c <= '9')
        {
            s += c;
        }
    }
    sort(s.begin(),s.end(),cmp);
    cout << s;
    return 0;
}
