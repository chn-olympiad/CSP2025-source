#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
#define next nxt

const int maxm=1e6,maxn=1e4,maxk=1e1;
/*struct Edge{
	int to,next;
	int w;
}e[maxm*10+105];
int head[maxn+maxk+105],ep=0;
int dis[maxn+maxk+105];
bool vis[maxn+5];*/

struct Poi{
	int u,v,w;
	Poi(){
		u=v=w=0;
	}
	Poi(int a,int b,int c){
		u=a,v=b,w=c;
	}
	bool operator<(const Poi &a)const{
		return w<a.w;
	}
};
vector<Poi> vec;
int c[maxk+5],a[maxk+5][maxn+5];
int n,m,k;

void add(int u,int v,int w){
/*	e[++ep].to=v;
	e[ep].w=w;
	e[ep].next=head[u];
	head[u]=ep;*/
	Poi in;
	in.u=u,in.v=v,in.w=w;
	vec.push_back(in);
	in.v=u,in.u=v;
	vec.push_back(in);
}
/*
priority_queue<pair<int,int> > q;
void Dijkstra(){
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	q.push({0,1});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(int p=head[u]; p; p=e[p].next){
			int v=e[p].to;
			if(dis[v]>dis[u]+e[p].w){
				dis[v]=dis[u]+e[p].w;
				q.push({-dis[v],v});
			}
		}
	}
}*/

template <typename _Tp>
class unionfind_set{
	public:
		vector<int> uf;
		unionfind_set(int n){
			for(int i=0; i<=n; i++){
				uf.push_back(i);
			}
		}
		int find(int x){
			if(x==uf[x]) return x;
			return uf[x]=find(uf[x]);
		}
		void Union(int x,int y){
			uf[find(x)]=uf[find(y)];
		}
};

void Kruskal(){
	unionfind_set<int> uf(n);
	int cnt=0,ans=0;
	sort(vec.begin(),vec.end());
	for(int i=0; cnt<n-1 && i<vec.size(); i++){
//		cout<<i<<" "<<cnt<<" "<<ans<<" "<<vec[i].u<<" "<<vec[i].v<<" "<<vec[i].w<<"\n";
		if(uf.find(vec[i].u)!=uf.find(vec[i].v)){
			uf.Union(vec[i].u,vec[i].v);
			ans+=vec[i].w;
			cnt++;
		}
	}
	printf("%d",ans);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1; i<=m; i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1; i<=k; i++){
		scanf("%d",&c[i]);
		for(int j=1; j<=n; j++){
			scanf("%d",&a[i][j]);
		}
		for(int j=1; j<=n; j++){
			for(int k=1; k<j; k++){
				add(j,k,a[i][j]+a[i][k]),add(k,j,a[i][j]+a[i][k]);
			}
		}
	}	
/*	for(int i=1; i<=n; i++){
		for(int j=head[i]; j; j=e[j].next){
			cout<<i<<" "<<e[j].to<<" "<<e[j].w<<"\n";
		}
	}*/
//	Dijkstra();
	Kruskal();
	return 0; //expect: 16+(0~24) pts
}
