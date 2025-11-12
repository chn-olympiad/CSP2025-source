#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5005,MOD=998244353;
int n;
ll a[N];
ll ans;
void dfs(ll sum,ll top,ll now,ll cnt,ll k){
    if(cnt==k){
        if(sum>top*2) ans=(ans+1)%MOD;
        return ;
    }
    if(now>n||k>n) return ;
    int nsum=sum+a[now],ntop=max(top,a[now]);
    dfs(sum,top,now+1,cnt,k);
    dfs(nsum,ntop,now+1,cnt+1,k);
}
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=3;i<=n;i++){
        dfs(0,0,1,0,i);
    }
    cout<<ans%MOD;
    return 0;
}
