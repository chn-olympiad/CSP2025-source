#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q[500005],a[500005],k,ans,res,rem[500005];
ll xoor(ll x,ll y){
    if(x==0) return y;
    if(y==0) return x;
    return x^y;
}
void dfs(ll x,ll sum){
    if(x==n){
        if(a[n]==k) ans=max(ans,sum+1);
        else ans=max(ans,sum);
        return ;
    }
    if(sum<=rem[x]) return ;
    else rem[x]=sum;
    ll ls=x;
    while((xoor(q[ls],q[x-1]))!=k&&ls<=n) ls++;
    if(ls>n){
        ans=max(ans,sum);
        return ;
    }
    if(a[ls]!=k) dfs(ls,sum+1);
    else ans=max(ans,sum+1);
    for(int i=ls+1;i<=n;i++) dfs(i,sum+1);
    return ;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    memset(rem,-1,sizeof(rem));
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        q[i]=xoor(q[i-1],a[i]);
    }
    for(int i=1;i<=n;i++){
        ans=0;
        dfs(i,0);
        res=max(ans,res);
    }
    cout<<res;
    return 0;
}
