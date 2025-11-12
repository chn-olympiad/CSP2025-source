#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int ans;
int n,a[5010],b[5010];
bool vis[5010];
void dfs(int maxn,int cnt){
    if(cnt==maxn){
        int sum=0,full=-1;
        for(int i=0;i<maxn;i++){
            sum+=b[i];
            full=max(full,b[i]);
        }
        if(sum>full*2){
            ans++;
            ans=ans%MOD;
        }
        return;
    }
    for(int i=cnt+1;i<n;i++){
        if(!vis[i]){
            b[cnt]=a[i];
            vis[i]=true;
            dfs(maxn,cnt+1);
            vis[i]=false;
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=3;i<=n;i++)dfs(i,0);
    cout<<ans+1;
    return 0;
}
