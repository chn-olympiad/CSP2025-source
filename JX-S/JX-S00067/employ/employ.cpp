#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,c[500],ans=0;
string s;
bool bok[600];
const ll mod=998244353;
ll chuli(ll x)
{
    ll ans=1;
    while(x!=1)
    {
        ans*=x;
        ans%=mod;
        x--;
    }
    return ans%mod;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    cin>>s;
    for(ll i=1;i<=n;i++)
    {
        if(s[i-1]=='1')bok[i]=true;
        else bok[i]=false;
    }
    ll nn=0;
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&c[i]);
        if(c[i]==0)nn++;
    }
    if(nn+m>n)printf("0");
    else printf("%lld\n",chuli(n));
    return 0;
}
