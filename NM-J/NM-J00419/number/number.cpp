#include <bits/stdc++.h>
using namespace std;
int sz[10];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    if (s.length()==1)
    {
        cout<<s;
        return 0;
    }
    for (int i=0;i<s.length();i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            int w=s[i]-'0';
            sz[w]++;
        }
    }
    for (int i=9;i>=0;i--)
    {
        while(sz[i])
        {
            cout<<i;
            sz[i]--;
        }
    }
    return 0;
}
