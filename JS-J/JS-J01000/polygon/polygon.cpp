#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
ll a[5005],f[5005],g[5005],h[5005];
int fpow(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    h[0]=1;
    for(int i=1;i<=n-1;i++){
        for(int j=a[n]+1;j>=a[n]+1-a[i];j--){
            h[a[n]+1]+=h[j];
        }
        for(int j=a[n];j>=a[i];j--){
            h[j]+=h[j-a[i]];h[j]%=mod;
        }
        int cnt=0;
        for(int j=0;j<=a[i+1];j++){
            cnt+=h[j];cnt%=mod;
        }
        g[i+1]=(fpow(2,i)-cnt+mod)%mod;
    }
    for(int i=1;i<=n;i++){
        f[i]=(f[i-1]+g[i])%mod;
    }
    cout<<f[n];
    return 0;
}
