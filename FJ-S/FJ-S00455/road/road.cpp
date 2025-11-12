#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+100,M=1e6+5,K=11;
//edge:M+10*N
struct edge{int u,v,w;int req;}e[M],nwc[K][N],tmp[K][N*10];//<40MB
int n,m,c[K],k; //0MB
bool vis[(1<<K)+10]; //0MB

bool cmp(const edge& a,const edge& b){return a.w<b.w;}

struct bcj{
	int fa[N],siz[N];
	int get(int n){return n==fa[n]?n:fa[n]=get(fa[n]);}
	inline void add(int u,int v){
		u=get(u),v=get(v);
		if(siz[u]>siz[v])swap(u,v);
		fa[u]=v,siz[v]+=siz[u];
	}
	inline void pre(int n){for(int i=1;i<=n;++i)fa[i]=i;}
}b1;

ll ans=0;

void dfs(int dep,int siz,int s,int u,int ad){
	//merge
	int ps=0;
	for(int i=1,j=1;i<=siz||j<=n;){
		if(i>siz)tmp[dep][++ps]=nwc[u][j++];
		else if(j>n)tmp[dep][++ps]=tmp[dep-1][i++];
		else{
			if(nwc[u][j].w>tmp[dep-1][i].w)tmp[dep][++ps]=tmp[dep-1][i++];
			else tmp[dep][++ps]=nwc[u][j++];
		}
	}
	//tree
	b1.pre(n+10);
	ll ansl=0;
	int cnt=0;
	for(int i=1;i<=ps;++i){
		//cerr<<tmp[dep][i].u<<' '<<tmp[dep][i].v<<' '<<tmp[dep][i].w<<'\n';
		if(b1.get(tmp[dep][i].u)!=b1.get(tmp[dep][i].v)){
			b1.add(tmp[dep][i].u,tmp[dep][i].v);
			ansl+=tmp[dep][i].w;
			tmp[dep][++cnt]=tmp[dep][i];
		}
	}
	ans=min(ans,ansl+c[u]+ad);
	//nxt
	s|=(1<<u);
	//cerr<<s<<' '<<u<<' '<<ansl<<' '<<ansl+c[u]<<'\n';
	vis[s]=1;
	for(int i=1;i<=k;++i)if(!vis[s|(1<<i)])dfs(dep+1,cnt,s,i,c[u]+ad);
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		int u,v,w;cin>>u>>v>>w;e[i]={u,v,w};
	}
	sort(e+1,e+m+1,cmp);
	int cnt=0;
	b1.pre(n);
	for(int i=1;i<=m;++i){
		if(b1.get(e[i].u)!=b1.get(e[i].v)){
			b1.add(e[i].u,e[i].v);
			ans+=e[i].w;
			tmp[0][++cnt]=e[i];
		}
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j){
			int w;
			cin>>w;
			nwc[i][j]={i+n,j,w};
		}
		sort(nwc[i]+1,nwc[i]+n+1,cmp);
	}
	//cerr<<ans<<'\n';
	for(int i=1;i<=k;++i){
		if(!vis[1<<i])dfs(1,n-1,0,i,0);
	}
	cout<<ans<<'\n';
	return 0;
}

/*
@15:57
CCF 评测机子 1s 能跑多少啊
感觉就算挤牙膏也有 10x 性能提升吧（i7 8700K->U9 285K）
O(2^kn) => 1024 * 10000 => 1e7
大样例 0.7s 
@16:02
空间大概40M没爆 
@16:18
自己造n=10000,k=10,m=1e6，随的，1.2~1.3s 
*/

