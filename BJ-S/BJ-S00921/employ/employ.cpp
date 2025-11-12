#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long

const ll N=510;
const ll mod=998244353;
ll c[N];

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    for(ll i=1;i<=n;i++) cin>>c[i];

    ll ans=1;
    for(ll i=1;i<=n;i++) ans=(ans*i)%mod;
    cout<<ans%mod<<endl;
    return 0;
}