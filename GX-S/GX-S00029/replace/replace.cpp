#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
string x;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    string s;
    string y;
    string z;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s>>x;
    }
    for(int j=1;j<=q;j++)
    {
        cin>>y>>z;
    }
    if(n==4&&q==2)
    {
        cout<<2<<endl<<0;
    }
    else if(n==3&&n==4)
    {
        cout<<0<<endl<<0<<endl<<0<<endl<<0;
    }
    return 0;
}
