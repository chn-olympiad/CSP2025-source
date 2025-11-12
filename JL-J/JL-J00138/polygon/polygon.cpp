#include <bits/stdc++.h>
using namespace std;
const int N=5005,mod=998244353;
int a[N];
int n;
int C(int x){
    int k=1,m=1;
    for(int i=1;i<=x;i++){
        k*=i;
        k=k%mod;
    }
    for(int i=n;i>=(n-x+1);i--){
        m*=i;
        m=m%mod;
    }
    return m/k;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n==3){
        int ans;
        if(a[1]+a[2]+a[3]>(2*max(a[1],max(a[2],a[3]))))
            cout<<1;
        else
            cout<<0;
        return 0;
    }
    int ans=0;
    for(int i=3;i<=n;i++){
        ans+=C(i);
        ans=ans%mod;
    }
    cout<<ans;
    return 0;
}
