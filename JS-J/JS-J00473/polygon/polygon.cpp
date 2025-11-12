#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll n,a[5005],ans,fact[5005],w;
bool f[5005];

bool check()
{
    ll sum=0,maxn=0;
    for(int i=1;i<=n;i++)
        if(f[i]==1)
            sum+=a[i],maxn=max(maxn,a[i]);
    if(sum>2*maxn)
        return true;
    return false;
}

ll qp(ll a,ll b)
{
    ll t=a%mod,res=1;
    while(b)
    {
        if(b&1)
            res=res*t%mod;
        t=t*t%mod;
        b/=2;
    }
    return res;
}

ll C(ll n,ll m)
{
    return fact[n]*qp(fact[m],mod-2)%mod*qp(fact[n-m],mod-2)%mod;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        w=max(w,a[i]);
    }
    if(n>20)
    {
        fact[0]=1;
        for(int i=1;i<=n;i++)
            fact[i]=fact[i-1]*i%mod;
        for(int i=3;i<=n;i++)
            ans=(ans+C(n,i))%mod;
        cout<<ans;
        exit(0);
    }
    for(int bit=1;bit<(1<<n);bit++)
    {
        ll x=bit,pos=0;
        memset(f,0,sizeof f);
        while(x)
        {
            pos++;
            if(x&1)
                f[pos]=1;
            x/=2;
        }
        if(check())
            ans=(ans+1)%mod;
    }
    cout<<ans;
	return 0;
}
