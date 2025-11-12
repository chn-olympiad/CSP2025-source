#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, k;
struct edge {
	int x, y, w;
	bool operator < (edge B) const {
		return w < B.w;
	}
} ed[1000010], ke[2000010], tmp;
int f[100010];
int q(int x) {
	if(f[x] != x) f[x] = q(f[x]);
	return f[x];
}
void h(int x, int y) {
	x = q(x);
	y = q(y);
	f[y] = x;
}
int _, _k;
int i1, i2;
int x, y, w;
int c[12], a[12][10010];
int sum, ans, ans1;
//bool flag[12];
int num;
char inc;
int read() {
	do {
		inc = getchar();
	} while(!isdigit(inc));
	num = 0;
	num = inc ^ '0';
	while(true) {
		inc = getchar();
		if(!isdigit(inc)) break;
		num *= 10;
		num += inc ^ '0';
	}
	return num;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
//	scanf("%lld%lld%lld", &n, &m, &k);
	n = read();
	m = read();
	k = read();
	for(int i = 1; i <= m; i++) {
//		cin >> x >> y >> w;
//		scanf("%lld%lld%lld", &x, &y, &w);
		x = read();
		y = read();
		w = read();
		++_;
		ed[_].x = x;
		ed[_].y = y;
		ed[_].w = w;
	}
	sort(ed + 1, ed + _ + 1);
	for(int i = 1; i <= k; i++) {
//		scanf("%lld", &c[i]);
		c[i] = read();
		for(int j = 1; j <= n; j++) {
//			scanf("%lld", &a[i][j]);
			a[i][j] = read();
//			a[i][j] += c[i];
		}
	}
	//----------------------------------------------------
//	sum = 0;
//	_k = _;
////		_k = 0;
//	for(int j = 1; j <= _; ++j) {
//		ke[j].x = ed[j].x;
//		ke[j].y = ed[j].y;
//		ke[j].w = ed[j].w;
//	}
////	for(int __ = 1; __ <= n; __++) {
////		++_k;
////		ke[_k].w = a[i][__];
////		ke[_k].x = __;
////		ke[_k].y = i + n;
////	}
////	sum += c[i];
//	sort(ke + 1, ke + _k + 1);
//	for(int j = 1; j <= n + k; ++j) {
//		f[j] = j;
//	}
//	for(int j = 1; j <= _k; ++j) {
//		if(q(ke[j].x) != q(ke[j].y)) {
//			sum += ke[j].w;
//			h(ke[j].x, ke[j].y);
//			if(sum >= ans) break;
//		}
//	}
//	ans1 = sum;
	//----------------------------------------------------
//	for(int i = 1; i <= k; i++) {
//		sum = 0;
//		_k = _;
////		_k = 0;
//		for(int j = 1; j <= _; ++j) {
//			ke[j].x = ed[j].x;
//			ke[j].y = ed[j].y;
//			ke[j].w = ed[j].w;
//		}
//		for(int __ = 1; __ <= n; __++) {
//			++_k;
//			ke[_k].w = a[i][__];
//			ke[_k].x = __;
//			ke[_k].y = i + n;
//		}
//		sum += c[i];
//		sort(ke + 1, ke + _k + 1);
//		for(int j = 1; j <= n + k; ++j) {
//			f[j] = j;
//		}
//		for(int j = 1; j <= _k; ++j) {
//			if(q(ke[j].x) != q(ke[j].y)) {
//				sum += ke[j].w;
//				h(ke[j].x, ke[j].y);
//				if(sum >= ans) break;
//			}
//		}
//		ans = min(ans, sum);
//		if(sum < ans1) flag[i] = true;
//	}
	//----------------------------------------------------
	ans = 1ll << 62;
	for(int i = 0; i < 1 << k; ++i) {
		sum = 0;
//		_k = _;
		_k = 0;
//		for(int j = 1; j <= _; ++j) {
//			ke[j].x = ed[j].x;
//			ke[j].y = ed[j].y;
//			ke[j].w = ed[j].w;
//		}
		for(int j = 1; j <= k; ++j) {
			if(i & (1 << j - 1)) {
				for(int __ = 1; __ <= n; __++) {
					++_k;
					ke[_k].w = a[j][__];
					ke[_k].x = __;
					ke[_k].y = j + n;
				}
				sum += c[j];
			}
		}
		sort(ke + 1, ke + _k + 1);
		for(int j = 1; j <= n + k; ++j) {
			f[j] = j;
		}
//		for(int j = 1; j <= _k; ++j) {
//			if(q(ke[j].x) != q(ke[j].y)) {
//				sum += ke[j].w;
//				h(ke[j].x, ke[j].y);
				if(sum >= ans) break;
//			}
//		}
		i1 = 0;
		i2 = 0;
		for(int j = 1; j <= _k + _; j++) {
			if(i1 == _) tmp = ke[++i2];
			else if(i2 == _k) tmp = ed[++i1];
			else if(ed[i1] < ke[i2]) tmp = ed[++i1];
			else tmp = ke[++i2];
			if(q(tmp.x) != q(tmp.y)) {
				sum += tmp.w;
				h(tmp.x, tmp.y);
				if(sum >= ans) break;
			}
		}
		ans = min(ans, sum);
//		cout << i << ' ' << sum << endl;
	}
	cout << ans << endl;
	return 0;
}



