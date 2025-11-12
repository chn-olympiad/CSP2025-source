#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N=1e4+15;
const int M=4e6+5;

struct edge{
	int nxt,from,to;
	ll dist;
} e[M];

struct node{
	int from;
	ll dist;
	bool operator<(const node& b)const{
		return b.dist<dist;
	}
};

int n,m,tot,k,lste[N],lst[N];
ll c[N],ans,dis[N],pre[N]; 
bitset<N> vis;
bitset<M> need;

// 最短路 

void fun(int t){
	if(t==0) return;
	need[lste[t]]=1;
	fun(lst[t]);
}

void dijkstra(){
	for(int i=1;i<=n+k;i++) dis[i]=-1;
	dis[1]=0;
	node cur={1,0};
	priority_queue<node> q;
	q.push(cur);
	while(!q.empty()){
		cur=q.top();
		q.pop();
		int from=cur.from,dist=cur.dist;
		if(vis[from]) continue;
		vis[from]=1;
		for(int i=pre[from];i;i=e[i].nxt){
			int to=e[i].to;
			if(dis[to]==-1||dis[to]>=dist+e[i].dist){
				dis[to]=dist+e[i].dist;
				lste[to]=i;
				lst[to]=from;
				if(!vis[to]){
					q.push({to,dis[to]});
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		fun(i);
	}
	for(int i=1;i<=tot;i++){
		if(need[i]){
			ans+=e[i].dist;
//			cerr<<"需要修复第"<<i<<"条的从"<<e[i].from<<"到"<<e[i].to<<"的长度为"<<e[i].dist<<"的道路"<<endl;
		}
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v;
		ll w;
		cin>>u>>v>>w;
		e[++tot].nxt=pre[u];
		e[tot].to=v;
		e[tot].dist=w;
		e[tot].from=u;
		pre[u]=tot;
		e[++tot].nxt=pre[v];
		e[tot].to=u;
		e[tot].dist=w;
		e[tot].from=v;
		pre[v]=tot;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			ll v;
			cin>>v;
			e[++tot].nxt=pre[j];
			e[tot].to=i+n;
			e[tot].dist=v+c[i];
			e[tot].from=j;
			pre[j]=tot;
			e[++tot].nxt=pre[i+n];
			e[tot].to=j;
			e[tot].dist=v;
			e[tot].from=i+n;
			pre[i+n]=tot;
		} 
	}
	dijkstra();
	cout<<ans<<endl;
	return 0;
}

