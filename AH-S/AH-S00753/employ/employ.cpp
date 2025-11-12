#include<bits/stdc++.h>
#define ppcnt(x) __builtin_popcount(x)
#define ll long long
using namespace std;
const int N=510,mod=998244353;
int n,m,c[N],f[20][1<<18];
string s;
signed main()
{
    freopen("employ.in","r",stdin);
   freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    s='*'+s;
    for(int i=1;i<=n;i++)cin>>c[i];
    if(n<=18)
    {
        f[0][0]=1;
        vector<int>zt;
        for(int i=0;i<(1<<n);i++)zt.emplace_back(i);
        sort(zt.begin(),zt.end(),[](int x,int y){return ppcnt(x)<ppcnt(y);});
        for(auto i:zt)
        for(int k=0;k<=ppcnt(i);k++)
        {
            for(int j=0;j<n;j++)
            {
                if((i&(1<<j)))continue;
                if(c[j+1]<=k||s[ppcnt(i)+1]=='0')f[k+1][i|(1<<j)]=(f[k+1][i|(1<<j)]+f[k][i])%mod;
                else f[k][i|(1<<j)]=(f[k][i|(1<<j)]+f[k][i])%mod;
            }
        }
        int ans=0;
        for(int i=m;i<=n;i++)ans=(ans+f[n-i][(1<<n)-1])%mod;
        cout<<ans<<"\n";
    }
    else
    {
        int tot=0;
        for(int i=1;i<=n;i++)tot+=(c[i]==0);
        if(n-tot+1<m)cout<<0<<"\n";
        else
        {
            ll ans=1;
            for(int i=1;i<=n;i++)ans=ans*i%mod;
            cout<<ans<<"\n";
        }
    }
    return 0;
}
