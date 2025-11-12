#include<bits/stdc++.h>
#include<bits/extc++.h>
#define int long long
inline int read(){
	int x=0,f=1; char ch; ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isalnum(ch)) x=x*10+ch-'0',ch=getchar();
	return x*f;
}
inline void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
const int maxn=1e4+100;
inline int min(int x,int y){
	if(x<y) return x;
	return y;
}
int n,m,k,a[12][maxn],c[12],u,v,w,dis[maxn],choose[12],cnt,sum=LLONG_MAX;
bool flag=1;
std::bitset<maxn> pd;
struct node{
	int to,val;
};
std::vector<node> vec[maxn],edg[maxn];
struct qnode{
	int id,val;
	inline bool operator <(const qnode& x) const{
		return val>x.val;
	}
};
std::priority_queue<qnode> q;
inline int prim(){
	memset(dis,0x3f,sizeof(dis));
	q.push({1,0}); dis[1]=0; int ans=0; pd=0;
	while(!q.empty()){
		auto p=q.top(); q.pop();
		if(pd[p.id]) continue;
		pd[p.id]=1; ans+=p.val; if(p.id>n) ans+=c[p.id-n];
		for(auto y:vec[p.id]) if(!pd[y.to]&&dis[y.to]>y.val){
			dis[y.to]=y.val;
			q.push({y.to,dis[y.to]});
		}
		if(p.id<=n){
			for(auto y:edg[p.id]) if(!pd[y.to]&&dis[y.to]>y.val){
				dis[y.to]=y.val;
				q.push({y.to,dis[y.to]});
			}
		}
	}
	return ans;
}
inline void init(){
	for(int i=1;i<=n+k;++i) vec[i].clear();
	for(int i=1;i<=cnt;++i){
		int id=choose[i];
		for(int j=1;j<=n;++j) vec[id+n].push_back({j,a[id][j]}),vec[j].push_back({id+n,a[id][j]});
	}
}
inline void dfs(int x){
	if(x==k){
		init();
		sum=min(sum,prim());
		return ;
	}
	choose[++cnt]=x+1;
	dfs(x+1); cnt--; dfs(x+1);
}
inline void work(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(); m=read(); k=read();
	for(int i=1;i<=m;++i) u=read(),v=read(),w=read(),edg[u].push_back({v,w}),edg[v].push_back({u,w});
	for(int i=1;i<=k;++i){
		c[i]=read(); flag&=(c[i]==0); int tmp=0;
		for(int j=1;j<=n;++j) a[i][j]=read(),tmp|=(a[i][j]==0);
		flag&=tmp;
	}
	if(flag){
		for(int i=1;i<=k;++i) choose[++cnt]=i;
		init();
		sum=prim();
	}
	else dfs(0); 
	write(sum);
}
signed main(){work();return 0;}