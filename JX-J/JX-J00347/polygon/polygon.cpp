#include <bits/stdc++.h>
using namespace std;

int MOD=998244353;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[50005],ans=0,l,ll;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n<3)
    {
        cout<<0;
        return 0;
    }
    if(n==3)
    {
        int maxx=max(a[1],max(a[2],a[3])),summm=a[1]+a[2]+a[3];
        if(summm>maxx*2)
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
        return 0;
    }
    n=n%MOD;
    l=n*(n-1)*(n-2)%MOD;
    ll=6;
    for(int i=3;i<=n;i++)
    {
        ans=(ans+(l/ll))%MOD;
        l=(l*(n-i))%MOD;
        ll=(ll*(i+1))%MOD;
    }
    cout<<ans;
    return 0;
}
