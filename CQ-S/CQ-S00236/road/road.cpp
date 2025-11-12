#include<bits/stdc++.h>
#define ll long long
using namespace std;
namespace zzy{
	const int maxn=2e4+10;
	const int maxm=1e6+10;
	const ll INF=1e18;
	int n,m,k;
	ll ans;
	int c[maxn];
	struct Graph{
		int x,y,w;
		bool operator < (const Graph &it)const{
			return w<it.w;
		}
	}e[maxm];
	int fa[maxn],sz[maxn];
	int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
	inline int merge(int x,int y){
		x=find(x),y=find(y);
		if(x==y)return 0;
		if(sz[x]<sz[y])swap(x,y);
		fa[y]=x;
		sz[x]+=sz[y];
		return 1;
	}
	int vis[maxn];
	inline ll solve(ll sum){
		for(int i=1;i<=n+k;i++)fa[i]=i,sz[i]=1;
		for(int i=1;i<=m;i++){
			if(!vis[e[i].x]||!merge(e[i].x,e[i].y))continue ;
			sum+=e[i].w;
			if(sum>=ans)return INF;
		}
		return sum;
	}
	int main(){
		cin>>n>>m>>k;
		for(int i=1;i<=m;i++)cin>>e[i].x>>e[i].y>>e[i].w;
		sort(e+1,e+m+1);
		for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1;
		for(int i=1,cnt=0;i<=m;i++){
			if(!merge(e[i].x,e[i].y))continue ;
			e[++cnt]=e[i];
		}
		m=n-1;
		for(int i=1;i<=k;i++){
			cin>>c[i];
			for(int x=1,w;x<=n;x++)cin>>w,e[++m]={n+i,x,w};
		}
		sort(e+1,e+m+1);
		for(int i=1;i<=n;i++)vis[i]=1;
		ans=INF;
		for(int s=0;s<(1<<k);s++){
			ll sum=0;
			for(int i=1;i<=k;i++){
				vis[n+i]=0;
				if((s>>i-1)&1)vis[n+i]=1,sum+=c[i];
			}
			ans=min(ans,solve(sum));
		}
		cout<<ans<<'\n';
		
		return 0;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	zzy::main();
	return 0;
}
//12MB
/*
ÎÒÃÇÏ²»¶Âí¼Îì÷£¬¶¡³ÌöÎ£¬ËÎÑÇÐù 
*/
