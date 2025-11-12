#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,a;
    cin>>s;
    if(s.size()==1)
    {
        cout<<s;
        return 0;
    }
    for(int i=0;i<=s.size();i++)
    {
        if(s[i]<='9')
        {
            a[i]=s[i];
        }
    }
    char zc;
    for(int i=0;i<=a.size();i++)
    {
        if(a[i+1]>a[i])
        {
            zc=a[i];
            a[i]=a[i+1];
            a[i+1]=zc;
        }
    }
    cout<<a;
    return 0;
}
