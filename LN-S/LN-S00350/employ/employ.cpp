#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,N=2000;
int n,m,s[N],c[N];
void A(){
    long long ans=1;
    for(int i=2;i<=n;i++) ans=ans*i%mod;
    cout<<ans%mod;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=n;i++) cin>>c[i];
    A();
    return 0;
}
