#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int mod=998244353;
int n;
int a[5010];
ll x[5010];
ll ans;
bool flag=1;
void meiju()
{
    for(ll i=1;i<=(1<<n);i++)
    {
        vector<ll>ve;
        int cnt=1;
        int num=0;
        ll u=i;
        while(u)
        {
            if(u&1)
            {
                ve.push_back(a[cnt]);
                num++;
            }
            cnt++;
            u>>=1;
        }
        if(num<3)
        {
            continue;
        }
        ll sum=0;
        ll maxx=0;
        for(auto x:ve)
        {
            sum+=x;
            maxx=max(maxx,x);
        }
        if(sum>maxx*2)
        {
            ans=(ans+1)%mod;
        }
    }
}
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
            flag=0;
        }
    }
    if(flag)
    {
        x[1]=1;
        x[0]=1;
        for(int i=2;i<=n;i++)
        {
            x[i]=((x[i-1]%mod)*i%mod)%mod;
        }
        for(int i=3;i<=n;i++)
        {
            ans+=(x[n]/x[n-i])/x[i];
            ans%=mod;
            //cout<<i<<"\n";
            //cout<<(x[n]/x[n-i])/x[i]<<"\n";
        }
        cout<<ans;
        return 0;
    }
    meiju();
    cout<<ans;
    return 0;
}
