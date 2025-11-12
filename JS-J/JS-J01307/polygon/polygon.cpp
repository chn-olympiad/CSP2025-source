#include<bits/stdc++.h>
using namespace std;
long long qw[1000000];
long long mod=998244353;
long long fun(long long z)
{
    long long maxn=1;
    for(int i=1;i<=z;i++)
    {
        maxn*=2;
        maxn%=mod;
    }
    maxn=(maxn-z+mod)%mod;
    maxn=maxn-z*(z-1)/2;
    maxn=(maxn+mod)%mod;
    return (maxn-1+mod)%mod;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long a,s,d,f,g,h,maxn=0;
    cin>>a;
    for(int i=1;i<=a;i++)
    {
        cin>>qw[i];
    }
    if(a>100)
    {
        cout<<fun(a);
        return 0;
    }
    sort(qw+1,qw+1+a);
    for(int i=0;i<(1<<a);i++)
    {
        s=i;
        d=0;
        f=0;
        g=0;
        while(s)
        {
            f++;
            if(s&1)
            {
                d+=qw[f];
                g=max(g,qw[f]);
            }
            s>>=1;
        }
        if(f>2&&g*2<d)
        {
            maxn++;
            maxn%=mod;
        }
    }
    cout<<maxn;
    return 0;
}
