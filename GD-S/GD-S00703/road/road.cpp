#include<stdio.h>
#include<vector>
#include<queue>
#define vec std::vector
#define int long long
const int N=1e4+15,INF=1e9+5;
int n,m,k,cnt=0,city=0;
struct edge{
	int to,w;
};
vec<int> cost(N,0);
vec<bool> f(N,false),build(N,false); 
vec<edge> e[N];
struct node{
	int from,to,dis;
	node(int z,int x,int y){from=z;to=x;dis=y;}
	bool operator < (const node & a)const{return dis>a.dis;}
};
long long Prim(){
	std::priority_queue<node>q;
	q.push(node(0,1,0));
	long long ans=0;
	while(!q.empty()){
		node p=q.top();
		q.pop();
		if(f[p.to])
			continue;
		//printf("from:%d to:%d dis:%d \n",p.from,p.to,p.dis);
		if(p.to<=n)city++;
		f[p.to]=true;
		if(p.to>n){
			if(build[p.to])
				p.dis-=cost[p.to];
			else{
				build[p.to]=true;
				//printf("build%d has been over\n",p.to);
			}
		}
		ans+=p.dis;
		if(city==n)break;
		for(int u=0;u<e[p.to].size();u++){
			edge i=e[p.to][u];
			if(f[i.to])
				continue;
			if(i.to>n&&!build[i.to])i.w+=cost[i.to];
			q.push(node(p.to,i.to,i.w));
		}
	}
	return ans;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(int i=1+n;i<=k+n;i++){
		int w;
		scanf("%d",&w);
		cost[i]=w;
		e[0].push_back({i,w});
		for(int j=1;j<=n;j++){
			int to;
			scanf("%d",&to);
			e[j].push_back({i,to});
			e[i].push_back({j,to});
		}
	}/*
	for(int i=0;i<=n+k;i++){
		printf("dot%d[",i);
		for(auto j:e[i]){
			printf("from:%d to:%d w:%d;\n",i,j.to,j.w);
		}printf("]\n\n");
	}*/
	printf("%lld",Prim());
	return 0;
}
