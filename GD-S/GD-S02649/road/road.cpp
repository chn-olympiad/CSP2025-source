#include<bits/stdc++.h>
#define int long long
using namespace std;
int fa[10010],ans,r[10010][10010],c[10010],t[10010];
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
int tog(int x,int y){
	return find(fa[x])==find(fa[y]);
}
void uni(int x,int y){
	fa[find(x)]=find(y);
}
struct edge{
	int u,v,w;
};
vector<edge> E;
bool cmp_edge(const edge& a,const edge& b){
	return a.w<b.w;
}
int n,m,k,x,y,z;
void tp1(){
	for(int i=1,j,k,l;i<=m;i++){
		scanf("%lld%lld%lld",&j,&k,&l);
		E.push_back({j,k,l});
	}
	sort(E.begin(),E.end(),cmp_edge);
	for(int i=0;i<E.size();i++){
		if(!tog(E[i].u,E[i].v)){
			uni(E[i].u,E[i].v);
			ans+=E[i].w;
		}
	}
	printf("%lld\n",ans);
	exit(0);
}
int read(){
	int x=1,f=0;
	char c=getchar();
	for(;c>'9'||c<'0';c=getchar()) if(c=='-') x=-1;
	for(;c>='0'&&c<='9';c=getchar()) f=(f<<3)+(f<<1)+(c-'0');
	return x*f; 
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	printf("%.6lf\n",sizeof(r)/1024.0/1024.0);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++) fa[i]=i,fill(r[i],r[i]+1+n,INT_MAX);
	if(k==0) tp1();
	for(int i=1,j,k,l;i<=m;i++){
		j=read(),k=read(),l=read();
		if(j>k) swap(j,k);
		r[j][k]=min(r[j][k],l);
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++) t[j]=read();
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				r[j][k]=min(r[j][k],t[j]+t[k]);
//				printf("j=%lld\tk=%lld\tn=%lld\n",j,k,n);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++)
			if(r[i][j]!=INT_MAX)
				E.push_back({i,j,r[i][j]});
	}
	sort(E.begin(),E.end(),cmp_edge);
	for(int i=0;i<E.size();i++){
		if(!tog(E[i].u,E[i].v)){
			uni(E[i].u,E[i].v);
			ans+=E[i].w;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
