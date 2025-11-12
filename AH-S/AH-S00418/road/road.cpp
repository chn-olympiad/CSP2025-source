#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXN 2000005
using namespace std;
typedef long long ll;
int n,m,k;
ll P[MAXN];
ll C[15][10005];
int fa[MAXN],cnt;
ll ans;

void init(int n){
    for(int i=1;i<=n;i++)
        fa[i]=i;
    return ;
}

int find(int x){
    if(x==fa[x]) return x;
    return fa[x]=find(fa[x]);
}

void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y) return ;
    fa[y]=x;
    return ;
}

bool same(int x,int y){
    return find(x)==find(y);
}

struct node{
    int u,v;
    ll w;
}g[MAXN],G[MAXN];

bool cmp(node x,node y){
    return x.w<y.w;
}


int pr[MAXN];
ll Kruscal(){

    ll sum=0;
    int N=n,M=m;
    for(int i=1;i<=m;i++)
        g[i]=G[i];

    for(int i=1;i<=k;i++){
        if(pr[i]){
            N++;
            sum+=C[i][0];

            for(int j=1;j<=n;j++){
                if(P[i]+C[i][j]<ans){
                    g[++M]=(node){N,j,C[i][j]};
                }
            }

        }
    }

    init(N);
    sort(g+1,g+M+1,cmp);
    cnt=0;
    for(int i=1;i<=M;i++){
        if(!same(g[i].u,g[i].v)){
            unite(g[i].u,g[i].v);
            cnt++;
            sum+=g[i].w;
            //cout<<sum<<endl;
        }
        if(cnt==N-1) break;
    }
    //cout<<M<<" "<<cnt<<" :"<<sum<<endl;
    return sum;
}
void dfs(int x){
    if(x==k+1){
        //for(int i=1;i<=k;i++) cout<<pr[i]<<" ";
        //cout<<endl;
        ans=min(ans,Kruscal());
        return ;
    }
    //cout<<x<<endl;
    if(P[x]+C[x][0]<ans){
        pr[x]=1;
        dfs(x+1);
        pr[x]=0;
    }
    dfs(x+1);
    return ;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        G[i]=(node){u,v,w};
    }
    init(n);
    sort(G+1,G+m+1,cmp);
    for(int i=1;i<=m;i++){
        if(!same(G[i].u,G[i].v)){
            unite(G[i].u,G[i].v);
            cnt++;
            ans+=G[i].w;
        }
        if(cnt==n-1) break;
    }
    //cout<<ans<<endl;
    for(int i=1;i<=k;i++){
        cin>>C[i][0];
        ll minn=0x3f3f3f3f3f3f3f3f;
        for(int j=1;j<=n;j++){
            cin>>C[i][j];
            minn=min(minn,C[i][j]);
        }
        P[i]=minn*2;
    }

    dfs(1);

    cout<<ans<<endl;

    return 0;
}
