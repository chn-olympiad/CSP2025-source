#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;
string s;
char c[100005];
bool cmp(char x,char y)
{
    return x > y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    int len = s.size();
    int k = 1;
    for (int i=0;i<s.size();i++)
    {
        if (s[i]>='0'&&s[i]<='9')
        {
            c[k] = s[i];
            k++;
        }
    }
    sort(c+1,c+k+1,cmp);
    for (int i=1;i<=k;i++)
    {
        cout << c[i];
    }


    return 0;
}
