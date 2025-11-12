#include<bits/stdc++.h>
using namespace std;
const int N=20,mod=998244353;
int n,m,a[N],c[N],ans,anss[N];
bool vis[N];
void dfs(int now,int sum){
    if(now>n){
        if(sum>=m) ans=(ans+1)%mod;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            anss[now]=i;
            dfs(now+1,sum+(c[i]>now-sum-1&&a[now]==0));
            vis[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        char z;cin>>z;
        a[i]=(z=='0');
    }
    cout<<endl;
    for(int i=1;i<=n;i++)
        cin>>c[i];
    dfs(1,0);
    cout<<ans;
    return 0;
}