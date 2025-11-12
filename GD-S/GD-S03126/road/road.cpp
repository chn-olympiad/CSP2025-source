#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e18;
const int N=1e4+12;
const int M=1.1e6+12;
const int K=12;
int n,m,k,c[K],a[K][N];
inline int read() {
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x;
} 
struct Edge {
	int x,y,z;
} e[M],e2[M],e3[M];
int fa[N],fa2[N];
int ct,tot,res;
inline void init_() {
	for(int i=1;i<N;i++)
		fa[i]=i;
	return ;
}
inline int get_fa(int x) {
	if(x==fa[x]) return x;
	return fa[x]=get_fa(fa[x]);
}
inline int get_fa2(int x) {
	if(x==fa2[x]) return x;
	return fa2[x]=get_fa2(fa2[x]);
}
inline bool cmp(Edge x,Edge y) {
	return x.z<y.z;
}
inline void kruskal() {
	int cnt=0;
	for(int i=1;i<=m;i++) {
		int x=e[i].x,y=e[i].y,z=e[i].z;
		int px=get_fa(x);
		int py=get_fa(y);
		if(px!=py) {
			fa[px]=py;
			e2[++cnt]=e[i];
		}
		if(cnt==n-1)
			return ;
	}
	return ;
}
inline void kruskal2() {
	int cnt=0;
	for(int i=1;i<=tot;i++) {
		int x=e2[i].x,y=e2[i].y,z=e2[i].z;
		int px=get_fa2(x);
		int py=get_fa2(y);
		if(px!=py) {
			fa2[px]=py;
			e3[++cnt]=e2[i];
		}
		if(cnt==ct+n-1)
			return ;
	}
	return ;
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	init_();
	for(int i=1;i<=m;i++)
		e[i].x=read(),e[i].y=read(),e[i].z=read();
	sort(e+1,e+1+m,cmp);
	bool flag=1; 
	for(int i=1;i<=k;i++) {
		c[i]=read();
		if(c[i]) flag=0;
		for(int j=1;j<=n;j++)	
			a[i][j]=read();
	}
	kruskal();
	if(!k) {
		int ans=0;
		for(int i=1;i<n;i++)
			ans+=e2[i].z;
		printf("%lld\n",ans);
		return 0;
	}
	for(int i=1;i<n;i++)
		e[i]=e2[i];
	int ans=inf;
	int st=0;
	if(flag) st=(1<<k)-1;
	for(int s=st;s<(1<<k);s++) {
		tot=n-1,res=0,ct=0;
		for(int i=1;i<=tot;i++)
			e2[i]=e[i];
		for(int i=1;i<=k;i++) {
			if(s&(1<<(i-1))) {
				res+=c[i],ct++;
				for(int j=1;j<=n;j++)
					e2[++tot]=(Edge){n+i,j,a[i][j]};
			}
		}
		sort(e2+1,e2+1+tot,cmp);
		for(int i=1;i<=n+k;i++)
			fa2[i]=i;
		kruskal2();
		for(int i=1;i<n+ct;i++)
			res+=e3[i].z;
		ans=min(res,ans);
	}
	printf("%lld\n",ans);
	return 0;
}
