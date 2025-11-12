#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N=1.2e3+5;
const int M=1e4+5;

int n,m,k;
int c[11],a[11][M];
int dis[N][N];
struct Seg {
	int u,v,w;
}seg[2000010];

bool cmp(Seg x,Seg y) {
	return x.w<y.w;
}

int fa[M];
int getf(int x) {
	if(fa[x]==x) return x;
	return fa[x]=getf(fa[x]);
}
void merge(int x,int y) {
	fa[getf(x)]=getf(y);
}

void solve() {
	for(int i=1;i<=m;++i)
		std::cin>>seg[i].u>>seg[i].v>>seg[i].w;
	sort(seg+1,seg+m+1,cmp);
	int ans=0,cnt=0;
	for(int i=1;i<=m;++i) {
		int x=seg[i].u,y=seg[i].v;
		if(getf(x)!=getf(y)) {
			++cnt;
			merge(x,y);
			ans+=seg[i].w;
			if(cnt==n-1) break;
		}
	} 
	std::cout<<ans<<'\n';
}

signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	
	memset(dis,0x3f3f3f3f,sizeof dis);
	
	std::cin>>n>>m>>k;
	for(int i=1;i<=n;++i) fa[i]=i;
	if(k==0) solve();
	else {
		for(int i=1;i<=m;++i)
		std::cin>>seg[i].u>>seg[i].v>>seg[i].w;
		for(int i=1;i<=k;++i) {
			std::cin>>c[i];
			for(int j=1;j<=n;++j) 
			std::cin>>a[i][j];
			for(int j=1;j<=n;++j) 
				for(int k=1;k<=n;++k) 
					if(j!=k && dis[j][k]>a[i][j]+a[i][k]+c[i])
						dis[j][k]=a[i][j]+a[i][k]+c[i];
		}
		int tot=m;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j) 
				if(i!=j) 
					seg[++tot].u=i,
					seg[tot].v=j,
					seg[tot].w=dis[i][j];
		sort(seg+1,seg+tot+1,cmp);
		int ans=0,cnt=0;
		for(int i=1;i<=tot;++i) {
			int x=seg[i].u,y=seg[i].v;
			if(getf(x)!=getf(y)) {
				++cnt;
				merge(x,y);
				ans+=seg[i].w;
				if(cnt==n-1) break;
			}
		} 
		std::cout<<ans<<'\n';
	}
	return 0;
}