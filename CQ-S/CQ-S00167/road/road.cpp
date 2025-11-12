#include<bits/stdc++.h>
#define inf 9223372036854775807
#define int long long 
using namespace std;
int h[30005],nxt[3000005],to[3000005],ct[3000005],vis[3000005],dis[30005];
int cnt=0;
int n,m,k;
int init[3000005][4]; 
int c[15];
int t[15][30005];
void addedge(int u,int v,int w){
	to[++cnt]=v;
	ct[cnt]=w;
	nxt[cnt]=h[u];
	h[u]=cnt;
}
int fa[30005];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void uni(int x,int y){
	int a=find(x),b=find(y);
	if(a==b) return;
	fa[a]=b;
}
int prim(int id){
	for(int i=1;i<=id;i++) dis[i]=inf;
	priority_queue<pair<int,int> > q;
	q.push({0,1});
	int ans=0;
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		uni(u,1);
		for(int i=h[u];i;i=nxt[i]){
			int v=to[i],w=ct[i];
			if(find(v)==find(u)) continue;
			if(dis[u]+w<dis[v]){
				ans=-dis[v]+dis[u]+w;
				dis[v]=dis[u]+w;
			}
			q.push({-dis[v],v});
		}
	}
	
	return ans;
}
int work(int s){//传递第i个乡镇是否进行城市化  
	memset(h,0,sizeof(h));
	memset(nxt,0,sizeof(nxt));
	memset(vis,0,sizeof(vis));
	memset(to,0,sizeof(to));
	memset(ct,0,sizeof(ct));
	cnt=0;
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	int ans=0;
	for(int i=1;i<=m;i++){
		int u=init[i][0],v=init[i][1],w=init[i][2];
		addedge(u,v,w);
		addedge(v,u,w);
	}
	int id=n;
	for(int i=1;i<=k;i++){
		if(s&(1<<(i-1))){//有  
			ans+=c[i];
			id++;
			for(int j=1;j<=n;j++){
				int u=id,v=j,w=t[i][j];
				addedge(u,v,w);
				addedge(v,u,w);
			}
		}
	}
	ans+=prim(id);
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>init[i][0]>>init[i][1]>>init[i][2];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>t[i][j];
		}
	}
	int minn=inf;
	for(int i=(1<<k)-1;i>=0;i--){
	//	cout<<work(i)<<" ";
		minn=min(minn,work(i));
	}
	cout<<minn;
	return 0;
} 
