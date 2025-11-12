#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1100100;
const ll MX=0x3f3f3f3f3f3f3f3f;
struct dada{
	ll u,w;
};
vector<dada>e[N];
ll n,m,k,kw[N],ans=0,vis[N],vis2[N],dist1[N];
ll aaa[12][N];
dada dist[N];
struct cmp{
	bool operator()(const dada &a,const dada &b){
		return a.w>b.w;
	}
};
void dfs(int x){
	int sum=0;
	priority_queue<dada,vector<dada>,cmp>q;
	q.push({1,0});
	memset(vis2,0x3f,sizeof(vis2));
	vis2[1]=0;
	while(q.size()){
		dada t=q.top();
		//printf("%d %d\n",t.u,t.w);
		q.pop();
		if(vis[t.u]){
			continue;
		}vis[t.u]=1;
		ans+=t.w;
		for(auto i:e[t.u]){
			if(i.w<vis2[i.u]&&!vis[i.u]){
				vis2[i.u]=i.w;
				q.push({i.u,i.w});
			}
		}
	}
}
void dfs1(int x){
	int sum=0;
	priority_queue<dada,vector<dada>,cmp>q;
	q.push({1,0});
	memset(vis2,0,sizeof(vis2));
	memset(dist1,0x3f,sizeof(dist1));
	dist1[1]=0;
	while(q.size()){
		dada t=q.top();
		q.pop();
		if(vis[t.u]){
			continue;
		}vis[t.u]=1;
		ans+=t.w;
		for(auto i:e[t.u]){
			for(int j=1;j<=k;j++){
				if(vis2[j])continue;
				if(dist1[j+n]+aaa[j][i.u]<i.w&&dist1[j+n]+aaa[j][i.u]<dist1[i.u]){
					dist1[i.u]=dist1[j+n]+aaa[j][i.u];
					vis2[j]=1;
					q.push({n+j,dist1[n+j]});
				}
			}
			if(i.w<dist1[i.u]&&!vis[i.u]){
				dist1[i.u]=i.w;
				if(i.u>n)continue;
				q.push({i.u,i.w});
			}
		}
	}
}
void dij(int x){
	//int sum=0;
	priority_queue<dada,vector<dada>,cmp>q;
	q.push({1,0});
	memset(dist,0x3f,sizeof(dist));
	dist[1].w=0;
	while(q.size()){
		dada t=q.top();
		//printf("%d %d\n",t.u,t.w);
		q.pop();
		if(vis[t.u]){
			continue;
		}vis[t.u]=1;
		ans+=t.w;
		for(auto i:e[t.u]){
			if(dist[i.u].w>dist[t.u].w+i.w+kw[i.u]){
				if(kw[i.u]!=0)dist[i.u].u=1;
				else dist[i.u].u=0;
				dist[i.u].w=dist[t.u].w+i.w+kw[i.u];
				q.push({i.u,i.w});
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen(" road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	int f=0;
	for(int i=0;i<m;i++){
		ll a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		e[a].push_back({b,c});
		e[b].push_back({a,c});
	}for(int i=1;i<=k;i++){
		ll a,b;
		scanf("%lld",&a);
		if(a)f=1;
		kw[i+n]=a;
		for(int j=1;j<=n;j++){
			scanf("%lld",&b);
			aaa[i][j]=b;
			e[n+i].push_back({j,b});
			e[j].push_back({i+n,b});
		}
	}if(k==0){
		dfs(1);
		printf("%lld",ans);
		return 0;
	}dfs1(1);
	printf("%lld",ans);
	//dij(1);
	return 0;
} 
