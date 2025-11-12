#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5500],ans,vis[5500],maxq=INT_MIN;
void dfs(int dep,int cnt,int maxn,int nw){
    if(dep>3){
        if(cnt>maxn*2){
                ans=(ans+1)%998244353;
        }
    }
    if(dep>n){
        return;
    }
    for(int i=nw;i<=n;i++){
        if(vis[i]) continue;
        vis[i]=1;
        dfs(dep+1,cnt+a[i],max(maxn,a[i]),i+1);
        vis[i]=0;
    }
}
signed main(){
    std::ios::sync_with_stdio(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxq=max(maxq,a[i]);
    }
    if(maxq==1){
        for(int i=3;i<=n;i++){
            int ansn=1;
            for(int i=1;i<=n;i++){
                ansn=((ans*(n+1-i))/i)%998244353;
            }
            ans+=ansn;
        }
    }
    else dfs(1,0,INT_MIN,1);
    cout<<ans;
    return 0;
}

