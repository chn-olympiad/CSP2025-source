#include<iostream>
#include<cstdio>
using namespace std;
int a[100005];
int main()
{
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=1;i<=s.size();i++)
    {
        if('0'<=s[i]&&s[i]<='9') a[i]=s[i];
    }
    for(int i=1;i<=s.size();i++)
    {
        if(a[i]<a[i+1])
        {
            int b;
            b=a[i];
            a[i]=a[i+1];
            a[i+1]=b;
        }
    }
    for(int i=1;i<=s.size();i++)
    {
        cout<<a[i];
    }
    return 0;
}

