#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,x;
    cin>>s;
    for (int i=0;i<s.length();i++)
    {
        if ((s[i]>='0') && (s[i]<='9'))
        {
            x+=s[i];
        }
    }
    for (int i=0;i<x.length();i++)
    {
        for (int j=i+1;j<x.length();j++)
        {
            if (x[i]<=x[j])
            {
                int b=x[i];
                x[i]=x[j];
                x[j]=b;
            }
        }
    }
    for (int i=0;i<x.length();i++)
    {
        cout<<x[i];
    }
    return 0;
}
