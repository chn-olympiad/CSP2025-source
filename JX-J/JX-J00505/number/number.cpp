#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005],k,p;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for (int i=0;i<s.length();i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            a[++k]=s[i]-'0';
        }
    }
    sort(a+1,a+k+1);
    if(a[k]==0)
    {
        cout<<0<<endl;
        return 0;
    }
    for (int i=k;i>=1;i--)
    {
        cout<<a[i];
    }
    cout<<endl;
    return 0;
    //freopen change;
}
