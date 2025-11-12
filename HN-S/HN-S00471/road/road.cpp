#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
struct dot{
	long long data;
	int bh;
	bool operator<(const dot a) const{
		return data>a.data;
	}
};
priority_queue<dot> dots;
int c[11];
int a[11][10001];
long long dist[10001];
int vis[10001];
int n,m,k;
int h[10001],nxt[2000002],to[2000002],val[2000002],opt;
void add(int u,int v,int w){
	nxt[++opt]=h[u];
	h[u]=opt;
	to[opt]=v;
	val[opt]=w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)dist[i]=-1;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,w,w);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	dist[1]=0;
	dots.push({0,1});
	dot step;
	while(dots.size()){
		step=dots.top();
		dots.pop();
		if(vis[step.bh])continue;
		vis[step.bh]=1;
		for(int i=h[step.bh];i;i=nxt[i]){
			if(!vis[to[i]]&&(val[i]<dist[to[i]]||dist[to[i]]==-1)){
				dist[to[i]]=val[i];
				dots.push({dist[to[i]],to[i]});
			}
		}
	}
	long long testit;
	long long res=0;	
	for(int i=1;i<=k;i++){//评估是否可以改造 
		testit=0;
		for(int j=1;j<=n;j++){
			if(a[i][j]<dist[j]){
				testit+=dist[j]-a[i][j];
			}
		}
		if(testit>c[i]+a[i][i]){
			dist[i]=a[i][i];
			for(int j=1;j<=n;j++){
				if(a[i][j]<dist[j]){
					dist[j]=a[i][j];
				}
			}
			res+=c[i];
		}
	}
	for(int i=1;i<=n;i++)res+=dist[i];
	cout<<res;
	return 0;
}

