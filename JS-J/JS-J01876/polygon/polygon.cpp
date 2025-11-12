#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5005,mod=998244353;
int n,ans;
int a[N],cnt[N],vis[N];
bool check(int x){
    if(x<3) return 0;
    int sum=0,maxx=-0x3f3f3f3f;
    for(int i=1;i<=x;i++){
        sum+=a[i]%mod;
        maxx=max(a[i],maxx);
    }
    if(maxx<=sum) return 1;
    return 0;
}
void dfs(int k){
    if(k>n) return ;
    if(check(n)){
        ans++;
    }
    for(int i=a[k-1];i<=n;i++){
        if(vis[i]==0){
            vis[i]=1;
            cnt[i]=a[i];
            dfs(k+1);
        }
    }

}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    dfs(1);
    cout<<ans-1;
    return 0;
}
