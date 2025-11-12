#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
const int mod=998244353;
long long inv[5005];
long long c(int n,int m){
    return inv[n]/inv[n-m]/inv[m];
}
bool flag=1;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    inv[0]=1;
    for(int i=1;i<=5000;i++){
        inv[i]=inv[i-1]*i%mod;
    }
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) flag=0;
    }
    sort(a+1,a+1+n);
    if(flag){
        long long ans=0;
        for(int i=3;i<=n;i++){
            ans+=c(n,i);
            ans%=mod;
        }
        cout<<ans<<"\n";
        return 0;
    }
    if(n<=2){
        cout<<0<<"\n";
        return 0;
    }
    if(n<=3){
        if(a[1]+a[2]+a[3]>2*a[3]) cout<<1<<"\n";
        else cout<<0<<"\n";
        return 0;
    }
    return 0;
}
