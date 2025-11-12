#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
ll n,a[5005];
ll ans=0;
void dfs(ll idx,ll sum,ll maxn,ll cnt){
    if(cnt>2 && sum>maxn*2)  ans++,ans%=mod;
    if(idx>n){
        return ;
    }
    for(ll i=idx;i<=n;i++){
        ll ss=sum+a[i],mm=max(maxn,a[i]);
        dfs(i+1,ss,mm,cnt+1);
    }
    return ;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,0,0,0);
    cout<<ans<<endl;
    return 0;
}
