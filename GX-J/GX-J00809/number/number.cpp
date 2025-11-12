#include <bits/stdc++.h>
using namespace std;
long long a[1000001],n=1;
string s;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<=s.size();i++)
    {
       if(s[i]>='0'&&s[i]<='9');
       {
           a[n]=s[i];
           n++;
       }
    }
    sort(a+1,a+1+n);
    for(int i=n;i>=0;i--)
    {
        if(a[i]>=47&&a[i]<=57)
        {
            cout<<char(a[i]);
        }
    }
    return 0;
}
