#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    long long n=0,m=0;
    char a[10000000];
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='1'&&s[i]<='9')
        {
            a[n]=s[i];
            n++;
        }
        if(s[i]=='0')
        {
            m++;
        }
    }
    sort(a,a+n);
    for(int i=n;i>=0;i--)
    {
        cout<<a[n];
    }
    for(int i=0;i<m;i++)
    {
        cout<<'0';
    }
    return 0;
}
