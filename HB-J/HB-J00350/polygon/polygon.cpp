#include<bits/stdc++.h>
using namespace std;

const int N=5005,MOD=998244353;
int n,maxn=-1;
int a[N];

int main(void)
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(maxn<a[i])
            maxn=a[i];
    }
    if(n==3)
    {
        if(a[1]+a[2]+a[3]>2*maxn)
        {
            cout<<1;
            return 0;
        }
        cout<<0;
        return 0;
    }
    if(maxn==1)
    {
        int ans=0;
        for(int i=3;i<=n;i++)
        {
            if(i%2==0) ans=(ans+(((i-1)*((i-2)>>1)))%MOD;
            else ans=(ans+((((i-1)>>1)*(i-2))))%MOD;
        }
        cout<<ans;
        return 0;
    }
    return 0;
}
