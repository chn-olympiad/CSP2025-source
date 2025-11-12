#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
long long solve1(int x,int y)
{
    long long u=1,g=1;
    for(int i=x;i>x-y;i--)
    {
        u=u*i;
    }
    for(int i=1;i<=y;i++)
    {
        u=u/i;
    }
    return u%MOD;
}
long long solve2(int x)
{
    long long u=1;
    for(int i=x;i>=2;i--)
    {
        u=u*i%MOD;
    }
    return u%MOD;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int a[100001];
    for(int i=1;i<=n;i++) cin>>a[i];
    bool h=true;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==1)
        {
            h=false;
            break;
        }
    }
    if(m==n)
    {
        if(h==true)
        {
            long long u=solve2(n);
            cout<<u;
        }
        else
        {
            cout<<0;
        }
        return 0;
    }
    if(h==true)
    {
        long long t=solve1(n,m)%MOD;
        cout<<t;
        return 0;
    }
    return 0;
}
