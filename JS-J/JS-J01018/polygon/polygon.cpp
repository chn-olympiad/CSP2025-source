#include <bits/stdc++.h>
using namespace std;
const int N=25000003,mod=998244353;
int n,a[N],sum[N],g[N],ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]+a[i];
    sort(a+1,a+n+1);
    g[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=sum[i];j>=a[i];j--){
            (g[j]+=g[j-a[i]])%=mod;
            if(j>2*a[i]) (ans+=g[j-a[i]])%=mod;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
//freopen("polygon.in","r",stdin);
//freopen("polygon.out","w",stdout);
