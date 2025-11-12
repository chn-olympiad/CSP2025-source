#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=50000,mod=998244353;
int n,ans,a[50005];
int f[50005];
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
//        for(int j=1;j<=100;j++) cout<<f[j]<<' ';
//        cout<<'\n';
        for(int j=N;j>=a[i]+1;j--){
            (ans+=f[j])%=mod;
            (f[j]+=f[j-a[i]])%=mod;
        }
        (f[a[i]]+=1)%=mod;
    }
    cout<<(ans%mod);
    return 0;
}
