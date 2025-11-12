#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,ans;
int a[5005];
bool vis[5005];

void dfs(int x,int cnt,int maxx,int sum){
    if(cnt>n)return;
    if(cnt>=3&&sum>maxx*2)ans=(ans+1)%mod;
    for(int i=x+1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            dfs(i,cnt+1,max(maxx,a[i]),sum+a[i]);
            vis[i]=0;
        }
    }
    return;
}

main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(0,0,-1e9,0);
    cout<<ans%mod;
    return 0;
}
