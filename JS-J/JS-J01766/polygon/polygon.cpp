#include <bits/stdc++.h>
#define int long long
using namespace std;
const int P=998244353;
int a[5005],sum[5005],ans=0;
int G(int t){
    int re=1,c=2;
    while(t){
        if(t&1) re = re*c%P;
        c = c*c%P;t>>=1;
    }
    return re%P;
}
void dg(int dep,int tot,int ty){
    if(dep==0){
        if(tot>ty) ans = (ans+1)%P;
        return;
    }
    if(tot+sum[dep]<=ty) return;
    if(tot>ty){ans=(ans+G(dep))%P;return;}
    for(int i=dep;i>=1;i--) dg(i-1,tot+a[i],ty);
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]+a[i];
    sort(a+1,a+n+1);
    for(int i=n;i>=3;i--) dg(i-1,0,a[i]);
    cout<<ans;
    return 0;
}