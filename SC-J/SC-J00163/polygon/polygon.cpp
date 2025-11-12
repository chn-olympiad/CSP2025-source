#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e3+10,mod=998244353;
ll n,ans,a[N];
ll Pow(ll a,ll b,ll mod){
    ll res=1;
    while(b){
        if(b&1)res=res*a%mod;
        b>>=1,a=a*a%mod;
    }
    return res;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    ans=((Pow(2,n,mod)-1-n-(n*(n-1))/2)%mod+mod)%mod;
    cout<<ans;
    return 0;
}