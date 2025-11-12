#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+1e5+5;
int n,m,k,fa[N<<1],c[15];long long ans;
struct node {
	int x,y,w;
	bool operator<(const node &u) const {return w<u.w;}
}a[M],t[15][N],b[M];
inline int find(int x) {return fa[x]==x?x:(fa[x]=find(fa[x]));}
inline void dfs(int x,long long now,int nn) {
	if(now>=ans) return ;
	if(x>k) {
		for(int i=1;i<=n+k;++i) fa[i]=i;
		int l=0;long long anss=now;
		for(int i=1;i<=m&&l<nn-1&&anss<ans;++i) {
			int x=find(a[i].x),y=find(a[i].y);
			if(x!=y) anss+=1ll*a[i].w,++l,fa[x]=y;
		}
		ans=min(ans,anss);
		return ;
	}
	dfs(x+1,now,nn);
	int mm=0;
	for(int i=1,j=1;i<=m||j<=n;) {
		if(i<=m&&(j>n||a[i]<t[x][j])) b[++mm]=a[i],++i;
		else b[++mm]=t[x][j],++j;
	}
	m+=n;
	for(int i=1;i<=m;++i) a[i]=b[i];
	dfs(x+1,now+c[x],nn+1);mm=0;
	for(int i=1;i<=m;++i) if(a[i].x!=n+x) b[++mm]=a[i];m-=n;
	for(int i=1;i<=m;++i) a[i]=b[i];
	return ;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;++i) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].w);
	sort(a+1,a+1+m);
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1,l=0;i<=m;++i) {
		int x=find(a[i].x),y=find(a[i].y);
		if(x!=y) fa[x]=y,ans+=1ll*a[i].w,b[++l]=a[i];
	}
	for(int i=1;i<n;++i) a[i]=b[i];m=n-1;
	for(int i=1;i<=k;++i) {
		scanf("%d",c+i);
		for(int j=1;j<=n;++j) scanf("%d",&t[i][j].w),t[i][j].x=i+n,t[i][j].y=j;
		sort(t[i]+1,t[i]+1+n);
	}
	dfs(1,0,n);
	printf("%lld\n",ans);
	return 0;
}