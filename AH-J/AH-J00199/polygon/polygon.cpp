#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int N=5000+6;
const ll mod=998244353;
int n,a[N],pre[N];
ll f1[N*N],f[N*N],ans;

ll fpow(ll a,ll b,ll p) {
    ll res=1;
    while (b) {
        if (b&1) (res*=a)%=p;
        (a*=a)%=p;
        b>>=1;
    }
    return res;
}

int main() {
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    if (n<3) {
        cout<<'0';
        return 0;
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++) pre[i]=a[i]+pre[i-1];
    if (pre[n]==n) {
        ans=(fpow(2,n,mod)-(n*(n-1)/2)%mod-n-1+mod)%mod;
        cout<<ans;
        return 0;
    }
    f[0]=f1[0]=1;
    for (int i=1;i<=n;i++) {
        for (int j=pre[i]-a[i];j>=0;j--) {
            (f[j+a[i]]=f1[j])%=mod;
            (f1[j+a[i]]+=f1[j])%=mod;
        }
        if (i<3) continue;
        for (int j=a[i]*2+1;j<=pre[i];j++) {
            (ans+=f[j])%=mod;
        }
    }
    cout<<ans;
    return 0;
}
