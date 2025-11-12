#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN=1e5+5;
const int MAXM=1e6+5;

struct node{
    int v,c,nxt;
}e[MAXM<<2],e2[MAXM<<2];

int h[MAXM],tot=0,vis[MAXN],a[15][MAXN];
int n,m,k;

void addEdge(int u,int v,int c){
    ++tot;
    e[tot].v=v;e[tot].c=c;e[tot].nxt=h[u];h[u]=tot;
}
int tot2=0,h2[MAXM];
void addEdge2(int u,int v,int c){
    ++tot2;
    e2[tot2].v=v;e2[tot2].c=c;e2[tot2].nxt=h2[u];h2[u]=tot2;
}
struct Queue{
    int pre,u,c;
    bool operator < (const Queue T)const{
        return c>T.c;
    }
};
struct node2{
    int u,v,c;
}p[MAXN];
priority_queue<Queue> q;
int ans=0,kkk=0,c[15];
void find_bst(){
    Queue now,nt;
    vis[1]=1;
    for(int i=h[1];i;i=e[i].nxt){
        nt.pre=1;nt.u=e[i].v;nt.c=e[i].c;
        q.push(nt);
    }
    while(!q.empty()){
        now=q.top();q.pop();
        int u=now.u;
        if(vis[u])  continue;
        vis[u]=1;
        ans+=now.c;
        //addEdge2(now.pre,u,now.c);
        p[++kkk].u=now.pre;
        p[kkk].v=u;
        p[kkk].c=now.c;
        for(int i=h[u];i;i=e[i].nxt){
            int v=e[i].v;
            if(vis[v])  continue;
            nt.pre=u;nt.u=v;nt.c=e[i].c;q.push(nt);
        }
    }
}
int res=0,sum=0;
void find_bst2(){
    Queue now,nt;
    vis[1]=1;
    for(int i=h2[1];i;i=e2[i].nxt){
        nt.pre=1;nt.u=e2[i].v;nt.c=e2[i].c;
        q.push(nt);
    }
    while(!q.empty()){
        now=q.top();q.pop();
        int u=now.u;
        if(vis[u])  continue;
        //cout<<u<<' ';
        vis[u]=1;
        res+=now.c;
        if(res+sum>ans) return;
        for(int i=h2[u];i;i=e2[i].nxt){
            int v=e2[i].v;
            if(vis[v])  continue;
            nt.pre=u;nt.u=v;nt.c=e2[i].c;q.push(nt);
        }
    }
}

signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,c;
        cin>>u>>v>>c;
        addEdge(u,v,c);
        addEdge(v,u,c);
    }
    find_bst();
    //cout<<ans<<'\n';
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    if(k==0){
        cout<<ans<<'\n';
        return 0;
    }//(1<<k)
    for(int num=1;num<(1<<k);num++){
          // cout<<"STH"<<num<<'\n';
        sum=0;
        for(int i=1;i<=k;i++){
            if((num>>(i-1))&1){
                sum+=c[i];
            }
        }
        if(sum>ans) continue;
        for(int i=1;i<=n+k;i++){
            h2[i]=0;
        }
        tot2=0;
        for(int i=1;i<=kkk;i++){
            addEdge2(p[i].u,p[i].v,p[i].c);
            addEdge2(p[i].v,p[i].u,p[i].c);
            //cout<<p[i].u<<' '<<p[i].v<<' '<<p[i].c<<'\n';
        }
        for(int i=1;i<=k;i++){
            if((num>>(i-1))&1){
                //sum+=c[i];
                for(int j=1;j<=n;j++){
                    addEdge2(n+i,j,a[i][j]);
                    addEdge2(j,n+i,a[i][j]);
                    //cout<<n+i<<' '<<j<<' '<<a[i][j]<<'\n';
                }
            }
            //cout<<sum<<' ';
        }
   // for(int i=1;i<=n+k;i++){
    //    for(int j=h2[i];j;j=e2[j].nxt){
     //       cout<<i<<' '<<e2[j].v<<' '<<e2[j].c<<'\n';
    //   }
    //
        while(!q.empty())   q.pop();
        memset(vis,0,sizeof(vis));
        res=0;
        find_bst2();
        ans=min(ans,res+sum);
    }
    cout<<ans<<'\n';
    return 0;
}
