#include<bits/stdc++.h>
#define io freopen("polygon.in","r",stdin),freopen("polygon.out","w",stdout)
#define ll long long
using namespace std;
long long n,ans;
long long a[100000],s[100000];
int main()
{
    io;
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    if(n<=3)
    {
        cout<<0<<endl;
        return 0;
    }
    for(ll i1=3;i1<=n;i1++)
    {
        for(ll i2=1;i2<=n-i1+1;i2++)
        {
            ll maxn=0;
            for(ll i3=i2;i3<i2+i1;i3++)
            {
                if(a[i3]>maxn)maxn=a[i3];
            }
            if(s[i1+i2-1]-s[i2-1]>maxn*2)ans=(ans+1)%998244353;
        }
    }
    cout<<ans<<endl;
    return 0;
}
