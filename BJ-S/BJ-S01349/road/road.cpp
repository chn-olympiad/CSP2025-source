#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,p[10100],c[12]; array<int,3> arr[1000010];
array<int,2> cs[12][10100];
int g[12],gg = 0,cur[12];
int find(int x) {return (p[x]==x)?(x):(p[x]=find(p[x]));}
signed main() {
	freopen("road.in","r",stdin); freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++) p[i] = i;
	for(int i = 1; i <= m; i++) cin >> arr[i][1] >> arr[i][2] >> arr[i][0];
	sort(arr+1,arr+1+m); int cc = 0;
	for(int i = 1; i <= m; i++) {
		int u = find(arr[i][2]),v = find(arr[i][1]);
		if(u == v) continue;
		p[u] = v; arr[++cc] = arr[i];
	}
	for(int _ = 1; _ <= k; _++) {
		cin >> c[_];
		for(int i = 1; i <= n; i++) {cin >> cs[_][i][0]; cs[_][i][1] = i;}
		sort(cs[_]+1,cs[_]+n+1);
	}
	int ans = 0x3f3f3f3f3f3f3f3f;
	for(int msk = 0; msk < (1<<k); msk++) {
		gg = 0; int sum = 0; for(int i = 1; i <= k; i++) {
			if(msk>>(i-1)&1) g[++gg] = i,cur[gg] = 1,sum += c[i];
		} cur[0] = 1;
		for(int i = 1; i <= n+gg; i++) p[i] = i;
		int enu = 0; while(enu < n+gg-1) {
			int mi = (cur[0]<n)?arr[cur[0]][0]:0x3f3f3f3f3f3f3f3f,plc = 0;
			for(int i = 1; i <= gg; i++) {
				if(cur[i] > n) continue;
				if(mi > cs[g[i]][cur[i]][0]) plc = i,mi = cs[g[i]][cur[i]][0];
			}
			if(!plc) {
				int u = find(arr[cur[0]][2]),v = find(arr[cur[0]][1]);
				cur[0]++; if(u == v) continue;
				p[u] = v; sum += mi;
			} else {
				int u = find(cs[g[plc]][cur[plc]][1]),v = find(n+plc);
				cur[plc]++; if(u == v) continue;
				p[u] = v; sum += mi;
			} enu++;
		} ans = min(ans,sum);
	} cout << ans;
	return 0;
}
