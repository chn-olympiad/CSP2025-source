#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+50;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
int n,m,k,fa[N],cnt,dis[N],c[N];
inline int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
struct edge{
	int x,y,z,s;
	inline bool operator<(edge b){
		return z<b.z;
	}
}e[N*100],g[N*11];
vector<pair<int,int>>v[N],w;
inline void dfs(int x,int fa){
	for(auto t:v[x]){
		int y = t.first,z=t.second;
		if(y==fa)continue;
		dis[y]=max(dis[x],z);
		dfs(y,x);
	}
} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i = 1;i<=m;i++)e[i].x=read(),e[i].y=read(),e[i].z=read();
	for(int i = 1;i<=n;i++)fa[i]=i;
	sort(e+1,e+m+1);
	long long ww = 0;
	for(int i = 1;i<=m;i++){
		if(find(e[i].x)!=find(e[i].y)){
			g[++cnt]=e[i];g[cnt].s = 0;
			ww+=e[i].z;
			fa[find(e[i].x)]=find(e[i].y);
		}
	}
//	cout<<ww<<endl;
	for(int i = 1;i<=cnt;i++)v[g[i].x].push_back({g[i].y,g[i].z}),v[g[i].y].push_back({g[i].x,g[i].z});
	for(int i = 1;i<=k;i++){
		c[i]=read();
		w.clear();
		for(int j = 1;j<=n;j++)w.push_back({read(),j});
		sort(w.begin(),w.end());
		c[i]+=w[0].first;
		dis[w[0].second]=0;dfs(w[0].second,0);
		for(int j = 1;j<n;j++){
			if(dis[w[j].second] > w[j].first)g[++cnt]={w[0].second,w[j].second,w[j].first,(1<<i-1)};
		}
	}
	sort(g+1,g+cnt+1);
	long long ans = 1e18;
	for(int s = 0;s<(1<<k);s++){
		long long sum = 0;
		for(int i = 1;i<=k;i++)if(s&(1<<i-1))sum+=c[i];
		for(int i = 1;i<=n+k;i++)fa[i]=i;
		int w = n-1+__builtin_popcount(s);
		for(int i = 1;i<=cnt&&w;i++){
			if((s&g[i].s)==g[i].s){
				int x=find(g[i].x),y=find(g[i].y);
				if(x!=y)w--,sum+=g[i].z,fa[x]=y;
			}
		}
		ans=min(ans,sum);
	} 
	cout<<ans;
	return 0;
}


