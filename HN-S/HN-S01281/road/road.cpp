#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m,k;
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(!isdigit(c)){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(isdigit(c)){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
const int N=1e4+10;
struct node{
    int v,w;
};
vector<node> g[N];
bool vis[N];
int ans=1e9;
bool vis1[N],vis2[N];
int mn=1e9;
void dfs(int id,int sum,int cnt,bool flag){
    if(sum>=ans) return ;
    if(cnt==n){
        if(flag) sum+=mn;
        ans=min(ans,sum);
        return ;
    }
    memset(vis1,0,sizeof vis1);
    for(auto x:g[id]){
        int v=x.v,w=x.w;
        if(!vis[v]){
            vis[v]=true;
            vis1[v]=true;
            dfs(x.v,sum+x.w,cnt+1,flag);
            vis[v]=false;
        }
    }
    for(int i=1;i<=n;i++){
        if(i==id) continue;
        if(!vis1[i]&&!vis[i]){
            vis[i]=true;
            dfs(i,sum,cnt+1,true);
            vis[i]=false;
        }
    }
    memset(vis1,0,sizeof vis1);
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("1.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    n=read(),m=read(),k=read();
    for(int i=1;i<=m;i++){
        int u=read(),v=read(),w=read();
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=1;i<=k;i++){
        int c=read();
        mn=min(mn,c);
        for(int j=1;j<=n;j++){
            int x=read();
        }
    }
    for(int i=1;i<=n;i++){
        vis[i]=true;
        dfs(i,0,1,false);
    }
    cout<<ans;
}
