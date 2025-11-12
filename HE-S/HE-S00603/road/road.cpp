#include <bits/stdc++.h>
using namespace std;
const int K=10;
const int N=2e4+5;
const int M=2e6+5;
int n,m,k,cnt,u,v;
long long w;
//long long summ;
struct edge{
	int v;
	long long w;
	int next;
}edges[M<<1];
int h[N];
long long c[N];
void add_edge(int u,int v,long long w){
	cnt++;
	edges[cnt].v=v;
	edges[cnt].w=w;
	edges[cnt].next=h[u];
	h[u]=cnt;
}
bool vis[N];
long long dis[N],ans,minn;
void dij(){
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > q;
	q.push(make_pair(0,1));
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		ans+=dis[u];
		for(int i=h[u];i;i=edges[i].next){
			int v=edges[i].v;
			long long w=edges[i].w;
			if(w<dis[v]){
				if(!vis[v]) dis[v]=w,q.push(make_pair(dis[v],v));
			}
		}
	}
}
long long cal[N][K];
long long diss[(1<<K)][N],S,val[N];
//bool vis[(1<<K)];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%d %d %lld",&u,&v,&w);
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&cal[j][i]);
		}
	}
	S=(1<<k)-1;
	dij();
//	for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
//	cout<<endl;
//	cout<<ans<<endl;
	val[0]=ans;
	minn=ans;
	for(int i=1;i<=n;i++) diss[0][i]=dis[i];
	for(int i=1;i<=S;i++){
//		if(val[i]>ans) continue;
		for(int j=1;j<=k;j++){
			if(((1<<(j-1))&i)){
				int L=(i^(1<<(j-1)));
				if(val[L]>ans){
					val[i]=1e14;
					break;
				}
//				if(vis[L]) continue;
				val[i]=c[j];
//				cout<<L<<" "<<i<<" "<<j<<endl;
				long long z=1e14;
				for(int k=1;k<=n;k++){
					diss[i][k]=min(diss[L][k],cal[k][j]);
					z=min(cal[k][j],z);
//					cout<<diss[L][k]<<"!"<<cal[k][j]<<endl;
					val[i]+=diss[i][k];
				}	
				val[i]+=z;
//				cout<<z<<" "<<c[j]<<endl;
//				vis[L]=true;
				break;
			}
		}
//		cout<<i<<" "<<val[i]<<endl;
		minn=min(val[i],minn);
	}
	
	printf("%lld",minn);
	return 0;
}
