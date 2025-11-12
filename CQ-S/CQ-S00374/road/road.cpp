#include<bits/stdc++.h>
#define int long long
#define N 20005
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();} 
	while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*f;
}
int n,m,k;
int ans=1e18;
int c[N],vis[N],l[N],fa[N];
pair<int,int> f[N];
vector<pair<int,int> > g[N];
int Find(int x){
	return x==fa[x]?x:fa[x]=Find(fa[x]);
}
void sol(int p){
	int sum=0,s=n;
	for(int j=0;j<k;j++){
		vis[n+j+1]=0;
		if((p>>j)&1) vis[n+j+1]=1,sum+=c[j+1],s++;
	} 
	if(sum>=ans) return;
	for(int i=1;i<=n+k;i++) l[i]=0,fa[i]=i;
	while(s>1){
		for(int i=1;i<=n+k;i++) f[i]={1e18,0};
		for(int i=1;i<=n+k;i++){
			if(!vis[i]) continue;
			while(l[i]<g[i].size()&&(Find(i)==Find(g[i][l[i]].second)||!vis[g[i][l[i]].second])) l[i]++;
			if(l[i]<g[i].size()) f[Find(i)]=min(f[Find(i)],g[i][l[i]]);
		}
		for(int i=1;i<=n+k;i++){
			if(!vis[i]||i!=Find(i)||f[i].second==0) continue;
			if(Find(i)!=Find(f[i].second)){
				sum+=f[i].first;
				if(sum>=ans) return;
				s--;
				fa[Find(i)]=Find(f[i].second);
			} 
		}
	}
	ans=min(ans,sum);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1,u,v,w;i<=m;i++){
		u=read();v=read();w=read();
		g[u].push_back({w,v});
		g[v].push_back({w,u});
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1,x;j<=n;j++) x=read(),g[n+i].push_back({x,j}),g[j].push_back({x,n+i});
		sort(g[n+i].begin(),g[n+i].end());
	}
	for(int i=1;i<=n;i++) sort(g[i].begin(),g[i].end()),vis[i]=1;
	for(int i=0;i<(1<<k);i++) sol(i);
	printf("%lld\n",ans);
	return 0;
}
