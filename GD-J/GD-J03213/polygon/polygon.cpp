#include<bits/stdc++.h>
#define ll long long
using namespace std; 
ll n;
ll a[51000];
ll ans;
map<vector<ll>,bool>mp;
vector<ll>vv;
void dfs(ll x,ll mx,ll sum,ll sss){
    if(sss>=3&&sum>mx*2&&(!mp[vv])){
        mp[vv]=1;
        ans++;
    }
    if(x>n){
        return;
    }
    vv.push_back(x);
    dfs(x+1,max(mx,a[x]),sum+a[x],sss+1);
    vv.pop_back();
    dfs(x+1,mx,sum,sss);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    dfs(1,0,0,0);
    cout<<(ans%998244353);
    return 0;
}