#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;

    cin>>s;
    int b=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
       b++;
    }
    char a[b];
    int c=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
      a[c++]=s[i];
    }
    sort(a,a+b);
    for(int i=b;i>=0;i--)
    cout<<a[i];
    return 0;
}
