/*
Boxed Meaning?
Merge in one taste?
And a Body?
Nuclear flu defense?
Building cross building?
Pointer-LCT?

escape escape escape escape escape You lung smog! Time Limit Exceeded!
escape escape escape escape escape You lung smog! Time Limit Exceeded!
escape escape escape escape escape You lung smog! Time Limit Exceeded!

recall
rerererererecall
bitset O(nq) 100
馃槺

You guys馃憟馃憟 shape no shape馃憟馃憟 mind no mind馃憟馃憟

How can I fold this one?
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=5050,V=5050,mod=998244353;
ll qp(ll a,ll b){
    ll res=1;
    for(;b;b>>=1,a=a*a%mod)
        if(b&1)res=res*a%mod;
    return res;
}
ll n,a[N],f[2][V],tg[V];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    ll las=0,cur=1;f[las][0]=1;
    for(ll i=1;i<=n;i++){
        memset(f[cur],0,sizeof f[cur]);
        cin>>a[i];
        for(ll j=0;j<a[i];j++)f[cur][j]=f[las][j];
        for(ll j=a[i];j<V;j++)
            f[cur][j]=(f[las][j]+f[las][j-a[i]])%mod;
        swap(cur,las);
    }ll ans=(qp(2,n)+mod-1)%mod;
    for(ll i=1;i<=n;i++){
        tg[a[i]]++;
        for(ll j=0;j<=a[i];j++)
            ans=(ans+mod-f[las][j]%mod);
        ans=(ans+tg[a[i]])%mod;
    }cout<<ans<<'\n';
    cout.flush();
    fclose(stdin);
    fclose(stdout);
    return 0;
}