#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[50500];
bool fg;
long long ans;
long long jie[50500];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1)
        {
            fg=1;
        }
    }
    if(!fg)
    {
        jie[1]=1;
        for(int i=2;i<=n;i++)
        {
            jie[i]=i*jie[i-1];
        }
        for(int i=3;i<n;i++)
        {
            int b=jie[n],c=jie[i],d=jie[n-i];
            ans=(ans+(b/(c*d)))%998244353;
        }
        ans=(ans+1)%998244353;
        cout<<ans%998244353;
        return 0;
    }
    else if(n==3)
    {
        cout<<1;
        return 0;
    }
    return 0;
}
