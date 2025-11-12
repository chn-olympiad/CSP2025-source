#include <bits/stdc++.h>
using namespace std;
struct node{
	int v,w;
	bool operator<(const node& x)const{
		return v<x.v;
	}
};
vector<node> a[10020];
multiset<node> t[10020];
bool done[10020];
int n,m,k;
int c[20];
int b[20][10010];
struct Edge{
	int u,v,w;
	bool operator<(const Edge& x)const{
		return w<x.w;
	}
};
struct cmp{
	bool operator()(const Edge& x,const Edge& y){
		return x.w>y.w;
	}
};
vector<Edge>e;
vector<int> ne;
struct bcj{
	int fa[1020];
	int size[1020];
	void init(int n){
		for (int i=1;i<=n;i++){
			fa[i]=i;
			size[i]=1;
		}
	}
	int getfa(int x){
		return fa[x]==x ? x : fa[x]=getfa(fa[x]);
	}
	void merge(int x,int y){
		x=getfa(x);
		y=getfa(y);
		if (size[x]<size[y]) swap(x,y);
		fa[y]=x;
		size[x]+=size[y];
	}
}h;
int dis[1020];
int vis[1020];
priority_queue<Edge,vector<Edge>,cmp> q;
void dfs(int x,int fa){
	for (node i:t[x]){
		if (i.v==fa) continue;
		h.merge(i.v,x);
//		printf("%d",i.w);
		dfs(i.v,x);
	}
}
int main(){
	srand(time(0));
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		a[u].push_back({v,w});
		a[v].push_back({u,w});
		e.push_back({u,v,w});
	}
	for (int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for (int j=1;j<=n;j++){
			scanf("%d",&b[i][j]);
			a[n+i].push_back({j,b[i][j]});
			a[j].push_back({n+i,b[i][j]});
			e.push_back({n+i,j,b[i][j]});
		}
	}
	int r=rand()%n+1;
	q.push({0,1,0});
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[1]=0;
//	for (int i=1;i<=n;i++) printf("%d ",a[i].size());
	int ans=0;
	while(!q.empty()){
		int d=q.top().w;
		int u=q.top().v;
		int from=q.top().u;
		q.pop();
		if (vis[u]==1) continue;
		vis[u]=1;
		if (from!=0){
			ans+=d;
			if (u>n) d-=c[u-n];
			t[u].insert({from,d});
			t[from].insert({u,d});
		}
//		printf("%d\n",u);
//		printf("\n%d;\n",a[u].size());
		for (node raw:a[u]){
//			printf("%d %d\n",raw.v,u);
//			printf("%d ",raw.w);
			node i=raw;
			if (i.v>n) i.w+=c[i.v-n];
			if (!vis[i.v] && dis[i.v]>i.w){
				dis[i.v]=i.w;
				q.push({u,i.v,i.w});
			}
		}
	}
//	printf("%d\n",ans);
//	for (int i=1;i<=n+k;i++){
//		for (node j:t[i]){
//			printf("%d %d\n",i,j.v);
//		}
//	}
//	exit(0);
	sort(e.begin(),e.end());
	for (int i=n+k;i<=n+1;i--){
		if (t[i].size()==1){
			continue;
		}
		else{
//			printf("%d",t[i].size());
			h.init(n+k);
			int sum=c[i-n];
			int minn=0;
			for (node eg:t[i]){
				dfs(eg.v,i);
				sum+=eg.w;
			}
			
			for (Edge eg:e){
				int x=h.getfa(eg.u);
				int y=h.getfa(eg.v);
				if (x==y || x==i || y==i || done[x] || done[y]) continue;
				h.merge(x,y);
//				printf("%d %d\n",eg.u,eg.v);
				minn+=eg.w;
				t[eg.u].insert({eg.v,eg.w});
			}
//			printf("%d",minn);
			
			if (minn<sum){
				ans-=sum;
				ans+=minn;
				for (node eg:t[i]){
					t[eg.v].erase({i,eg.w});
				}
				multiset<node> _;
				swap(t[i],_);
				done[i]=1;
			}
//			printf("%d\n",ans);
//			exit(0);
		}
	}
	for (int i=n+1;i<=n+k;i++){
		if (t[i].size()==1){
			ans-=(*(t[i].begin())).w;
			ans-=c[i-n];
		}
	}
	printf("%d",ans);
	
	return 0;
}












