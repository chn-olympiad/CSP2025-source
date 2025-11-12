#include <bits/stdc++.h>
using namespace std;
string s;
int a[10005],n=1;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<=s.length()-1;i++)
    {
        if((s[i]>='0')&&(s[i]<='9'))
        {
            a[n]=s[i];
            n++;
        }
    }
    sort(a+1,a+n+1);
    for(int i=n;i>0;i++)
    {
        cout<<a[i];
    }
    return 0;
}
