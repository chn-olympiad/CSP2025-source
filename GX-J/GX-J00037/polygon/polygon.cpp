//choose m sticks,satisfy that (intext there has a limit)
//sigma the count of different plans

//sigma a plan except the maxnum,sigma > maxnum
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll N = 5e3+5,mod = 998244353;

ll n,a[N],ans,fac[N],inv[N];
bool tp1;

ll read()
{
    char c = getchar();
    ll ch = 0;
    while(c<'0'||c>'9')
    {
        c = getchar();
    }
    while(c>='0'&&c<='9')
    {
        ch = (ch<<3)+(ch<<1)+c-'0';
        c = getchar();
    }
    return ch;
}

ll fast_pow(ll x,ll y)
{
    ll res = 1;
    x %= mod;
    while(y)
    {
        if(y&1) res = res*x%mod;
        x = x*x%mod;
        y >>= 1;
    }
    return res;
}

ll C(ll x,ll y)
{
    return (fac[x]*inv[y]%mod*inv[x-y])%mod;
}

void solve1()
{
    fac[0] = 1;
    for(ll i=1;i<=n;i++) fac[i] = fac[i-1]*i%mod;
    inv[n] = fast_pow(fac[n],mod-2);
    for(ll i=n-1;i>=0;i--) inv[i] = inv[i+1]*(i+1)%mod;
    for(ll i=3;i<=n;i++) ans = (ans+C(n,i))%mod;
    cout << ans;
}

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cout.tie(0);
    n = read();
    for(ll i=1;i<=n;i++)
    {
        a[i] = read();
        if(a[i]>1) tp1 = 1;
    }
    if(!tp1)
    {
        solve1();
        return 0;
    }
    sort(a+1,a+1+n,greater<ll>());
    for(ll i=1;i<=n;i++)
    {
        ll len = n-i;
        for(ll j=0;j<(1<<len);j++)
        {
            ll res = 0,cnt = 0;
            for(ll k=1;k<=len;k++)
            {
                if((j>>(k-1))&1)
                {
                    ++res;
                    cnt += a[i+k];
                }
            }
            if(res<=1||cnt<=a[i]) continue;
            ++ans;
        }
    }
    cout << ans%mod;
    return 0;
}
