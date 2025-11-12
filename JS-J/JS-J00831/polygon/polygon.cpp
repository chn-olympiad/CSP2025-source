#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,a[5005],ans=0,Jc[5005],C[5005][5005];
int A(int m,int n){
    if(n==m) return 1ll;
    return (((Jc[n]/Jc[n-m])%mod)/Jc[m])%mod;
}
void jc(){
    Jc[1]=1;
    for(int i=2;i<=n;i++){
        Jc[i]=(Jc[i-1]*i)%mod;
    }
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    jc();
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(n==3){
        if(a[1]+a[2]>a[3]){
            cout<<1;
            return 0;
        }
        cout<<0;
        return 0;
    }
    bool pf1=1;
    for(int i=1;i<=n;i++){
        if(a[i]>1){
            pf1=0;
            break;
        }
    }
    if(pf1){
        ans=0;
        for(int i=3;i<=n;i++){
            ans+=A(i,n);
        }
        cout<<ans;
        return 0;
    }
    return 0;
}
