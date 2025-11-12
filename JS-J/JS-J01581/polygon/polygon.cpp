#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[5005],mod=998244353,ans;
void dfs(ll x,ll maxx,ll sum,bool cho){
    if(cho&&sum>maxx*2){
        ans++;
        ans%=mod;
        cout<<maxx<<' '<<sum<<'\n';
    }
    if(x>n)
        return ;
    dfs(x+1,max(maxx,a[x]),sum+a[x],1);
    dfs(x+1,maxx,sum,0);
    return ;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    dfs(0,0,0,0);
    cout<<ans/2;
    return 0;
}
