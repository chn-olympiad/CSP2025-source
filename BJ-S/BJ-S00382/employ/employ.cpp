#include<bits/stdc++.h>
#define g n-i+1-j
using namespace std;
typedef long long ll;
const ll N=18;
ll c[N],s,n,m; char t[N]; bitset<N> vs;
void dfs(ll x,ll k){
    if(k>n-m) return;
    if(x>n){
        s++; return;
    }
    for(ll i=1;i<=n;i++){
        if(vs[i]) continue;
        vs[i]=1;
        dfs(x+1,k+(t[x]=='0'||k>=c[i]));
        vs[i]=0;
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%lld%lld%s",&n,&m,t+1);
    for(ll i=1;i<=n;i++) scanf("%lld",&c[i]);
    dfs(1,0),printf("%lld",s);
    return 0;
}
