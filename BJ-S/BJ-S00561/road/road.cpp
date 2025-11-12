#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
constexpr int N=1e4+5,M=1e6+5,K=15;
using ll=long long;
int n,m,k;
int a[K][N],c[K];
int head[N+K],to[(M<<1)+K*(N<<1)],val[(M<<1)+K*(N<<1)],nxt[(M<<1)+K*(N<<1)],cnt;
void add(int u,int v,int w){
    to[++cnt]=v;
    val[cnt]=w;
    nxt[cnt]=head[u];
    head[u]=cnt;
}
int f[N];
bool vis[N];
ll sum=0;
struct node{
    int f,id;
    bool operator<(const node& right)const{
        return f>right.f;
    }
};
priority_queue<node> q;
void prim(int s=1){
    for(int i=1;i<=n+k;i++) f[i]=2e9,vis[i]=0;
    sum=0;
    f[s]=0;
    q.push(node{0,s});
    while(!q.empty()){
        auto t=q.top();
        // cerr<<t.f<<' '<<t.id<<'\n';
        q.pop();
        if(vis[t.id]) continue;
        vis[t.id]=1;
        sum+=t.f;
        int u=t.id;
        for(int i=head[u];i;i=nxt[i]){
            if(f[to[i]]>val[i]){
                f[to[i]]=val[i];
                q.push(node{f[to[i]],to[i]});
            }
        }
    }
}
ll ans0=-1;
int cnt0;
int tag[K];
int head0[N+K];
void dfs(int p){
    if(p>k){
        cnt=cnt0;
        memcpy(head,head0,sizeof(head));
        ll sumc=0;
        for(int i=1;i<=k;i++){
            if(tag[i]){
                sumc+=c[i];
                for(int j=1;j<=n;j++){
                    add(n+i,j,a[i][j]);
                    add(j,n+i,a[i][j]);
                }
            }
        }
        prim();
        // cerr<<"1:"<<sum+sumc<<'\n';
        if(ans0!=-1) ans0=min(ans0,sum+sumc);
        else ans0=sum+sumc;
        return;
    }
    tag[p]=1;
    dfs(p+1);
    tag[p]=0;
    dfs(p+1);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1,x,y,z;i<=m;i++){
        cin>>x>>y>>z;
        add(x,y,z);
        add(y,x,z);
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++) cin>>a[i][j];
    }
    if(k==0){
        prim();
        cout<<sum<<'\n';
    }
    else{
        cnt0=cnt;
        memcpy(head0,head,sizeof(head));
        dfs(1);
        cout<<ans0<<'\n';
    }
    return 0;
}