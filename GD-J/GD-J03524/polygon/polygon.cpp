#include<bits/stdc++.h>
using namespace std;
const int N=5005,mod=998244353;
int n,mx,ans,a[5005],f[N<<1],s[2][N<<1];
int main(){
    freopen("polygon.in","r",stdin);freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1),mx=a[n]*2+1;
    for(int i=1;i<=n;i++){
        for(int k=1;k<=mx;k++) f[k]=0;
        for(int k=1;k<=mx;k++) (f[min(a[i]+k,mx)]+=(s[0][k]+s[1][k])%mod)%=mod;
        for(int j=1;j<i;j++) ++s[0][min(a[i]+a[j],mx)];
        for(int k=1;k<=mx;k++) (s[1][k]+=f[k])%=mod;
        for(int j=2*a[i]+1;j<=mx;j++) (ans+=f[j])%=mod;
    }
    cout<<ans;
    return 0;
}