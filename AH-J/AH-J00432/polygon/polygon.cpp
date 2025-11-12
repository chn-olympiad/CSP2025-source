#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[5010],ans[5010],cnt;
void dfs(ll cur,ll d,ll pre){
    if(cur==d+1){
        ll sum=0,maxn=-1;
        for(ll i=1;i<cur;i++){
            sum+=ans[i];
            maxn=max(maxn,ans[i]);
        }
        if(sum>2*maxn)cnt++;
        cnt%=998244353;
        return ;
    }
    for(ll i=pre+1;i<=n;i++){
        ans[cur]=a[i];
        dfs(cur+1,d,i);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(ll i=3;i<=n;i++){
        memset(ans,0,sizeof ans);
        dfs(1,i,0);
    }
    cout<<cnt%998244353;
    return 0;
}
