#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int a[1000005],b=1;
    cin>>s;
    if(s==1)
    {
        cout<<s;
    }
    for(int i=1;i<=s.size();i++)
    {
        if(s[i]=='1')
        {
            a[b]=1;
            b++;
        }
        if(s[i]=='2')
        {
            a[b]=2;
            b++;
        }
        if(s[i]=='3')
        {
            a[b]=3;
            b++;
        }
        if(s[i]=='4')
        {
            a[b]=4;
            b++;
        }
        if(s[i]=='5')
        {
            a[b]=5;
            b++;
        }
        if(s[i]=='6')
        {
            a[b]=6;
            b++;
        }
        if(s[i]=='7')
        {
            a[b]=7;
            b++;
        }
        if(s[i]=='8')
        {
            a[b]=1;
            b++;
        }
        if(s[i]=='9')
        {
            a[b]=9;
            b++;
        }
        if(s[i]=='0')
        {
            a[b]=0;
            b++;
        }
    }
    b--;
    sort(a+1,a+b+1);
    for(int i=b;i>=1;i--)
    {
        cout<<a[i];
    }
    return 0;
}
