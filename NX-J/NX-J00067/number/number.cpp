#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int n[100000],t=0,m=0;
    string a;
    getline(cin,a);
    for(int i=0;i<a.length();i++)
    {
        if(a[i]-48>=0&&a[i]-48<=9)
        {
            n[t]=a[i]-48;
            t++;
        }
    }
    for(int i=0;i<t;i++)
    {
        for(int j=0;j<t;j++)
        {
            if(n[j]<n[j+1])
            {
                m=n[j+1];
                n[j+1]=n[j];
                n[j]=m;
            }
        }
    }
    for(int i=0;i<t;i++)
    {
        cout<<n[i];
    }
    return 0;
}
