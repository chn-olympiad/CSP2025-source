#include<bits/stdc++.h>
using namespace std;
const int N=1e4+15, INF=1e9+1;
struct edge{
	int u,v,w;
	bool operator<(const edge &x) const{
		return w<x.w;
	}
};
int n,fa[N],sz[N],m,k,S,c[15],vis[N],ct[N];
vector<edge> e;
int read(){
	int x=0;
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) x=(x*10)+(ch-'0'),ch=getchar();
	return x;
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y) return;
	if(sz[x]<sz[y]) swap(x,y);
	fa[x]=y;
	sz[y]+=sz[x];
}
void init(){
	for(int i=1;i<=n+k;i++) fa[i]=i,sz[i]=ct[i]=0;
}
bool check(int S,int v){
	if(v>n) return (S>>(v-n-1))&1;
	return 1;
}
long long kruskal(int S){
	long long ans=0,cnt=n+__builtin_popcount(S);
	init();
	for(edge a:e){
		int u=a.u,v=a.v,w=a.w;
		if(check(S,v)==0||check(S,u)==0) continue;
		if(find(u)==find(v)) continue;
		merge(u,v);
		cnt--;
		ct[u]++,ct[v]++;
		ans+=w;
		if(cnt==1) return ans;
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		e.emplace_back((edge){u,v,w});
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			int w=read();
			e.emplace_back((edge){n+i,j,w});
		}
	}
	sort(e.begin(),e.end());
	long long ans=1e18;
	for(int i=0;i<(1<<k);i++){
		long long cnt=0;
		bool flag=1;
		for(int j=1;j<=k;j++){
			bool g=(i>>(j-1))&1;
			cnt+=g*c[j];
			if(g&&vis[j+n]) flag=0;
		}
		if(!flag) continue;
		cnt+=kruskal(i);
		for(int j=1;j<=k;j++) vis[j+n]|=(ct[j+n]==1);
		ans=min(cnt,ans);
	}
	printf("%lld",ans);
}
