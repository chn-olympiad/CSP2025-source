#include<bits/stdc++.h>
#define MAXN 10010
#define MAXM 1000010
#define MAXK 11
using namespace std;
typedef long long ll;
struct node{
	int from,to,w;
	node(const int from=0,const int to=0,const int w=0){
		this->from=from;
		this->to=to;
		this->w=w; 
	}
	inline friend bool operator<(const node &a,const node &b){
		return a.w<b.w;
	}
};
vector<node> edge;
int n,m,k,fa[MAXN+MAXK],c[MAXN],a[MAXK][MAXN];
inline int get(const int x){
	return fa[x]==x?x:fa[x]=get(fa[x]);
}
inline int read(){
	register int res=0,f=1;
	register char c=getchar();
	while(!isdigit(c)){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(isdigit(c)){
		res=(res<<1)+(res<<3)+(c^'0');
		c=getchar();
	}
	return res*f;
}
namespace Sub1{
	inline void Main(){
		for(register int i=1;i<=k;++i){
			for(register int j=1;j<=n;++j){
				edge.push_back(node(n+i,j,a[i][j]));
			}
		} 
		sort(edge.begin(),edge.end());
		for(register int i=1;i<=n+k;++i){
			fa[i]=i;
		}
		register ll res=0;
		for(register size_t i=0;i<edge.size();++i){
			const int fx=get(edge[i].from),fy=get(edge[i].to);
			if(fx^fy){
				res+=edge[i].w;
				fa[fx]=fy;
			}
		}
		printf("%lld",res);
	} 
}
namespace Sub2{
	ll ans=1e18;
	inline ll Kruskal(vector<node> edge){
		sort(edge.begin(),edge.end());
		for(register int i=1;i<=n+k;++i){
			fa[i]=i;
		}
		register ll res=0;
		for(register size_t i=0;i<edge.size();++i){
			const int fx=get(edge[i].from),fy=get(edge[i].to);
			if(fx^fy){
				res+=edge[i].w;
				fa[fx]=fy;
			}
			if(res>=ans){
				return 1e18;
			}
		}
		return res;
	}
	inline void dfs(const int &dep,const ll &cost){
		if(cost>=ans){
			return;
		}
		if(dep==k+1){
			ans=min(ans,Kruskal(edge)+cost);
			return;
		}
		dfs(dep+1,cost);
		for(register int i=1;i<=n;++i){
			edge.push_back(node(n+dep,i,a[dep][i]));
		}
		dfs(dep+1,cost+c[dep]);
		for(register int i=1;i<=n;++i){
			edge.pop_back();
		}
	}
	inline void Main(){
		dfs(1,0);
		printf("%lld",ans);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(register int i=1;i<=m;++i){
		const int u=read(),v=read(),w=read();
		edge.push_back(node(u,v,w));
	} 
	register bool F=true;
	for(register int i=1;i<=k;++i){
		c[i]=read();
		if(c[i]){
			F=false;
		}
		for(register int j=1;j<=n;++j){
			a[i][j]=read();
//			edge.push_back(node(n+i,j,a[i][j]));
		} 
	}
	if(F){
		Sub1::Main();
		return 0;
	}
	Sub2::Main();
	return 0;
}
