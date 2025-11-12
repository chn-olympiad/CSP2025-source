#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[5001],ans,mod=998244353;
inline void dfs(ll fr,ll sum,ll mx,ll m)
{
    if(sum>mx*2&&m>2) ans++;
    for(ll i=fr+1;i<=n;i++) dfs(i,sum+a[i],a[i],m+1);
}
inline ll f(int a,int b)
{
    ll sum=1;
    for(int i=a;i>=a-b+1;i--) sum*=i;
    for(int i=b;i>=2;i--) sum/=i;
    return sum;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    if(a[n]==1)
    {
        for(int i=3;i<=n;i++) ans+=f(n,i),ans%=mod;
    }
    else dfs(0,0,0,0);
    cout<<ans;
    return 0;
}
