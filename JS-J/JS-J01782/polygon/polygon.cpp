#include<bits/stdc++.h>
#define mod 998244353
#define N 5005
using namespace std;
int n,a[N],tmp[N];
long long ans;
bool vis[N];
void dfs(int now,int dep){
    if(now==dep+1){
        int summ=0,maxx=0;
        for(int i=1;i<=dep;i++){
            summ+=a[tmp[i]];
            maxx=max(maxx,a[tmp[i]]);
        }
        if(summ>maxx*2) ans=(ans+1)%mod;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]&&i>tmp[now-1]){
            vis[i]=1;
            tmp[now]=i;
            dfs(now+1,dep);
            vis[i]=0;
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=3;i<=n;i++) dfs(1,i);
    cout<<ans;
    return 0;
}
