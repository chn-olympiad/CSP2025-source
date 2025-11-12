#include<bits/stdc++.h>
using namespace std;
int fact[4*(int)1e6+5],infact[4*(int)1e6+5];
const int mod = 998244353;
int qmi(int a,int b){
    int ans = 1;
    while(b){
        if(b&1) ans*=a;
        a*=a;
        a%=mod;
        ans%=mod;
        b>>=1;
    }
    return ans;
}
void init(){
    fact[0] = 1;
    for(int i = 1;i<=500;i++){
        fact[i] = fact[i-1]*i%mod;
    }
    infact[500]=qmi(fact[500],mod-2)%mod;
    for(int i = 499;i>=0;i--){
        infact[i] = infact[i+1]*(i+1)%mod;
    }
}
int C(int n,int m){
    return fact[n]%mod*infact[n-m]%mod*infact[m]%mod;
}
int A(int n,int m){
    return fact[n]%mod*infact[n-m]%mod;
}
long long ans = 1;
int n,m;
string t;
int main(){
    init();
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m >> t;
    for(int i = 1;i<=n;i++){
        ans*=i;
        ans%=mod;
    }
    cout << ans;
    return 0;
}
