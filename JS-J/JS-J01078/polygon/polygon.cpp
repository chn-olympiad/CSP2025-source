#include<bits/stdc++.h>
using namespace std;
int a[5005];
long long mod=998244353;
int pd(int a1,int b,int c){
    if(a1+b+c>2*max(max(a1,b),c)){
        return 1;
    }
    return 0;
}
long long c(int a1,int b){
    int s=1,x=1;
    for(int i=0;i<a1;i++){
        s*=(b-i);
    }
    for(int i=0;i<a1;i++){
        x*=(a1-i);
    }
    return (s/x)%mod;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<3){
        cout<<0;
        return 0;
    }
    if(n==3){
        if(pd(a[1],a[2],a[3])){
            cout<<1;
            return 0;
        }
        cout<<0;
        return 0;
    }
    long long ans=0;
    for(int i=3;i<=n;i++){
        ans=(ans+c(i,n))%mod;
    }
    cout<<ans;
    return 0;
}