#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e3+5,mod=998244353;
ll n,a[N],ans;
bool flag=0;
void dfs(ll dep,ll sum,ll maxx,ll cnt){
    if(dep==n+1){
        if(cnt>=3&&sum>maxx*2) ans++;
        ans%=mod;
        return;
    }
    dfs(dep+1,sum+a[dep],max(maxx,a[dep]),cnt+1);
    dfs(dep+1,sum,maxx,cnt);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) flag=1;
    }
    if(!flag){
        ans=1;
        for(int i=1;i<=n;i++){
            ans*=2;
            ans%=mod;
        }
        if(ans>=n+n*(n-1)/2) cout<<ans-(n+n*(n-1)/2);
        else cout<<ans+mod-(n+n*(n-1)/2);
    }
    dfs(1,0,0,0);
    cout<<ans;
    return 0;
}
