//GZ-S00040 贵阳市白云区华师一学校 冯子尧 
#include <bits/stdc++.h>

#define upp(a, x, y) for (int a = x; a <= y; a ++)
#define dww(a, x, y) for (int a = x; a >= y; a --)
#define lowbit(x) x & -x
#define pb(x) push_back(x)
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int N = 1e4 + 20, M = 1e6 + 1e5 + 10;

struct Node {
	int a, b;
	LL w;
	int kind;
	bool operator < (const Node &node) const {
		return w < node.w;
	}
}node[M];

int n, m, k;
int c[20], cn[20][N];
int g[N][N];
int p[N];

int find(int x) {
	if (p[x] == x) return x;
	return p[x] = find(p[x]);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	memset(g, -1, sizeof g); 
	
	cin >> n >> m >> k;
	
	upp(i, 1, n + k) p[i] = i;
	
	upp (i, 1, m) {
		int a, b, w;
		cin >> a >> b >> w;
		node[i] = {a, b, w};
		if (g[a][b] == -1) g[a][b] = g[b][a] = w;
		g[a][b] = g[b][a] = min(g[a][a], w);
	}
	if (k == 0) {
		LL res = 0;
		sort(node + 1, node + m + 1);
		upp (i, 1, m) {
			int a = node[i].a, b = node[i].b;
			LL w = node[i].w;
			int fa = find(a), fb = find(b);
			if (fa != fb) {
				p[fa] = fb;
				res += w;
			}
		}
		cout << res;
	}
	else {
		bool flag = false;
		int cnt = 0;
		upp (i, 1, k) {
			cin >> c[i];
			cnt += c[i];
			upp (j, 1, n) {
				cin >> cn[i][j];
			}
		}
		if (cnt == 0) {
			upp (k1, 1, k) {
				upp (i, 1, n - 1) {
					upp(j, i + 1, n) {
						int t = cn[k1][i] + cn[k1][j];
						if(g[i][j] == -1) g[i][j] = g[j][i] = t;
						else g[i][j] = g[j][i] = min(g[i][j], t);
					}
				}
			}
			vector<Node> s;
			upp (i, 1, n - 1) {
				upp (j, i + 1, n) {
					if (g[i][j] != -1) {
						s.push_back({i, j, g[i][j]});
					}
				}
			}
			sort(s.begin(), s.end());
			int ns = s.size();
			LL res = 0ll;
			upp (i, 0, ns - 1) {
				int a = s[i].a, b = s[i].b, w = s[i].w;
				int fa = find(a), fb = find(b);
				if (fa != fb) {
					res+= (LL)w;
					p[fa] = fb;
				}
			}
			cout << res; 
		}
	}
	return 0;
}
