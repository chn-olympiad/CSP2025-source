#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string n[10001];
    string s;
    cin>>s;

    for (int i=0;i<=s.length();i++)
    {
        if ((s[i]=='0') || (s[i]=='1')||(s[i]=='2')||(s[i]=='3')||(s[i]=='4')||(s[i]=='5')||(s[i]=='6')||(s[i]=='7')||(s[i]=='8')||(s[i]=='9')||(s[i]=='0'))
        {
            n[i]=s[i];
        }

    }
    string x;
    for (int j=0;j<=s.length();j++)
    {
        for (int i=0;i<=s.length();i++)
        {
            if (n[i]<=n[i+1])
            {
                x=n[i];
                n[i]=n[i+1];
                n[i+1]=x;
            }
        }
    }
    for (int i=0;i<=s.length();i++)
    {
        cout<<n[i];
    }
    return 0;
}
