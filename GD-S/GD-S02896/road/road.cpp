#include <bits/stdc++.h>
using namespace std;
long long f[11000];
long long find(long long x){
	if (f[x] == x){
		return x;
	}
	f[x] = find(f[x]);
	return f[x];
}
void merge(long long x, long long y){
	x = find(x);
	y = find(y);
	if (x == y){
		return;
	}
	f[x] = y;
	return;
}
pair<long long, pair<long long, long long> > e[1200000];
pair<long long, pair<long long, long long> > ee[110000];
long long c[11000];
long long a[11000][20];
int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	long long n, m, k;
	cin >> n >> m >> k;
	for (long long i = 1; i <= n; i++){
		f[i] = i;
	}
	for (long long i = 1; i <= m; i++){
		long long x, y, w;
		cin >> x >> y >> w;
		e[i] = {w, {x, y}};
	}
	sort(e + 1, e + m + 1);
	long long ans = 0;
	long long tot = 0;
	for (long long i = 1; i <= m; i++){
		if (find(e[i].second.first) != find(e[i].second.second)){
			ans += e[i].first;
			merge(e[i].second.first, e[i].second.second);
			ee[++tot] = e[i];
		}
	}
	for (long long i = 1; i <= tot; i++){
		e[i] = ee[i];
	}
	for (long long i = tot + 1; i <= m; i++){
		e[i] = {0, {0, 0}};
	}
	m = tot;
//	cout << ans << '\n';
	for (int i = 1; i <= k; i++){
		cin >> c[i];
		for (int j = 1; j <= n; j++){
			cin >> a[j][i];
			e[++m] = {a[j][i], {j, n + i}};
		}
	}
	sort(e + 1, e + m + 1);
	for (long long i = 1; i < (1 << k); i++){
		long long sum = 0;
		int pp = 0;
		for (int j = 1; j <= k; j++){
			if ((i & (1 << (j - 1))) != 0){
				pp = j;
				sum += c[j];
			}
		}
		for (long long j = 1; j <= n + k; j++){
			f[j] = j;
		}
		long long num = 0;
		for (long long j = 1; j <= m; j++){
			if (e[j].second.second > n && (i & (1 << (e[j].second.second - n - 1))) == 0){
				continue;
			}
			if (e[j].second.first > n && (i & (1 << (e[j].second.first - n - 1))) == 0){
				continue;
			}
			if (find(e[j].second.first) != find(e[j].second.second)){
				num += e[j].first;
				merge(e[j].second.first, e[j].second.second);
			}
		}
		ans = min(ans, num + sum);
//		cout << num + sum << " " << ans + sum << '\n';
	}
	cout << ans << '\n';
	return 0;
}
