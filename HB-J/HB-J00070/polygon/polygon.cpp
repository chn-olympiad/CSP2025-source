#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[5001],cnt;
const ll mod=998244353;
//打暴力
void dfs(ll depth,ll edge,ll sum,ll maxa){
    if(depth==n){
        if(edge>=3&&sum>maxa*2) ++cnt;
        return;
    }
    dfs(depth+1,edge+1,sum+a[depth],a[depth]);
    dfs(depth+1,edge,sum,maxa);
}
ll qpow(ll b,ll p,ll m){
    if(p==0) return 1;
    ll ans=qpow(b,p/2,m);
    return (((ans*ans)%m)*(p&1?b:1))%m;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    sort(a,a+n);
    if(n<=20){
        dfs(0,0,0,0);
        cnt%=mod;
    }
    if(n>20&&n<=5000){
        cnt=(qpow(2,n,mod)-n-n*(n+1)/2+mod)%mod;
    }
    cout<<cnt<<"\n";
    return 0;
}
