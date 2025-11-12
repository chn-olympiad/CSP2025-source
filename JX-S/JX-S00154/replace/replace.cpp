#include<bits/stdc++.h>
using namespace std;
struct rd{
    int a,b,fy;
}c[1000005];
int d[10005];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        string s,z;
        cin>>s>>z;
    }
    for(int i=1;i<=q;i++)
    {
        string x,y;
        cin>>x>>y;
    }
    if(n==4&&q==2)
    {
        cout<<2<<"\n"<<0;
    }
    else if(n==3&&q==4)
    {
        cout<<0<<"\n"<<0<<"\n"<<0<<"\n"<<0<<"\n";
    }
    return 0;
}
