#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        string s1,s2;
        cin>>s1>>s2;
    }
    for(int i=1;i<=q;i++)
    {
        int sum1=0,sum2=0;
        string x,y;
        cin>>x>>y;
        if(x.size()!=y.size())
        {
            cout<<0<<endl;
            continue;
        }
        for(int i=0;i<x.size();i++)
        {
            if(x[i]=='b')
            {
                sum1=x[i]-'0';
            }
        }
        for(int i=1;i<y.size();i++)
        {
            if(y[i]=='b')
            {
                sum2=y[i]-'0';
            }
        }
        if(sum1!=sum2)
        {
            cout<<0<<endl;
        }
        else{
            cout<<n<<endl;
        }
    }
    return 0;
}
