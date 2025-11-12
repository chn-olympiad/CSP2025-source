#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5,K=13,M=1e6+5;
int n,m,k,tot=0,c[K],fa[N+K];
bool can[N+K];
long long ans=0;
struct E {int u,v,w;}edge[M];
bool cmp1(E x,E y) {return x.w<y.w;}
struct Node{int u,v,w;}e[M];
bool cmp2(Node x,Node y) {return x.w<y.w;}
inline int read() {
	int x=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1; ch=getchar();}
	while (ch<='9'&&ch>='0') {x=x*10+ch-48; ch=getchar();}
	return x*f;
}
inline int find(int x) {return x==fa[x]?x:fa[x]=find(fa[x]);}
inline long long Kruskal(int cntn) {
	int ecnt=0,fu,fv,w; long long res=0;
	for (int i=1;i<=tot;i++) {
		fu=find(e[i].u),fv=find(e[i].v),w=e[i].w;
		if (fu!=fv&&can[e[i].u]&&can[e[i].v]) {
			fa[fu]=fv,res+=w,ecnt++;
			if (ecnt==cntn-1) return res;
		}
	}
	return res;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for (register int i(1);i<=m;i++) edge[i].u=read(),edge[i].v=read(),edge[i].w=read();
	sort(edge+1,edge+m+1,cmp1);
	for (register int i(1);i<=n;i++) can[i]=1,fa[i]=i;
	for (int i=1;i<=m;i++) {
		int fu=find(edge[i].u),fv=find(edge[i].v),w=edge[i].w;
		if (fu!=fv) {fa[fu]=fv,ans+=w,e[++tot]={edge[i].u,edge[i].v,edge[i].w};}
	}
	if (!k) {cout<<ans<<"\n";return 0;}
	for (register int i(1);i<=k;i++) {
		c[i]=read();
		for (register int j=1,a;j<=n;j++) a=read(),e[++tot]={n+i,j,a};
	}
	sort(e+1,e+tot+1,cmp2);
	int mx=(1<<k)-1,cntn; long long now=0;
	for (int sta=1;sta<=mx;sta++) {
		cntn=n,now=0;
		for (int i=0;i<k;i++) {
			if (((sta>>i)&1)) cntn++,now+=c[i+1],can[n+i+1]=1;
			else can[n+i+1]=0;
		}
		for (register int i(1);i<=n+k;i++) fa[i]=i;
		ans=min(ans,now+Kruskal(cntn));
	}
	cout<<ans<<"\n";
	return 0;
}