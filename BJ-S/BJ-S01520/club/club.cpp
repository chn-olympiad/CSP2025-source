#include <bits/stdc++.h>
using namespace std;
int nxt[10005],to[10004],val[10005],h[10005];
int cnt=0,n,m,k;
int f[10][10005],cn[15];
bool b[10005];
struct node{
    int u,w;
    friend bool operator <(node x,node y){
        return x.w>y.w;
    }
}tmp;
int dis[1000005],vis[1000005];
void add(int a,int b,int c){
    ++cnt;
    val[cnt]=c,to[cnt]=b,nxt[cnt]=h[a],h[a]=cnt;
}
long long num=0;
int dijkstra(int s){
    priority_queue <node> q;
    long long ans=0;
    for(int i=1;i<=n;i++)dis[i]=1000000005;
    dis[s]=0;
    tmp.u=s,tmp.w=0;
    q.push(tmp);
    while(!q.empty()){
        node l=q.top();
        q.pop();
        if(vis[l.u])continue;
        vis[l.u]=1;
        for(int i=h[l.u];i;i=nxt[i]){
            int t=to[i];
            if(dis[t]>val[i]&&!vis[t]){
                dis[t]=val[i];
                tmp.u=to[i],tmp.w=dis[t];
                q.push(tmp);
            }
        }
    }
    for(int i=1;i<=n;i++){
        //cout<<dis[i]<<" ";
        ans+=dis[i];
    }
    return ans;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    int l;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        l=a;
        add(a,b,c);
        add(b,a,c);
    }
    for(int i=1;i<=k;i++){
        cin>>cn[i];
        for(int j=1;j<=n;j++)cin>>f[i][j];
    }
    num=dijkstra(l);
    cout<<num;
    return 0;
}

