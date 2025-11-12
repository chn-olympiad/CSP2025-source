#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=2005,Mod=998244353;
LL n,a[N],ans[N],res;
bool check(LL ans[],LL cur){
    LL sum=0,maxn=-1;
    for(LL i=1;i<cur;i++){
        sum+=ans[i];
        maxn=max(maxn,ans[i]);
    }
    if(sum-maxn>maxn) return true;
    return false;
}
void dfs(LL cur,LL k,LL pre){
    if(cur>k){
        if(check(ans,cur)){
            res++;
            res%=Mod;
        }
        return;
    }
    for(LL i=pre+1;i<=n;i++){
        ans[cur]=a[i];
        dfs(cur+1,k,i);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(LL i=1;i<=n;i++) cin>>a[i];
    if(n<=20){
        for(LL i=3;i<=n;i++){
            memset(ans,0,sizeof ans);
            dfs(1,i,0);
        }

    }
    cout<<res;
    return 0;
}
