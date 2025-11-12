#include<bits/stdc++.h>
using namespace std;
bool tmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int a[1000005],pos=0;
    cin>>s;
    for (int i=0;i<s.size();i++)
    {
        if (s[i]>=48&&s[i]<=57)
        {
            a[++pos]=s[i]-48;
        }
    }
    sort (a+1,a+pos+1,tmp);
    for (int i=1;i<=pos;i++)
    {
        cout<<a[i];
    }
    return 0;
}
