#include <bits/stdc++.h>
using namespace std;
string s;
char a[1000005];
int charn=0;
int cmp(char x,char y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>=48&&s[i]<=57)
        {
            a[charn]=s[i];
            charn++;
        }
    }
    sort(a,a+charn,cmp);
    for(int i=0;i<charn;i++)
    {
        cout<<a[i];
    }
    return 0;
}
