#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
string s;
int n[1000005],t;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","W",stdout);
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            n[i]=s[i]-'0';
            t++;
        }

    }
    sort(n,n+s.size(),cmp);
    for(int i=0;i<t;i++)
        cout<<n[i];
    return 0;
}
