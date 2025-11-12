#include <bits/stdc++.h>
using namespace std;
string n;
int a[10005];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int maxn=-1,num=0;
    cin>>s;
    for (int i=0;i<=s.length();i++)
    {
        if (s[i]>='0'&&s[i]<='9')
        {
            a[i]=s[i]-'0';
            num++;
        }
    }
    sort(a+1,a+num+1);
    for (int i=num;i>=0;i--)
    {
        n[i]=a[i]+'0';
    }
    for (int i=num;i>=0;i--)
    {
        cout<<n[i];
    }
    return 0;
}
