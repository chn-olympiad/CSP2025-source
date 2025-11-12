#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e3+10;
ll n,a[N],ans;
bool cmp(const ll &x,const ll &y){
    return x>y;
}
void dfs(ll pre,ll sum,ll maxn,ll cnt){
    if(pre>n){
        return ;
    }
    if(cnt>=3&&sum>2*maxn){
        ans++;
        ans%=998244353;
    }
    for(ll i=pre+1;i<=n;i++){
        ll Sum=sum+a[i],Maxn=max(maxn,a[i]);
        dfs(i,Sum,Maxn,cnt+1);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1,cmp);
    dfs(0,0,0,0);
    printf("%lld",ans%998244353);
    return 0;
}
