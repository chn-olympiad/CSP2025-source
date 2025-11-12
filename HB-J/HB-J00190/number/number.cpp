#include <bits/stdc++.h>
using namespace std;
string s,ans;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int j=1;j<=s.length();j++)
    {
        if(s[j]=='9')
        {
            s+=s[j];
        }
    }
    for(int j=1;j<=s.length();j++)
    {
        if(s[j]=='8')
        {
            s+=s[j];
        }
    }
    for(int j=1;j<=s.length();j++)
    {
        if(s[j]=='7')
        {
            s+=s[j];
        }
    }
    for(int j=1;j<=s.length();j++)
    {
        if(s[j]=='6')
        {
            s+=s[j];
        }
    }
    for(int j=1;j<=s.length();j++)
    {
        if(s[j]=='5')
        {
            s+=s[j];
        }
    }
    for(int j=1;j<=s.length();j++)
    {
        if(s[j]=='4')
        {
            s+=s[j];
        }
    }
    for(int j=1;j<=s.length();j++)
    {
        if(s[j]=='3')
        {
            s+=s[j];
        }
    }
    for(int j=1;j<=s.length();j++)
    {
        if(s[j]=='2')
        {
            s+=s[j];
        }
    }
    for(int j=1;j<=s.length();j++)
    {
        if(s[j]=='1')
        {
            s+=s[j];
        }
    }
    for(int j=1;j<=s.length();j++)
    {
        if(s[j]=='0')
        {
            s+=s[j];
        }
    }
    cout<<s;
    return 0;
}
