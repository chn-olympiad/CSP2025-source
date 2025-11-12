#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;//998, 244, 353
long long n,a[5005],lmax;
long long ans;
void dfs(long long sum,long long maxn,int x,int d){
    if (x>n){
        return ;
    }
    if (d>=3){
        if (maxn*2<sum) ans=(ans%mod+1)%mod;
    }
    for (int i=x+1;i<=n;i++){
        dfs(sum+a[i],max(maxn,a[i]),i,d+1);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    if (n<=20){
        for (int i=1;i<=n;i++){
            dfs(a[i],a[i],i,1);
        }
        cout<<ans%mod<<endl;
        return 0;
    }
    for (int i=1;i<=n;i++){
        lmax=a[i];
        for (int j=1;j<=n;j++){
            if (i==j||a[j]>a[i]) continue;
            lmax+=a[j];
            if (lmax>2*a[i]) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
