#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pir pair<int, int>
const int M = 2e2 + 5, N = 3e5 + 5;
int T, n, a[N][3], ans, i0, lim, c[5], x[N], id[N];
int f[M][M], g[M][M];
priority_queue<pir> q[5];

inline int mx(int i, int j){
	int res = 0;
	for(int k = 0; k < 3; ++k) if(j ^ k) res = max(res, a[i][k]);
	return res;
}
inline void add(int i, int j){	
	ans += a[i][j];
	++c[j];
	q[j].push({mx(i, j) - a[i][j], i});
}
inline void del(int i, int j){
	ans -= a[i][j];
	--c[j];
	q[j].pop();
	
	int res = mx(i, j);
	for(int k = 0; k < 3; ++k)
		if(k ^ j && res == a[i][k]){
			add(i, k);
			break;
		}
}
inline void MAX(int &a, int b) {a = (a > b ? a : b);}
inline int bl(){
	for(int i = 0; i <= n / 2; ++i)
		for(int j = 0; j <= n / 2; ++j) f[i][j] = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j <= n / 2; ++j)
			for(int k = 0; k <= n / 2; ++k) g[j][k] = f[j][k], f[j][k] = 0;
		for(int j = 0; j <= n / 2; ++j)
			for(int k = 0; k <= n / 2; ++k){
				MAX(f[j + 1][k], g[j][k] + a[i][0]);
				MAX(f[j][k + 1], g[j][k] + a[i][1]);
				MAX(f[j][k], g[j][k] + a[i][2]);
			}
	}
	int res = 0;
	for(int i = 0; i <= n / 2; ++i)
		for(int j = 0; j <= n / 2; ++j)
			if(n - i - j <= n / 2) MAX(res, f[i][j]);
	return res;
}
signed main(){
	freopen("club4.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--){
		scanf("%lld", &n), lim = n / 2;
		ans = 0;
		for(int i = 0; i < 3; ++i){
			c[i] = 0;
			while(!q[i].empty()) q[i].pop();
		}
		for(int i = 1; i <= n; ++i) scanf("%lld%lld%lld", &a[i][0], &a[i][1], &a[i][2]);
		
		int sm = 0;
		for(int i = 1; i <= n; ++i) sm += a[i][0], x[i] = a[i][1] - a[i][0];
		sort(x + 1, x + 1 + n);
		for(int i = n / 2 + 1; i <= n; ++i) sm += x[i]; 
		
		for(int i = 1; i <= n; ++i){
			int mxx = 0;
			for(int j = 0; j < 3; ++j) mxx = max(mxx, a[i][j]);
			if(a[i][0] == mxx) i0 = 0;
			else if(a[i][1] == mxx) i0 = 1;
			else i0 = 2;
			if(c[i0] < lim) add(i, i0);
			else{
				pir _ = q[i0].top(); int res = mx(i, i0);
				if(_.second + a[i][i0] > res) del(q[i0].top().second, i0), add(i, i0);
				else{
					for(int j = 0; j < 3; ++j)
						if(j ^ i0 && a[i][j] == res){
							add(i, j);
							break;
						}
				}
			}
		}
		if(n <= 200) sm = max(sm, bl());
		printf("%lld\n", max(ans, sm));
	}
	return 0;
} 
