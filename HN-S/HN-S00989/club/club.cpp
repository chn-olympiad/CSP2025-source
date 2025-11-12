#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e5 + 100;
const int inf = 1ll << 40;
int a[MAXN][3];

inline int read() {
	int f = 1, rd = 0; char ch = getchar();
	while (!((ch >= '0' && ch <= '9') || ch == '-')) ch = getchar();
	if (ch == '-') f = -1; else rd = ch - '0'; ch = getchar();
	while (ch >= '0' && ch <= '9') rd = rd * 10 + ch - '0', ch = getchar();
	return rd * f;
}

struct Node {
	int id, max_val, middle_val, min_val;
	
	Node() : id(0), max_val(-inf), middle_val(-inf), min_val(inf) {}
	Node(int id, int max_val, int middle_val, int min_val) : id(id), max_val(max_val), middle_val(middle_val), min_val(min_val) {}
	
	bool operator < (const Node &other) const {
		int val1 = max_val - middle_val;
		int val2 = other.max_val - other.middle_val;
		if (val1 != val2) {
			return val1 > val2;
		}
		val1 = max_val - min_val;
		val2 = other.max_val - other.min_val;
		return val1 > val2;
	}
};

priority_queue<Node> q[3];

void clear() {
	while (!q[0].empty()) q[0].pop();
	while (!q[1].empty()) q[1].pop();
	while (!q[2].empty()) q[2].pop();
}

int getmaxpos(int x, int y, int z) {
	int Max = max(max(x, y), z);
	if (Max == x) return 0;
	if (Max == y) return 1;
	if (Max == z) return 2;
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int T;
	cin >> T;
	while (T--) {
		int n, ans = 0;
		cin >> n;
		clear();
		for (int i = 1; i <= n; ++i) {
			int x, y, z;
			x = read(), y = read(), z = read();
			a[i][0] = x, a[i][1] = y, a[i][2] = z;
			int Max_val = max(max(x, y), z);
			int Min_val = min(min(x, y), z);
			int Middle_val = x + y + z - Max_val - Min_val;
			ans += Max_val;
			q[getmaxpos(x, y, z)].push(Node(i, Max_val, Middle_val, Min_val));
		}
		
		int Max_size = n / 2;
		for (int i = 1; i <= 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				while (q[j].size() > Max_size) {
					int id = q[j].top().id;
					q[j].pop();
					ans -= a[id][j];
					a[id][j] = -inf;
					int x = a[id][0], y = a[id][1], z = a[id][2];
					int Max_val = max(max(x, y), z);
					int Min_val = min(min(x, y), z);
					int Middle_val = x + y + z - Max_val - Min_val;
					ans += Max_val;
					q[getmaxpos(x, y, z)].push(Node(id, Max_val, Middle_val, Min_val));
				}
			}
		}
		
		cout << ans << '\n';
	}
}

/*
yangli:
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
