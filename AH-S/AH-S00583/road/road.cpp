#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
int t, n, m, k;
struct Node{
	int a, b, v;
	bool operator < (const Node B) const {
		return v < B.v;
	}
} E[1000025], A[12][10005];
bool Hav[12];
int UseEdge[1000025], ECnt;
int fa[10025];
int Find(int x) {
	return x == fa[x] ? x : fa[x] = Find(fa[x]);
}
bool Union(int x, int y) {
	x = Find(x), y = Find(y);
	if (x == y) return 0;
	fa[x] = y;
	return 1;
}
void BCJ_INIT() {
	for (int i = 1; i <= n + 10; i++) fa[i] = i;
	return;
}
long long Ans;
long long LCA_INIT() {
	BCJ_INIT();
	long long Tot = 0;
	for (int i = 1; i <= m; i++) {
		if (Union(E[i].a, E[i].b)) {
			Tot += E[i].v;
			UseEdge[++ECnt] = i;
		}
	}
	return Tot;
}
struct CMp {
	bool operator () (Node a, Node b) {
		return a.v > b.v;
	}
};

int Ause[12];
long long LCA() {
	BCJ_INIT();
	long long Tot = 0;
	for (int i = 1; i <= k; i++) Ause[i] = 1;
	priority_queue<Node, vector<Node>, CMp> pq;
	for (int i = 1; i <= k; i++) if (Hav[i]) pq.push({i, A[i][1].b, A[i][1].v});
	for (int i = 1; i <= ECnt; i++) {
		for (int j = 1; j <= k; j++) {
			if (Hav[j]) {
				while (Ause[j] <= n && A[j][Ause[j]].v < E[UseEdge[i]].v) {
					if (Union(A[j][Ause[j]].a, A[j][Ause[j]].b)) 
						Tot += A[j][Ause[j]].v;
					++Ause[j];
				}
			}
		}
		if (Union(E[UseEdge[i]].a, E[UseEdge[i]].b)) {
			Tot += E[UseEdge[i]].v;
		}
	}
	return Tot;
}
int c[15];
void dfs(int idx) {
	long long This = 0;
	for (int i = 1; i <= k; i++) {
		if (Hav[i]) {
			This += c[i];
		}
	}
	long long ans = LCA() + This;
	Ans = min(Ans, ans);
	if (idx > k) return;
	Hav[idx] = 1;
	dfs(idx + 1);
	Hav[idx] = 0;
	dfs(idx + 1);
	return;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> E[i].a >> E[i].b >> E[i].v;
	}
	sort(E + 1, E + m + 1);
	Ans = LCA_INIT();
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> A[i][j].v;
			A[i][j].a = n + i, A[i][j].b = j;
		}
		sort(A[i] + 1, A[i] + n + 1);
	}
	dfs(1);
	cout << Ans;
	return 0;
}
//会了！
//               一路走好
//             王狗灏、来中杨
//              ^   ^   ^
//                & & &
//                | | |
//                \ | /
//                 |||
//                 |||
//                 |||
//            -------------
//真的有用!  ^^^^   ^^^^   ^^^^
//T2, too water.
//OK 100pts
