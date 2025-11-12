#include<bits/stdc++.h>
using namespace std;
const int M=1e7+1e6+10,N=1e4+10;
int fa[N];
long long ans=0;
int n,m,k,faa=1,mm;
int c[12][N];
struct edge {
	int u,v;
	long long w;
	bool operator<(const edge &a)const {
		return w<a.w;
	}
} e[M],ie[M];
void in() {
	faa=1;
	cin>>n>>m>>k;
	mm=m;
	for(int i=1; i<=m; i++) {
		cin>>e[i].u>>e[i].v>>e[i].w;
		ie[i]=e[i];
	}
	for(int i=1; i<=k; i++) {
		for(int j=0; j<=n; j++) {
			cin>>c[i][j];
		}
		if(c[i][0]!=0)faa=0;
	}
}
int find(int x) {
	int xx=x,t;
	while(fa[xx]!=xx)xx=fa[xx];
	while(xx!=x) {
		t=fa[x];
		fa[x]=xx;
		x=t;
	}
	return x;
}
void init() {
	for(int i=1; i<=n+k; i++)fa[i]=i;
	m=mm;
	for(int i=1; i<=m; i++)e[i]=ie[i];
}
long long kruskal() {
	long long res=0;
	sort(e+1,e+1+m);
	for(int i=1; i<=m; i++) {
		int u=e[i].u,v=e[i].v;
		long long w=e[i].w;
		int fu=find(u),fv=find(v);
		if(fu==fv)continue;
		fa[fu]=fv;
		res+=w;
	}
	return res;
}
long long work(int s) {
	long long res=0;
	for(int kk=1; kk<=k; kk++) {
		if(((1<<(kk-1))&s)==0)continue;
		res+=c[kk][0]*1ll;
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				e[++m].u=i;
				e[m].v=j;
				e[m].w=c[kk][i]+c[kk][j];
			}
		}
	}
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	in();
	init();
	if(k==0) {
		ans=kruskal();
	} else if(faa) {
		for(int kk=1; kk<=k; kk++) {
			for(int i=1; i<=n; i++) {
				for(int j=i+1; j<=n; j++) {
					e[++m].u=i;
					e[m].v=j;
					e[m].w=c[kk][i]+c[kk][j];
				}
			}
		}
		ans=kruskal();
	} else {
		ans=LLONG_MAX;
		for(int i=(1<<k)-1; i>=0; i--) {
			long long lans=0;
			init();
			lans=work(i);//¼Ó±ß
//			cout<<i<<" "<<lans<<" ";
			lans+=kruskal();
//			cout<<lans<<endl;
			ans=min(ans,lans);
		}
	}
	cout<<ans<<endl;
	return 0;
}
