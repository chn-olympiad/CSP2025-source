#include<bits/stdc++.h>
using namespace std;
int a[100000];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int n=s.length();
    for(int i=0;i<s.length();i++)
    {
            a[i]=s[i];
    }
    sort(a,a+n+1);
    for(int i=n;i>0;i--)
    {
        if(a[i]>=48&&a[i]<=57)cout<<a[i]-48;
    }
    return 0;
}
