#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vec vector
#define str string
#define bstr basic_string
#define mod 998244353
    vec<ll>sticks;
    ll n;
ll dfs(ll l,vec<ll>arr){
    ll mx=0,sum=0;
    for(auto i:arr){
        mx=max(mx,i);
        sum+=i;
    }
    ll ans=0;
    if(sum>2*mx)ans++;
    for(ll i=l+1;i<n;i++){
        auto tmp=arr;
        tmp.push_back(sticks[i]);
        ans+=dfs(i,tmp);
        ans%=mod;
    }
    return ans;
}
int main(){
    #ifndef DXX_DEBUG
        freopen("polygon.in","r",stdin);
        freopen("polygon.out","w",stdout);
    #endif
    cin>>n;
    for(ll i=0;i<n;i++){
        ll stick;
        cin>>stick;
        sticks.push_back(stick);
    }
    cout<<dfs(-1,{})<<'\n';
    return 0;
}
