#include<bits/stdc++.h>
using namespace std;
#define intc constexpr long long
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc mod=998244353,N=5000;
intl n,ans,suma,a[N],hr[N];
void dfs(intl p,intl ch,intl sum,intl mx) {
    if (p==n+1) {
        if (sum>2*mx&&ch>=3) (ans+=1)%=mod;
        return ;
    }
    dfs(p+1,ch+1,sum+a[p],max(mx,a[p]));
    dfs(p+1,ch,sum,mx);
}
intl qpow(intl a,intl b) {
    intl ans=1;
    while (b) {
        if (b%2==1) (ans*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return ans%mod;
}
intl modn(intl a){
    return qpow(a,mod-2)%mod;
}
int main() {
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for (intl i=1;i<=n;i++) cin>>a[i],suma+=a[i];
    if (suma==n) {
        hr[1]=1;
        for (intl i=2;i<=n;i++) hr[i]=(i*hr[i-1])%mod;
        for (intl i=3;i<n;i++) {
            intl ny1=modn(hr[i]%mod);
            intl ny2=modn(hr[n-i]%mod);
            intl cij=((((hr[n]%mod)*ny1)%mod)*ny2)%mod;
            ans+=cij;
            ans%=mod;
        }
        cout<<((ans+1)%mod)<<endl;
        return 0;
    }
    dfs(1,0,0,-1);
    cout<<ans%mod<<endl;
    return 0;
}