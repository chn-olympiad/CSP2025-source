#include <bits/stdc++.h>
using namespace std;
#define il inline
#define pb push_back
#define fi first
#define se second
using ll=long long;
using pii=pair<int,int>;
const int N=1e4+50,M=2e6+5;
int n,m,K;
int a[N][N];
ll ans,dis[N];
bool vis[N];
void prim() {
	vis[1]=1;
	for(int i=1;i<=n;i++) dis[i]=a[1][i];
	for(int i=1;i<n;i++) {
		pii t={2e9,0};
		for(int j=1;j<=n;j++) {
			if(vis[j]) continue;
			if(dis[j]<t.fi) {
				t.fi=dis[j];
				t.se=j;
			}
		}
		ans+=t.fi;
		vis[t.se]=1;
		for(int j=1;j<=n;j++) dis[j]=min(dis[j],(ll)a[t.se][j]);
	}
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&K);
	for(int i=1;i<=n+K;i++) {
		for(int j=1;j<=n+K;j++) {
			a[i][j]=2e9;
		}
		a[i][i]=0;
	}
	for(int i=1;i<=m;i++) {
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		a[x][y]=a[y][x]=min(a[x][y],c);
	}
	for(int i=1;i<=K;i++) {
		scanf("%d",&a[n+i][0]);
		for(int j=1;j<=n;j++) {
			scanf("%d",&a[n+i][j]);
			a[j][n+i]=a[n+i][j];
		}
	}
	n+=K;
	prim();
	printf("%lld",ans);
	return 0;
}

