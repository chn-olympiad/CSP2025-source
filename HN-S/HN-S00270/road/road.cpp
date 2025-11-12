#include<bits/stdc++.h>
using namespace std;
long long g[13006][13006], c[13], a[13][13006], tree[13006] = {1, 1}, tt[13006], ttt[13006] = {0, 1};
struct abc{
	long long start, end, num;
}t[1300006];
bool ccc(abc x,abc y) {
	return x.num< y.num;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	long long n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		long long u, v, w;
		cin >> u >> v >> w;
		g[u][v] = w;
		g[v][u] = w;
	}
	long long ccccc=0;
	for (int j = 1; j <= k; j++) {
		cin >> c[j];
		ccccc++;
		tt[n + ccccc] = c[j];
		for (int i = 1; i <= n; i++) {
			cin >> a[j][i];
			g[n +ccccc][i] = a[j][i];
			g[i][n +ccccc] = a[j][i];
		}
	}
	long long cnt = 0, ans = 0, cccc= 0;
	for (int i = 1; i <= n + ccccc; i++){
		if (g[1][i] != 0) {
			cnt++;
			t[cnt].start = 1;
			t[cnt].end = i;
			t[cnt].num = g[1][i]+tt[i];
		}
	}
	bool flag = 1;
	for (int j = 1; flag; j++) {
		sort(t + j + cccc, t + cnt + 1, ccc);
		ans += t[j].num;
		tree[0]++;
		tree[tree[0]] = t[j].end;
		ttt[t[j].end] = 1;
		for (int i = 1; i <= n + ccccc; i++) {
			if (t[i].end == t[j].end) {
				cccc++;
			}
		}
		flag = 0;
		for (int i =1;i<=n;i++){
			if(ttt[i] != 1) {
				flag = 1;
			} 
		}
		for (int i = 1; i <= n + ccccc; i++){
			if (g[t[j].end][i] != 0) {
				bool ok = 1;
				for (int k = 1; k <= tree[0]; k++) {
					if (i == tree[k]) {
						ok = 0;
					}
				}
				if (ok == 0) {
					continue;
				}
				cnt++;
				t[cnt].start = t[j].end;
				t[cnt].end = i;
				t[cnt].num = g[t[j].end][i] + tt[i];
			}
		}
	}
	cout << ans;
	return 0;
}

