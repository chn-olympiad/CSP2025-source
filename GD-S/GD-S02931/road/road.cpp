#include<bits/stdc++.h>
using namespace std;
#define time 1000*clock()/CLOCKS_PER_SEC
#define int long long
bool mst;
const int N=5e3+10,inf=1e9+10;
int fa[N],n,m,k,ne[N],p;
int find(int x){return fa[x]==x?x:(fa[x]=find(fa[x]));}
struct node{
	int u,v,w; 
	node(){w=inf;}
	bool friend operator<(node a,node b){return a.w<b.w;}
}b[N*N];
bool med;
int fd(int x,int y){
	b[(x-1)*n+y].u=x,b[(x-1)*n+y].v=y;
	return (x-1)*n+y;
}
void init(){
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
		b[fd(j,i)].w=b[fd(i,j)].w=min(b[fd(i,j)].w,p+ne[i]+ne[j]);
	}
}
int kruskal(){
	sort(b,b+n*n+1);
	int cnt=0,ans=0;
	for(int i=n+1;i<=n*n;i++){
		int u=b[i].u,v=b[i].v;
		if(find(u)!=find(v)){
			ans+=b[i].w;cnt++;
			fa[find(u)]=fa[find(v)];
		}
		if(cnt==n-1)break;
	}
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)fa[i]=i,b[fd(i,i)].w=0;
	for(int i=1;i<=m;i++){
		int x,y,w;scanf("%lld%lld%lld",&x,&y,&w);
		b[fd(x,y)].w=b[fd(y,x)].w=w;
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&p);
		for(int j=1;j<=n;j++)scanf("%lld",&ne[j]);
		init();
	}
	printf("%lld\n",kruskal());
	return 0;
}
