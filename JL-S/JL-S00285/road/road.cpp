#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,u,v,w,W,dis[N],ii,ans,k,vis[N],head[N],tot,to,cnt,d;
struct node{
	int nxt,v,w;
}e[N];
struct lis{
	int u,d;
};
bool operator <(const lis &a,const lis &b){
	return a.d>b.d;
}
void add(int u,int v,int w){
	e[++cnt]={head[u],v,w};
	head[u]=cnt;
}
priority_queue<lis>q;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	if(k!=0){
		for(int i=1;i<=k;i++){
			scanf("%d",&W);
			for(int j=1;j<=n;j++){
				scanf("%d",&w);
				add(n+i,j,W+w);
				add(j,n+i,W+w);
			}
		}
	}
	n=n+k;
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	q.push({1,0});
	while(!q.empty()){
		if(tot>=n){
			break;
		}
		d=q.top().d;
		u=q.top().u;
		q.pop();
		if(vis[u]==1){
			continue;
		}
		vis[u]=1;
		ans=ans+d;
		tot++;
		for(int i=head[u];i;i=e[i].nxt){
			w=e[i].w;
			v=e[i].v;
			if(w<dis[v]){
				dis[v]=w;
				q.push({v,w});
			}
		}
	}
	cout<<ans;
    return 0;
}
