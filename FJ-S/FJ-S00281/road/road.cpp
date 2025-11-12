#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fs first
#define sc second

int read() {
	int x = 0, f = 1;
	char c = getchar();
	while(!isdigit(c)) {
		if(c == '-') f = -1;
		c = getchar();
	}
	while(isdigit(c)) {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}

vector <pair<int,pair<int, int>>> g;
vector <pair<int,pair<int, int>>> g2;


bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
	return a.fs < b.fs;
}

vector <int> fa;

int find(int x){
	if(fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}

void merge(int x, int y){
	int fx = find(x), fy = find(y);
	if(fx != fy) fa[fx] = fy;
	return;
}

int ans, n, m, k;

void krus() {
	ans = 0;
	sort(g2.begin(), g2.end(), cmp);
	for(int i = 0;i < m;i++) {
//		cout << g2[i].sc.fs << " " << g2[i].sc.sc << " " << g2[i].fs << " " << 
//			find(g2[i].sc.fs) << " " << find(g2[i].sc.sc) << "\n";
		if(find(g2[i].sc.fs) != find(g2[i].sc.sc)) {
			merge(g2[i].sc.fs, g2[i].sc.sc);
			ans += g2[i].fs;
//			cout << find(g2[i].sc.fs) << " " << find(g2[i].sc.sc) << "\n";
			g.emplace_back(make_pair(g2[i].fs, make_pair(g2[i].sc.fs, g2[i].sc.sc)));
//			cout << g2[i].sc.fs << " " << g2[i].sc.sc << "\n";
//			cout << g.size() << "\n";
		}
	}
}

signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	fa.resize(n + 10);
	vector <int> c(k + 10);
	vector <vector <int>> a(k + 10, vector <int>(n + 10));
	vector <vector <pair<int,int>>> g4(n + 10);
	vector <pair<int,pair<int, int>>> g3;
	for(int i = 1;i <= n;i++) fa[i] = i;
	for(int i = 1;i <= m;i++) {
		int u = read(), v = read(), w = read();
		g2.emplace_back(make_pair(w, make_pair(u, v)));
	}
//	cout << 1 << "\n";
	for(int i = 1;i <= k;i++) {
		c[i] = read();
		for(int j = 1;j <= n;j++) a[i][j] = read();
	}
	krus();
	cout << ans << "\n";
	int val = 0;
//	cout << "1\n";
	for(int j = 0; j < g.size(); j++) {
		g3.emplace_back(g[j]);
//		cout << g[j].sc.fs << " " << g[j].sc.sc << " " << g[j].fs << "\n";
		g4[g[j].sc.fs].emplace_back(make_pair(g[j].sc.sc, g[j].fs));
		g4[g[j].sc.sc].emplace_back(make_pair(g[j].sc.fs, g[j].fs));
	}
	for(int i = 1; i < (1 << k); i++) {
		vector <int> dot;
//		cout << 1 << "\n";
		int res = 0;
		for(int j = 0;(1 << j) <= i;j ++) {
			if(i & (1 << j)) dot.emplace_back(j), res += c[j];
		}
//		cout << "1\n";
		
//		cout << "1\n";
		for(int j = 0; j < dot.size(); j++) {
			int x = dot[j] + 1;
//			cout << "x : " << x << "\n";
			for(int l = 0; l < g3.size(); l ++) {
				int w = g3[l].fs, u = g3[l].sc.fs, v = g3[l].sc.sc;
				int min_w = a[x][u] + a[x][v];
//				cout << "1\n";
//				cout << "g4u : " << g4[u].size() << "\n";
				for(int o = 0;o < (int)g4[u].size();o++) {
					if(g4[u][o].fs == v) continue;
					if(g4[u][o].sc < w) continue;
					min_w = min(min_w, a[x][v] + a[x][g4[u][o].fs]);
//					cout << g4[u][o].fs << " " << min_w << "\n";
				}
//				cout << "1\n";
//				cout << "g4v : " << g4[v].size() << "\n";
				for(int o = 0;o < (int)g4[v].size();o++) {
//					cout << "1\n";
					if(g4[v][o].fs == u) continue;
					if(g4[v][o].sc < w) continue;
					min_w = min(min_w, a[x][u] + a[x][g4[v][o].first]);
//					cout << g4[v][o].fs << " " << min_w << "\n";
//					cout << 1 <
				}
//				cout << "1\n";
				if(min_w < w) {
					res += min_w - w, g3[l].fs = min_w;
					for(int o = 0;o < (int)g4[u].size();o++) {
						if(g4[u][o].fs == v) {
							g4[u][o].sc = min_w;
							break;
						}	
					}
					for(int o = 0;o < (int)g4[v].size();o++) {
						if(g4[v][o].fs == u) {
							g4[v][o].sc = min_w;
							break;
						}	
					}
				}
//				cout << "min_w : " << min_w << " res : " << res << "\n";
			}
		}
//		cout << "\n";
		val = min(val, res);
//		cout << val << "\n";
//		puts("__________________________________");
	}
	cout << ans + val << "\n";
	return 0;
}

/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/

/*
11 14 0
1 2 100
2 3 0
2 4 100
3 4 0
1 4 100
4 8 100
4 7 0
4 6 100
4 5 100
5 6 0
6 7 100
7 9 0
9 10 100
10 11 100
*/

