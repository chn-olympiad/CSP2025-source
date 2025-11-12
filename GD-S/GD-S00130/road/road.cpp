#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 12, M = 2e6 + 10;
int n, m, k;
struct node {
	long long x, y, w;
};
int read() {
	int f = 0;
	char t = getchar();
	while(t < '0' || t > '9') {
		t = getchar();
	}
	while(t >= '0' && t <= '9') {
		f = f * 10 + t - '0';
		t = getchar();
	}
	return f;
}
int a[N];
int z[N][20];
int pa[N];
int find(int x) {
	if(pa[x] == x) {
		return x;
	}
	return x = find(pa[x]);
}

node v[M];
int cnt = 0;
int t[10];
bool cmp(node a, node b) {
	return a.w < b.w;
}
node q[N];
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) {
		int x, y, z;
		x = read();
		y = read();
		z = read();
		v[++cnt].x = x;
		v[cnt].y = y;
		v[cnt].w = z;
		q[cnt] = v[cnt];
		v[++cnt].x = y;
		v[cnt].y = x;
		v[cnt].w = z;
		q[cnt] = v[cnt];
	}
	for(int i = 1; i <= k; i++) {
		a[i] = read();
		for(int j = 1; j <= n; j++) {
			z[i][j] = read();
		}
	}
	int zw = 1 << k;
	zw--;
	int ye = cnt;
	long long ans = 0x3f3f3f3f;
	while(zw >= 0) {
		long long e = 0;
		for(int j = 1; j <= k; j++) {
			if(zw & (1 << (j - 1))) {
				e += a[j]; 
				for(int kk = 1; kk <= n; kk++) {
					v[++cnt].x = kk;
					v[cnt].y = j + n;
					v[cnt].w = z[j][kk];
					q[cnt] = v[cnt];
					v[++cnt].x = j + n;
					v[cnt].y = kk;
					v[cnt].w = z[j][kk];
					q[cnt] = v[cnt];
				}
			}
		}
		for(int i = 1; i <= n + k; i++) {
			pa[i] = i;
		}
		sort(v + 1, v + 1 + cnt, cmp);
		//cout << cnt;
		for(int i = 1; i <= cnt; i++) {
			int x = v[i].x, y = v[i].y, w = v[i].w;
			int xs = find(x), ys = find(y);
			//cout << x << " " << y << " " << w << " " << xs << " " << ys << endl;
			if(xs != ys) {
				pa[xs] = ys;
				e += v[i].w;
				//cout << e;
				int r = 0;
				for(int j = 1; j <= n + k; j++) {
					if(j <= n) {
						int xs = find(j), ys = find(n);
						if(xs != ys) {
							r++;
							break;
						}
					}
					else{
						int q = j - n;
						if(zw & (1 << q)) {
							int xs = find(n), ys = find(j);
							if(xs != ys) {
								r++;
								break;
							}
						}
					}
				}
				if(r == 0) {
					break;
				}
			}
		}
		cnt = ye;
		for(int i = 1; i <= cnt; i++) {
			v[i] = q[i];
		}
		ans = min(ans, e);
		zw--;
	}
	cout << ans; 
	return 0;
}
/*
4 4 0
1 2 1
2 3 2
3 4 3
1 4 2

*/
