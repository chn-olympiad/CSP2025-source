#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=1e3+10,mod=998244353;
ll n,m,fact[N];
string s;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    fact[1]=1;
    for(ll i=2;i<=n;i++){
        fact[i]=fact[i-1]*i%mod;
    }
    cout<<fact[n];
    return 0;
}
