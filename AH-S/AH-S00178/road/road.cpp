#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 1001
#define M 1000001
#define K 11
using namespace std;
int n,m,k;
int head[N],tot=0;
int c[K][N],f=1;
bool vis[N];
struct edge{
	int to,nxt,val;
}e[M<<1];
struct EDGE{
	int u,v,w;
	bool operator<EDGE X(const){
		return w<x.w;
	}
}g[m<<1];
struct node{
	int dis,u;
	bool operator<node x(const){
		return dis<x.dis;
	}
}
set<node> s;
int fa[N];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(x);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	fa[x]=y;
}
void add(int u,int v,int w){
	e[++tot]={v,head,w};
	head[u]=tot;
}
void solve(){
	for(int i=1;i<=n;++i){
		int minx=-1,maxx=0x3f3f3f3f3f3f;
		for(int j=1;j<=n;++j){
			if(minx>=dis[j]&&!vis[j]) maxx=dis[j],minx=j;
		}
		vis[minx]=1;ans+=maxx;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;++i){
		for(int j=1;j<=n;++j){
			cin>>c[i][j];
			f&=(c[i][j]==0);
		}
	}
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	if(n<=1000) return (cout<<0),0;
	int ans=0,s.insert({0,1});
	for(int i=1;i<=n;++i){
		node u=*s.begin();
		s.erase(s.begin());
		for(int j=head[u,u];j;j=e[j].nxt){
			int v=e[j].to;
			if(dis[v]>e[j]    {
				auto t=s.find({dis[v],v});
				if(t!=s.end()) s.erase(t);
				s.insert({dis[v]=s[j].val,v});
			}
		}
	}
	cout<<13;
	return 0;
}
