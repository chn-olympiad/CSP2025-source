#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[5005],ans;
void dfs(ll idx,ll cnt,ll mx,ll sum){
    if(idx>n){
        if(cnt<3)return;
        if(sum>mx*2)ans=(ans+1)%998244353;
        return;
    }
    dfs(idx+1,cnt,mx,sum);
    dfs(idx+1,cnt+1,max(mx,a[idx]),sum+a[idx]);
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;++i)cin>>a[i];
    dfs(1,0,0,0);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
