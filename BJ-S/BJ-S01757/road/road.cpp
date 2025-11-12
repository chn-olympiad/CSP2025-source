#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
const int N = 1e4+10;
const int M = 1e6+10;
const int K = 15;
int n,m,k;
struct edge{
	int v,nxt;
	ll w;
}e[M<<1];
int head[N],tote = 0;
void add(int u,int v,ll w){
	e[++tote].v = v;
	e[tote].w = w;
	e[tote].nxt = head[u];
	head[u] = tote;
}
ll a[K][N],c[K];
ll ans = 1e18;
ll dis[N];
bool vis[N];
ll Prim(int tr){
	for(int i=1;i<=n;++i)dis[i] = 1e18,vis[i] = 0;
	dis[1] = 0;
	int V = 0;
	ll sum = 0ll;
	for(int j=1;j<=k;++j){
		if(((1<<(j-1))&tr)) sum += c[j];
	}
	//cout<<sum<<endl;
	while(V < n){
		ll mind = 1e18; 
		int mini = -1;
		for(int i=1;i<=n;++i){
			if(dis[i] < mind && (!vis[i])){
				mind = dis[i];
				mini = i;
			}
		}
		//cout<<mind<<" "<<mini<<endl;
		if(mini == -1)break;
		sum += mind;
		vis[mini] = 1;
		++V;
		for(int i=head[mini];i;i=e[i].nxt){
			int v = e[i].v;
			if(vis[v])continue;
			dis[v] = min(dis[v],e[i].w);
		}
		for(int v=1;v<=n;++v){
			if(vis[v])continue;
			for(int j=1;j<=k;++j){
				if(((1<<(j-1))&tr))dis[v] = min(dis[v],a[j][mini]+a[j][v]);
			}
		}
		//for(int i=1;i<=n;++i)cout<<dis[i]<<" ";
		//cout<<endl;
	}
	//cout<<"&&&"<<sum<<endl;
	if(V == n)return sum;
	else return 1e18;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	int u,v; ll w;
	for(int i=1;i<=m;++i){
		scanf("%d%d%lld",&u,&v,&w);
		add(u,v,w); add(v,u,w);
	}
	//cout<<"---\n";
	bool f = 1;
	for(int i=1;i<=k;++i){
		scanf("%lld",&c[i]);
		f = (f&&(c[i]==0));
		for(int j=1;j<=n;++j)scanf("%lld",&a[i][j]),f = (f&&(a[i][j]==0));
	}
	if(f)printf("0\n");
	else{
		//cout<<"---\n";
		for(int i=0;i<(1<<k);++i){
			ans = min(Prim(i),ans);
		}
		printf("%lld",ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
