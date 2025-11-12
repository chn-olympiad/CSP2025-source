#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,anss=1;
char c;
ll sum[100100];
ll a[100100],cnt=0;
ll mods=998244353;
ll cmp(ll x)
{
    ll ans=1;
    for(int i=1;i<=x;i++)
    {
        ans=ans*i%mods;
    }
    return ans;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>c;
        if(c=='1') sum[i]=sum[i-1]+1;
        if(c=='0') sum[i]=sum[i-1];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        if(a[i]<sum[i])
        {
            cout<<0;
            return 0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        cnt++;
        if(a[i]==a[i-1]&&a[i+1]!=a[i])
        {
            anss=anss*cmp(cnt)%mods;
            cnt=0;
        }
    }
    cout<<anss;
    return 0;
}
