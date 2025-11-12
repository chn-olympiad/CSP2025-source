#include<bits/stdc++.h>
using namespace std;
int a[10],an;
string x;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>x;
    for(int i=0;i<x.length();i++)
    {
        if(x[i]<='9'&&x[i]>='0')
        {
            int b=x[i]-'0';
            a[b]=a[b]+1;
        }
    }
    for(int i=9;i>=0;i--)
    {
        int s;
        s=a[i];
        for(int d=0;d<s;d++)
        {
            cout<<i;
        }
    }
    return 0;
}
