# include <bits/stdc++.h>
# define int long long
# define N 10010
# define M 1000010
using namespace std;
inline int read() {
	int w=0,f=1; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
	for(;isdigit(ch);ch=getchar()) w=(w<<1)+(w<<3)+(ch^48);
	return w*f;
}
struct D {
	int w,x,y;
	bool operator <(const D &v) const {
		return w<v.w;
	}
}G[M];
int n,m,k,ans,tp,fa[N];
int find(int x) {
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
int c;
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
//	if(!k) {
	for(int i=1;i<=m;i++) 
	  G[++tp].x=read(),G[tp].y=read(),G[tp].w=read();
	for(int i=1;i<=k;i++) {
	  c=read();
	  for(int j=1,v;j<=n;j++) {
	    v=read();
	    if(!v) {
	      int p=find(G[i].x),q=find(G[i].y);
	      if(p!=q) fa[q]=p;
		}
//		else G[++tp].x=i,G[tp].y=j,G[tp].w=v;
	  }
	}
	sort(G+1,G+1+tp);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=tp;i++) {
	  int p=find(G[i].x),q=find(G[i].y);
	  if(p!=q) ans+=G[i].w,fa[q]=p;
	}
	printf("%lld",ans);
//	}
	return 0;
}
//4 4 2
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//1 1 8 2 4
//100 1 3 2 4
