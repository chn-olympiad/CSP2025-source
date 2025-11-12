#include <bits/stdc++.h>
using namespace std;
string s;
int d[1000005],top;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for (int i=0;i<s.size();i++)
    {
        if (s[i]>='0'&&s[i]<='9')
        {
            d[top++]=s[i]-'0';
        }
    }
    sort(d,d+top);
    for (int i=top-1;i>=0;i--)
    {
        printf("%d",d[i]);
    }
    return 0;
}
