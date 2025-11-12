#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100005],allpow=1,ans;
int mod=998244353;
signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        allpow*=2;
    }
    for (int i=0;i<=allpow;i++)
    {
        int now=i,pos=0,sum=0,maxx=0;
        while (now>0)
        {
            pos++;
            if (now%2==1)
            {
                sum=(a[pos]+sum)%mod;
                maxx=max(maxx,a[pos]);
                maxx%=mod;
            }
            now/=2;
        }
        if (sum>2*maxx)
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
