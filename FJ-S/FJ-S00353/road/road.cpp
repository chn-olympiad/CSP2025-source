#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5,maxm=3e6+5;
int n,m,k,tot;
long long ans,ans1;
int cnt,first[maxn],to[maxm],nxt[maxm],w[maxm];
int ck[20][maxn];
int dis[maxn];
bool vis[maxn];
void add(int u,int v,int c){
    to[++cnt]=v;
    nxt[cnt]=first[u];
    first[u]=cnt;
    w[cnt]=c;
}
void prim(){
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0;
    while(++tot<=n){
        long long minn=1e18;
        int now=0;
        for(int i=1;i<=n;i++){
            if(vis[i]) continue;
            if(dis[i]<minn){
                now=i;
                minn=1ll*dis[i];
            }
        }
        vis[now]=1;
        ans+=1ll*minn;
        for(int i=first[now];i;i=nxt[i]){
            if(vis[to[i]]) continue;
            dis[to[i]]=min(dis[to[i]],w[i]);
        }
    }
    return;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k; 
    for(int i=1;i<=m;i++){
        int u,v,c;
        cin>>u>>v>>c;
        add(u,v,c);
        add(v,u,c);
        ans1+=c;
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++) cin>>ck[i][j];
        for(int k=1;k<=n;k++){
            for(int j=1;j<=n;j++){
                if(k==j) continue;
                add(k,j,ck[i][j]+ck[i][k]);
                add(k,j,ck[i][j]+ck[i][k]);
            }
        }
    } 
    if(k==0){
        cout<<ans1<<"\n";
        return 0;
    }
    
    prim();
    cout<<ans<<"\n";
    return 0;
}