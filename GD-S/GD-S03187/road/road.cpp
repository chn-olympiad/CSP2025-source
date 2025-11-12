#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e4;
const int MAXM=1e6;
const int MAXK=10;
int n,m,k;
struct Edge {
	int u,v,w;
} e[MAXM+MAXN*MAXK+10];
struct City {
	int c;
	int a[MAXN+10];
} ct[MAXK+10];
int fa[MAXN+MAXK+10];
int find(int x) {
	return (fa[x]==x)?x:fa[x]=find(fa[x]);
}
bool mycmp(Edge x,Edge y) {
	return x.w<y.w;
}
void read(int &x) {
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return;
}
int main(void) {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);
	read(m);
	read(k);
	for(int i=1; i<=n+k; i++) {
		fa[i]=i;
	}
	for(int i=1; i<=m; i++) {
		read(e[i].u);
		read(e[i].v);
		read(e[i].w);
	}
	for(int i=1; i<=k; i++) {
		read(ct[i].c);
		for(int j=1; j<=n; j++) {
			read(ct[i].a[j]);
		}
	}
	if(k==0) {
		sort(e+1,e+1+m,mycmp);
		long long ans=0;
		for(int i=1; i<=m; i++) {
			int fu=find(e[i].u),fv=find(e[i].v);
			if(fu!=fv) {
				ans+=e[i].w;
				fa[fu]=fv;
			}
		}
		printf("%lld\n",ans);
		return 0;
	} else {
		for(int i=1; i<=k; i++) {
			for(int j=1; j<=n; j++) {
				++m;
				e[m].u=j;
				e[m].v=n+i;
				e[m].w=ct[i].a[j];
			}
		}
		sort(e+1,e+1+m,mycmp);
		long long ans=0;
		for(int i=1; i<=m; i++) {
			int fu=find(e[i].u),fv=find(e[i].v);
			if(fu!=fv) {
				ans+=e[i].w;
				fa[fu]=fv;
			}
		}
		printf("%lld",ans);
		return 0;
	}
	return 0;
}
