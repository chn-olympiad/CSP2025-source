#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+7,M=1e6+7,inf=(1<<31)-1;

int head[N],dis[N],cnt,vis[N],flag[N];
int n,m,k;
ll ans;

struct Graph{
    int u,v,w;
    int next;

}edge[2*M];

void init(int n,int m){
 for(int i=1;i<=n;i++) {
    head[i]=-1;
    dis[i]=inf;
 }
 for(int i=1;i<=m;i++){
    edge[i].next=-1;
 }
}

void add(int u ,int v,int w){
    edge[++cnt]={u,v,w,head[u]};
    head[u]=cnt;
}

void dfs(int s){
    priority_queue< pair<int,int> >q;
    dis[s]=0; q.push( {-dis[s],s} );
    for(int k=head[s];~k;k=edge[k].next){
        auto u=q.second();q.pop();
        int v=edge[k].v,w=edge[k].w;
        if(vis[k]==0&&dis[v]>dis[u]+w){
            dis[v]=dis[u]+w;
            vis[v]=1;
            q.push( {-dis[v],v} );
        }
    }
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    init(n,m);
    for(int i=1;i<=m;i++){
    int from,to,val;
    scanf("%d%d%d",&from,&to,&val);
    add(from,to,val);
    add(to,from,val);
    }
	int a[N];
    for(int i=1;i<=k;i++){
      for(int j=i+1;j<=n;j++){
        int c;
        scanf("%d%d",&c,&a[j]);
        add(i,j,a[j]+c/(n-1) );
        add(j,i,a[j]+c/(n-1) );
      }
    }
    dfs(1);
    for(int i=1;i<=n;i++){
        ans+=dis[i];
    }
    printf("%lld",ans);
return 0;
}