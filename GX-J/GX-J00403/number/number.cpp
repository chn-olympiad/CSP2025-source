#ifndef NUMBER_CPP_INCLUDED
#define NUMBER_CPP_INCLUDED
#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
using namespace std;
int k;
int length(string x)
{
    for(k=1;k<=2000;k++)
    {
        if(x[k]==0)
            break;
    }
    return k+1;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int a[200];
    int t=1;
    for(int i=0;i<=length(s);i++)
    {
        if(s[i]-0<=57&&s[i]-0>=47)
        {
            a[t]=(s[i]-0)-48;
            t+=1;
        }
    }
    for(int i=1;i<=t-1;i++)
    {
        for(int j=i+1;j<=t-1;j++)
        {
            if(a[i]>a[j])
                swap(a[i],a[j]);
        }
    }
    for(int i=t-1;i>=1;i--)
    {
        cout<<a[i];
    }
    return 0;
}


#endif // NUMBER_CPP_INCLUDED
