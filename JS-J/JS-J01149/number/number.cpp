#include <bits/stdc++.h>
using namespace std;
string s,ans;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int n=s.length();
    for(int i=0;i<n;++i)
    {
        if(s[i]=='9')
        {
            ans+=s[i];
        }
    }

    for(int i=0;i<n;++i)
    {
        if(s[i]=='8')
        {
            ans+=s[i];
        }
    }
    for(int i=0;i<n;++i)
    {
        if(s[i]=='7')
        {
            ans+=s[i];
        }
    }
    for(int i=0;i<n;++i)
    {
        if(s[i]=='6')
        {
            ans+=s[i];
        }
    }
    for(int i=0;i<n;++i)
    {
        if(s[i]=='5')
        {
            ans+=s[i];
        }
    }
    for(int i=0;i<n;++i)
    {
        if(s[i]=='4')
        {
            ans+=s[i];
        }
    }
    for(int i=0;i<n;++i)
    {
        if(s[i]=='3')
        {
            ans+=s[i];
        }
    }
    for(int i=0;i<n;++i)
    {
        if(s[i]=='2')
        {
            ans+=s[i];
        }
    }
    for(int i=0;i<n;++i)
    {
        if(s[i]=='1')
        {
            ans+=s[i];
        }
    }
    for(int i=0;i<n;++i)
    {
        if(s[i]=='0')
        {
            ans+=s[i];
        }
    }

    cout<<ans;
    return 0;
}
