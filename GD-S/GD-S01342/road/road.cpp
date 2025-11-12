#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

inline ll read(){
	ll x=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x;
}

const ll INF=1e18;
const int N=1e4+5;
struct node{
	int to;
	ll w;
};
vector<node> e[N],ne[N];
ll a[N],z[N],n,ans=INF;
bool vis[N];

void build(){
	for(int i=1;i<=n;++i){
		fill(z+1,z+n+1,INF);
		for(auto v:e[i])
			z[v.to]=min(z[v.to],v.w);
		for(int j=1;j<=n;++j)
			if(j!=i){
				ne[i].push_back({j,z[j]});
				
//				printf("%d %d %lld\n",i,j,z[j]);
			}
	}
}

void dfs(int u,int num,ll sum){
//	printf("%d %d %lld\n",u,num,sum);
	if(num==n){
		ans=min(ans,sum);
		return ;
	}
	for(auto x:ne[u]){
		int v=x.to;
		if(vis[v]) continue;
		vis[v]=1;
		dfs(v,num+1,sum+x.w);
		vis[v]=0;
	}
	return ;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m,k;
	scanf("%d%d%d",&n,&m,&k);
	ll w;
	int u,v;
	for(int i=1;i<=m;++i){
		u=read(),v=read(),w=read();
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(int i=1;i<=k;++i){
		int c=read();
		for(int j=1;j<=n;++j) a[j]=read();
		for(int j=1;j<n;++j)
			for(int k=j+1;k<=n;++k){
				e[j].push_back({k,c+a[j]+a[k]});
				e[k].push_back({j,c+a[j]+a[k]});
			}
	}
	build();
	vis[1]=1;
//	printf("!!!\n");
	dfs(1,1,0);
	printf("%lld",ans);
	return 0;
} 
