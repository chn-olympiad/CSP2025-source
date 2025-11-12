// 准考证：GZ-S00501，姓名：黄佳洛，学校：华中师大一附中贵阳学校 

#include <bits/stdc++.h>
#define endl '\n'
#define upp(i, l, r) for (int i = l; i <= r; i++)
#define dww(i, r, l) for (int i = r; i >= l; i--)
#define IO ios::sync_with_stdio(0)
#define x first
#define y second
#define PII pair<int, int>
#define PIII pair<int, PII>

using namespace std;

const int N = 2e6 + 10, M = 1e5 + 10;

int n, m, k;
int p[M];
int t[12][M], c[13];
int dist[N];
struct node {
	int u, v, w;
	bool operator <(const node &W) const {
		return w < W.w;
	}
} qe[N];
int idx;

int find(int x) {
	if (p[x] != x) return p[x] = find(p[x]);
	return p[x];
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	IO;
	cin >> n >> m >> k;
	int sum = 0; 
	upp(i, 1, n + k) p[i] = i;
	upp(i, 1, m) {
		int v, u, d;
		cin >> v >> u >> d;
		qe[++idx] = {u, v, d};
		sum += d;
	}
	int flag = 0;
	upp(i, 1, k) {
		int fl = 0;
		cin >> c[i];
		if (c[i]) fl = 1;
		else flag = i;
		upp(j, 1, n) {
			cin >> t[i][j];
			if (t[i][j] != 0) fl = 1;
		}
		if (!fl) {
			cout << 0 << endl;
			return 0;
		}
	}
	if (!k) {
		int idx = m;
		sort(qe + 1, qe + idx + 1);
		int res = 0;
		upp(i, 1, m) {
			int u = find(qe[i].u), v = find(qe[i].v), w = qe[i].w;
			int u1 = 0, v2 = 0;
			if (p[u] != v) {
				p[u] = v;
				res += w;
			}
		}
		
		cout << res << endl;
	}
	
	if (flag) {
		upp(i, 1, n) qe[++idx] = {i + 1, i, t[flag][i]};
		sort(qe + 1, qe + idx + 1);
		int res = 0;
		upp(i, 1, idx) {
			int u = find(qe[i].u), v = find(qe[i].v), w = qe[i].w;
			int u1 = 0, v2 = 0;
			if (u > n && v > n) {
				continue;
			}
			if (p[u] != v) {
				p[u] = v;
				res += w;
			}
		}
		
		cout << res << endl;
	}
	else {
		cout << sum << endl;
	}
	
	
	return 0;
}
