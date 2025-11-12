#include<bits/stdc++.h>
using namespace std;
int l[5010],vis[5050],int ma=0,s=0,qwq,n,k,ans=0;
void dfs(int now,int cnt,int dep){
    vis[now]=1;s+=l[now];ma=max(ma,l[now]);
    if(ma>=s-l[now]){
        s-=l[now];return;
    }
    if(now>n)return;
    if(cnt==dep){
        ans++;ans%=mod;return;
    }
    
    
    dfs(now+1,cnt+1,dep);
    vis[now]=0;ma=qwq;s-=l[now];
    dfs(now+1,cnt,dep);
    
}
const int mod=998244353;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>l[i];ma=max(ma,l[i]);
    }
    for(int i=3;i<=n;i++){
        memset(vis,0,sizeof(vis));
        dfs(1,0,i);
    }
    cout<<ans;
    return 0;
}