#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
inline void printt(int x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x>9) printt(x/10);
	putchar(x%10+'0');
}
inline void print(int x){
	printt(x);
	puts("");
}
inline int read(){
	char c;
	int res=0,flag=1;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			flag=-1;
			c=getchar();
			break;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		res=res*10+c-'0';
		c=getchar();
	}
	return res*flag;
}
const int N=1e4+100;
const int M=1e6+100;
int n,m,k,a[11][N],c[11],fa[N],ans=0x3f3f3f3f,U[M],V[M],W[M],tmp;
inline int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
inline void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy) fa[fx]=fy;
}
struct node{
	int u,w;
};
struct edge{
	int u,v,w;
};
inline bool cmp(edge a,edge b){
	return a.w<b.w;
}
std::vector<edge> E;
std::vector<node> G[N];
inline void kruscal(){
	for(int i=1;i<=n;i++) fa[i]=i;
	ans=0;
	std::sort(E.begin(),E.end(),cmp);
	for(int i=0;i<(int)E.size();i++){
		int u=E[i].u,v=E[i].v;
		if(find(u)!=find(v)){
			ans+=E[i].w;
			merge(u,v);
		}
	}
	print(ans);
}
inline int KK(int nn){
	for(int i=1;i<=nn;i++) fa[i]=i;
	std::sort(E.begin(),E.end(),cmp);
	for(int i=0;i<(int)E.size();i++){
		int u=E[i].u,v=E[i].v;
		if(find(u)!=find(v)){
			tmp+=E[i].w;
			merge(u,v);
		}
	}
	return tmp;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int u,v,w,i=1;i<=m;i++){
		U[i]=u=read(),V[i]=v=read(),W[i]=w=read();
		G[u].push_back({v,w});
		G[v].push_back({u,w});
		E.push_back({u,v,w});
	}
	int cccnt=k;
	for(int i=1;i<=k;i++){
		c[i]=read();
		cccnt-=c[i];
		for(int j=1;j<=n;j++) a[i][j]=read();
	}
	if(k==0){
		kruscal();
		return 0;
	}else if(cccnt==k){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++) E.push_back({n+i+1,j,a[i][j]});
		}
		print(KK(n+k));
	}else{
		int cnt=0;
		for(int i=0;i<(1<<k)-1;i++){
			E.clear();
			tmp=0;
			for(int i=1;i<=m;i++) E.push_back({U[i],V[i],W[i]});
			for(int j=0;j<k;j++){
				if((i>>j)&1){
					tmp+=c[j+1];
					for(int l=1;l<=n;l++) E.push_back({n+j+1,l,a[j+1][l]});
					cnt++;
				}
			}
			ans=std::min(ans,KK(n+cnt));
		}
		print(ans);
	}
	return 0;
}

