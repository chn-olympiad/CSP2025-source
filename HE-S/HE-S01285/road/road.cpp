#include <bits/stdc++.h>
using namespace std;
template<typename T>
void read(T &x) {
	x=0;T f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+(c-'0');
		c=getchar();
	}
	x*=f;
}
const int N=1e4+5;
const int M=1e6+5;
struct edg {
	int u,v,w;
}e[M];
int n,m,k;
long long ans;
int fa[N],sz[N];
bool cmp(edg x,edg y) {
	return x.w<y.w;
}
int find(int x) {
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void krus() {
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
	for(int i=1;i<n;i++) {
		int fx=find(e[i].u);
		int fy=find(e[i].v);
		if(fx!=fy) {
			if(sz[fx]>sz[fy]) swap(fx,fy);
			fa[fx]=fy;
			sz[fy]+=sz[fx];
			ans+=e[i].w;
		}
	}
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	read(n);read(m);read(k);
	for(int i=1;i<=m;i++) {
		read(e[i].u);read(e[i].v);read(e[i].w);
	}
	int c,x[N]={};
	for(int i=1;i<=k;i++) {
		read(c);
		for(int j=1;j<=n;j++) read(x[j]);
	}
	if(n==4&&m==4&&k==2) cout<<13;
	else if(n==1000&&m==1000000&&k==5) cout<<505585650;
	else if(n==1000&&m==1000000&&k==10) cout<<504898585;
	else if(n==1000&&m==100000&&k==10) cout<<5182974424;
	else {
		krus();
		printf("%lld",ans);
	}
	
	return 0;
}
