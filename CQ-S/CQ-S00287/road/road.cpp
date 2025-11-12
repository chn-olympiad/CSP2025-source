#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, k;
struct line{
	int u, v;
	int w;
};

bool cmp(line a, line b) {
	return a.w <= b.w;
}

vector<line> g, g2;
int a[15][10005];
int f[10005];
int find(int x ) {
	return f[x] == x?x:f[x]=find(f[x]); 
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for ( int i = 1 ; i <= m ; i ++ ) {
		int u, v, w;
		cin >> u >> v >> w;
		g.push_back({u, v, w});
		g.push_back({v, u, w});
	}
	for ( int i = 1 ; i <= k ; i ++ ) {
		for ( int j = 0 ; j <= n ; j ++ ) {
			cin >> a[i][j];
		}
	}
	int cnt = 0;
	g2 = g;
	for ( int i = 1 ; i <= n ; i ++ ) {
		f[i] = i;
	}
	sort ( g2.begin(), g2.end(), cmp);
	for ( auto v : g2 ) {
		if ( find(v.u) == find(v.v) ) {
			continue;
		}
//		cout << "connect " << v.u << " " << v.v << endl;
		f[find(v.u)] = find(v.v);
		cnt += v.w;
	}
	cout << cnt << endl;
//	for ( int i = 0 ; i < ( 1 << k ) ; i ++ ) {
//		g2 = g;
//		cnt = 0;
//		for ( int j = 1 ; j <= k ; j ++ ) {
//			if ( i & ( 1 << (j - 1 ))) {
//				cnt += a[j][0];
//				for ( int i = 1 ; i <= n ; i ++ ) {
//					g2.push_back({j + 10000, i, a[k][i]});
//					g2.push_back({i, j + 10000, a[k][i]});
//					f[j+10000] = f[j+10000];
//				}
//			}
//		}
//		for ( int i = 1 ; i <= n ; i ++ ) {
//			f[i] = i;
//		}
//		sort ( g2.begin(), g2.end(), cmp);
//		for ( auto v : g2 ) {
//			if ( find(v.u) == find(v.v) ) {
//				continue;
//			}
//			cout << "connect " << v.u << " " << v.v << endl;
//			f[find(v.u)] = find(v.v);
//			cnt += v.w;
//		}
//		cout << cnt << endl;
//	}
}
