#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5,M=1e4+5;
struct node{
	int w,u,v;
}e[N];
int n,m,k,ans,cnt;
int c[15],a[15][M],f[N]; 
bool vis[M],flag[M][M];
vector<pair<int,int> > g[M];
int dfs(int u,int v,int s) {
	if (u==v) {
		return s;
	}
	for (auto t:g[u]) {
		if (vis[t.first]) continue;
		vis[t.first]=1;
		int x=dfs(t.first,v,s+t.second);
		if (x) return x;
	}
	return 0;
}
bool cmp(node a,node b) {
	return a.w<b.w;
}
int find(int x) {
	if (f[x]==x) return x;
	return f[x]=find(f[x]); 
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	for (int i=1;i<=k;i++) {
		cin>>c[i];
		for (int j=1;j<=n;j++) {
			cin>>a[i][j];
		}
	}
	if (k<=0) {
		for (int i=1;i<=n;i++) f[i]=i;
		sort(e+1,e+1+m,cmp);
		for (int i=1;i<=m;i++) {
			int u=e[i].u,v=e[i].v,w=e[i].w;
			int fu=find(u),fv=find(v);
			if (fu!=fv) {
				f[fu]=fv;
				ans+=w;
			}
		}
		cout<<ans;
	}else {
		for (int i=1;i<=n;i++) f[i]=i;
		sort(e+1,e+1+m,cmp);
		for (int i=1;i<=m;i++) {
			int u=e[i].u,v=e[i].v,w=e[i].w;
			int fu=find(u),fv=find(v);
			if (fu!=fv) {
				f[fu]=fv;
				ans+=w;
				g[u].push_back({v,w});
				g[v].push_back({u,w});
			}
		}
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) {
				if (i==j) continue;
				int s=dfs(i,j,0);
				ans-=s;
				for (int z=1;z<=k;z++) {
					int sum=c[z];
					bool f1=0,f2=0;
					if (!flag[n+z][i]) {
						f1=1;
						flag[n+z][i]=flag[i][n+z]=1;
						sum+=a[z][i];
					}
					if (!flag[n+z][j]) {
						f2=1;
						flag[n+z][j]=flag[j][n+z]=1;
						sum+=a[z][j];
					}
					if (sum<s) {
						s=sum;
					}else {
						if (f1) flag[n+z][i]=flag[i][n+z]=0;
						if (f2) flag[n+z][j]=flag[j][n+z]=0;
					}
				}
				ans+=s;
			}
		}
		cout<<ans;
	}
	return 0;
}
