#include<bits/stdc++.h>

using namespace std;

const int N = 2e6 + 10;

struct node{
	int x, y, w;
}a[N], b[N];

bool cmp(const node &a, const node &b){
	return a.w < b.w;
}

int n, m, k, f[N], c[15], d[15][N];
long long ans = 1e18;

int find(int x){
	return f[x] == x ? x : f[x] = find(f[x]);
}

void solve(){
	for(int i = 0; i < (1 << k); i++){
		int top = 0;
		long long sum = 0;
		for(int j = 1; j <= n + k; j++){
			f[j] = j;
		}
		for(int j = 0; j < k; j++){
			if(i >> j & 1){ sum += c[j];
				for(int p = 1; p <= n; p++){
					b[++top] = {p, n + j + 1, d[j][p]};
				}
			}
		}
		if(sum >= ans){
			continue;
		}
		sort(b + 1, b + 1 + top, cmp);
		for(int i1 = 1, i2 = 1, su = 0; (i1 <= m || i2 <= top) && sum < ans; ){
			if(su == n - 1){
				break;
			}
			int x, y, w;
			if(i1 <= m && (i2 > top || a[i1].w < b[i2].w)){
				x = a[i1].x, y = a[i1].y, w = a[i1].w, i1++;
			}else{
				x = b[i2].x, y = b[i2].y, w = b[i2].w, i2++;
			}
			int fx = find(x), fy = find(y);
			if(fx != fy){
				f[fy] = fx, sum += w, su += fx <= n && fy <= n;
			}
		}
		if(sum == 0){
			cout << 0;
			return ;
		}
		ans = min(ans, sum);
	}
	cout << ans << '\n';
}

signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		cin >> a[i].x >> a[i].y >> a[i].w;
	}
	sort(a + 1, a + 1 + m, cmp);
	for(int i = 0; i < k; i++){
		cin >> c[i];
		for(int j = 1; j <= n; j++){
			cin >> d[i][j];
		}
	}
	solve();
	return 0;
}

