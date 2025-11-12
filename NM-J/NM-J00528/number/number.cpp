#include <bits/stdc++.h>
using namespace std;
string s,q;
int a[1000005];
int w;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("number2.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for (int i=0;i<s.size();i++)
    {
        if (s[i]>='0' && s[i]<='9')
        {
            a[i]=s[i];
        }
    }
    sort (a,a+s.size(),cmp);
    for(int i=0;i<s.size();i++)
    {
        q+=a[i];
    }
    cout<<q;
    return 0;
}
