#include<bits/stdc++.h>
using namespace std;
int n,m;
int c[505];
string q;
int ans=0;
bool isa=0;
int a(int x)
{
    long long an=1;
    for(int i=x;i>0;i--)
    {
        an=(an*i)%998244353;
    }
    return an%998244353;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>q;   //ti mu nan du
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        if(q[i]=='1')
        isa=1;
    }
    if(isa)
    cout<<a(n);
    else
    cout<<0;
    return 0;
}
