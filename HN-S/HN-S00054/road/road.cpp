#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e4 + 5, M = 1e6 + 5;
ll n,m,k,idx;
ll f[N], vis[N];
ll c[15];
ll a[15][N];
ll aa[M],bb[M],cc[M];
vector<ll> g[N], h[N];
struct node {
	ll x,y,w,op;
} e[M];
bool cmp(node l,node r) {
	return l.w < r.w;
}
int find(int x) {
	if(x == f[x]) {
		return x;
	}
	return f[x] = find(f[x]);
}
void merge(int r1,int r2) {
	int x = find(r1),y = find(r2);
	if(x != y) {
		f[x] = y;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out","w", stdout);
	cin >> n >> m >> k;
	for(int i=1; i<=n; i++) {
		g[i].resize(n+1);
		h[i].resize(n+1);
		fill(g[i].begin(), g[i].end(), 1e8);
	}
	for(int i=1; i<=n; i++) {
		f[i] = i;
	}
	for(int i=1; i<=m; i++) {
		cin>>aa[i]>>bb[i]>>cc[i];
		g[aa[i]][bb[i]] = min(g[aa[i]][bb[i]], cc[i]);
		g[bb[i]][aa[i]] = min(g[bb[i]][aa[i]], cc[i]);
	}
	if(k == 0) {
		for(int i=1; i<=m; i++) {
			e[++idx] = {aa[i],bb[i],cc[i]};
		}
		ll ans = 0, sum = 0;
		sort(e+1,e+1+idx,cmp);
		for(int i=1; i<=idx; i++) {
			int x = e[i].x,y = e[i].y,w = e[i].w;
			if(find(x) == find(y)) {
				continue;
			}
			merge(x,y);
			sum++;
			ans+=w;
			if(sum == n-1) {
				break;
			}
		}
		cout<<ans;
		return 0;
	}
	bool ok = true;
	for(int i=1; i<=k; i++) {
		cin>>c[i];
		if(c[i] != 0) {
			ok=false;
		}
		for(int j=1; j<=n; j++) {
			cin>>a[i][j];
			if(a[i][j] != 0) {
				ok = false;
			}
		}
	}
	if(ok) {
		cout<<0;
		return 0;
	}
	for(int i=1; i<=k; i++) {
		for(int j=1; j<n; j++) {
			for(int s=j+1; s<=n; s++) {
				if(g[j][s] > c[i] + a[i][j] + a[i][s]) {
					g[j][s] = c[i] + a[i][j] + a[i][s];
					g[s][j] = c[i] + a[i][j] + a[i][s];
					h[j][s] = i;
					h[s][j] = i;
				}
			}
		}
	}
	for(int j = 1; j<n; j++) {
		for(int s = j+1; s<=n; s++) {
			if(h[j][s]) {
				e[++idx] = {j,s,g[j][s],h[j][s]};
			} else {
				e[++idx] = {j,s,g[j][s],0};
			}
		}
	}
	ll ans = 0, sum = 0;
	sort(e+1,e+1+idx,cmp);
	for(int i=1; i<=idx; i++) {
		int x = e[i].x,y = e[i].y,w = e[i].w, op = e[i].op;
		if(find(x) == find(y)) {
			continue;
		}
		if(op) {
			vis[op]++;
		}
		merge(x,y);
		sum++;
		ans+=w;
		if(sum == n-1) {
			break;
		}
	}
	for(int i=1; i<=k; i++) {
		if(vis[i]) {
			ans -= (vis[i]-1)*c[i];
		}
	}
	cout<<ans;
	return 0;
}
