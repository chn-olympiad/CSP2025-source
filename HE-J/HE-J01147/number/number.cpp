#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string a;
    string s;
    int c[10];
    cin>>a;
    for(int i=0;i<=100005;i++)
    {
        if(a[i]>=0&&a[i]<=9)
        {
            s+=a[i];
        }
    }
    for(int i=0;i<=100005;i++)
    {
        c[s[i]]++;
    }
    for(int i=9;i<=0;i--)
    {

        cout<<c[i]*i;
    }
    return 0;
}
