#include<bits/stdc++.h>
#define N (int)(1e4+5)
#define M (int)(1e6+5)
using namespace std;
typedef struct Edge{
	int to,next,w;
	int from;
}Edge;
Edge e[M<<1];
int ans[N];
int cnt;
int n,m,k;
int fa[N];
inline void unionn(int x,int y);
inline void addEdge(int u,int v,int w);
inline void read(int &num);
inline int find(int x);
inline void solve();
inline void Kus();
inline bool cmp(const Edge &A,const Edge &B);
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int T=1;
	while(T--){
		solve();
	}
	return 0;
}
inline void read(int &num){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		f=(ch=='-')?-1:1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	num=x*f;
}
inline void solve(){
	read(n);
	read(m);
	read(k);
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=m;++i){
		int x,y,z;
		read(x);
		read(y);
		read(z);
		addEdge(x,y,z);
		addEdge(y,x,z);
	}
	Kus();
	sort(ans+1,ans+1+ans[0]);
	int cost=0;
	for(int i=1;i<=ans[0]-k;++i){
		cost+=ans[i];
	}
	printf("%d\n",cost);
}
inline void addEdge(int u,int v,int w){
	e[++cnt].to=v;
	e[cnt].w=w;
	e[cnt].from=u;
}
inline void unionn(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy)fa[fx]=fy;
}
inline int find(int x){
	return (fa[x]==x)?x:fa[x]=find(fa[x]);
}
inline void Kus(){
	sort(e+1,e+1+cnt,cmp);
	for(int i=1;i<=cnt;++i){
		int u=e[i].from;
		int v=e[i].to;
		if(find(v)!=find(u)){
			unionn(u,v);
			ans[++ans[0]]=e[i].w;
			if(ans[0]==n-1){
				return ;
			}
		}else{
			continue;
		}
	}
}
inline bool cmp(const Edge &A,const Edge &B){
	return A.w<B.w;
}
