#include<bits/stdc++.h>
#define int long long

/*
1s 1e8
U9 285K/xin/xin
*/

using namespace std;

const int N=10055,M=1000055,K=15,INF=1e16;

int n,m,k;
vector<pair<int,int>> vec[N];

int c[K],a[K][N];

int fa[N];
inline int find(int u) {
	if(fa[u]==u) return u;
	return fa[u] = find(fa[u]);
}

struct Node {int u,v,w;}pth[M],kpth[K][N];
int tot,kp[K];

signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	cin >> n >> m >> k;

	int u,v,w;
	for(int i=1;i<=m;++i) {
		cin >> u >> v >> w;
		vec[u].push_back({v,w});
		vec[v].push_back({u,w});
		pth[i] = {u,v,w};
	}

	for(int i=0;i<k;++i) {
		cin >> c[i];
		for(int j=1;j<=n;++j) cin >> a[i][j];
		for(int j=1;j<=n;++j) {
			kpth[i][j]={n+i+1,j,a[i][j]};
		}
		sort(kpth[i]+1,kpth[i]+1+n,[](Node& a,Node& b) {
			return a.w<b.w;
		});
	}

	sort(pth+1,pth+1+m,[](Node& a,Node& b) {
		return a.w<b.w;
	});
	iota(fa+1,fa+1+n,1);

	for(int i=1;i<=m;++i) {
		auto& [u,v,w] = pth[i];
		if(find(u)!=find(v)) {
			kpth[k][++tot] = pth[i];
			fa[find(u)] = find(v);
		}
	}

	int ans=INF,cnt=0,lcnt=0;
	for(int j=(1<<(k+1))-1;j>=(1<<k);--j) {
		cnt=0,lcnt=0;
		for(int i=0;i<k;++i)
			if(j&(1<<i)) cnt+=c[i],++lcnt;
		
		for(int i=0;i<=k;++i) kp[i]=1;
		iota(fa+1,fa+1+n+k,1);
		
//		cout << "P" << n-1+lcnt << endl;
		for(int p=1;p<=n-1+lcnt;++p) {
			int mn=-1;
			for(int i=0;i<=k;++i) {
				if(!(j&(1<<i))) continue;
				while(kpth[i][kp[i]].u && find(kpth[i][kp[i]].u) == find(kpth[i][kp[i]].v)) ++kp[i];
				if(!kpth[i][kp[i]].u) continue;
				if(mn==-1 || kpth[i][kp[i]].w < kpth[mn][kp[mn]].w) mn=i;
			}

			fa[find(kpth[mn][kp[mn]].u)] = find(kpth[mn][kp[mn]].v);
			cnt += kpth[mn][kp[mn]++].w;
//			cout << "CT" << cnt << ' ' << mn << ' ' << kpth[mn][kp[mn]-1].w << endl;
		}

		ans = min(ans,cnt);
//		cout << cnt << endl;
	}

	cout << ans << '\n';

	return 0;
}