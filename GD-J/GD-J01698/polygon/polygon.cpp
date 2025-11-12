#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,ans,maxa,a[5005];
unsigned long long f[5005];
void dfs(int k,int p,int cnt,int sum,int maxl) {
    if (cnt==k) {
        if (sum>maxl*2) ans=(ans+1)%mod;
        return;
    }
    if (p==n+1) return;
    dfs(k,p+1,cnt+1,sum+a[p],max(maxl,a[p]));
    dfs(k,p+1,cnt,sum,maxl);
}
void pre(int n) {
    f[0]=f[1]=1;
    for (int i=2;i<=n;i++)
        f[i]=f[i-1]*i;
}
int C(int n,int m) {
    return f[m]/(f[n]*f[m-n])%mod;
}
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i],maxa=max(maxa,a[i]);
    if (maxa<=1) {
        //C(3,n)+C(4,n)+C(5,n)+...+C(n-1,n)+C(n,n)
        pre(n);
        for (int i=3;i<=n;i++)
            ans=(ans+C(i,n)%mod)%mod;
        cout<<ans%mod;
        return 0;
    }
    for (int i=1;i<=n;i++)
        dfs(i,1,0,0,0);
    cout<<ans;
    return 0;
}

