#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN=10000+20;
typedef long long ll;

struct node{
    ll v,w;
};

struct edge{
    int u,v,w;
};

int n,m,k;
vector<node> G[MAXN];
ll c[MAXN];
ll a[20][MAXN];
edge e[1200010];
int fa[MAXN];

void init(){
    for(int i=1;i<=n+k;i++) fa[i]=i;
}

int find(int x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}

bool same(int x,int y){
    return find(x)==find(y);
}

void unite(int x,int y){
    int xn=find(x),yn=find(y);
    if(xn==yn) return ;
    fa[xn]=yn;
    return ;
}

bool cmp(edge e1,edge e2){
    return e1.w<e2.w;
}

ll kruscal(int nm,int nt){
    init();
    edge e1[MAXN];
    for(int i=1;i<=nm;i++){
        e1[i]=e[i];
    }
    sort(e1+1,e1+1+nm,cmp);
    ll ans=0,cnt=0;
    //cout<<nm<<endl;
    for(int i=1;i<=nm;i++){
        int x1=e1[i].u,x2=e1[i].v;
        //cout<<x1<<" "<<x2<<" "<<e[i].w<<" "<<same(x1,x2)<<endl;
        if(same(x1,x2)) continue;
        unite(x1,x2);
        ans+=e1[i].w;
        cnt++;
        if(cnt>=nt-1) break;
    }
    //cout<<endl;
    return ans;
}

ll all=0x7f7f7f7f;
bool vis[15];

void dfs(int u,int cnt){
    if(u>k){
        int ret=m;
        ll pos=0;
        for(int i=1;i<=k;i++){
            if(vis[i]){
                pos+=c[i];
                for(int j=1;j<=n;j++){
                    //cout<<"ret:"<<ret<<endl;
                    e[++ret]=(edge){i+n,j,a[i][j]};
                }
            }
        }
        //cout<<ret<<endl;
        all=min(all,kruscal(ret,cnt+n)+pos);
        return ;
    }
    vis[u]=true;
    dfs(u+1,cnt+1);
    vis[u]=false;
    dfs(u+1,cnt);
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        e[i]=(edge){u,v,w};
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    dfs(1,0);
    cout<<all<<endl;
    return 0;
}
