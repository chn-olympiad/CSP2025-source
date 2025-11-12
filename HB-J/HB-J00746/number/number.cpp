#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s;
char c[1000005],t;
bool cmp(char a,char b)
{
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            c[++t]=s[i];
        }
    }
    sort(c+1,c+t+1,cmp);
    for(int i=1;i<=t;i++)
    {
        cout << c[i];
    }
    return 0;
}
