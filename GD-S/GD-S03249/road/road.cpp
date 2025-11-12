#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read (void) {
	ll X = 0; bool O = false; char C = getchar();
	while (!(C >= '0' && C <= ' 9')) O ^= (C == '-'), C = getchar();
	while (C >= '0' && C <= ' 9') X = (X << 3) + (X << 1) + (C - '0'), C = getchar();
	if (O) X = -X;
	return X;
}
const int MAXN = 1e4 + 10;
struct Edge {
	int u, v, w;
	friend bool operator < (Edge A, Edge B) {
		return A.w > B.w;
	} 
};
int main () {
	// std::cin.tie(nullptr) -> sync_with_stdio(false);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int N, M, K;
	ll Ans = 0;
	N = read(), M = read(), K = read();
	vector<bool> B(N + K);
	vector<vector<Edge> > E(M + K);
	for (int i = 0; i < M; i ++) {
		int u, v, w;
		u = read(), v = read(), w = read();
		u--, v--;
		E[u].push_back((Edge){u, v, w});
		E[v].push_back((Edge){v, u, w});
	}
	vector<int> C(K);
	vector<vector<int> > A(K, vector<int>(N));
	for (int i = 0; i < K; i ++) {
		C[i] = read();
		for (int j = 0; j < N; j ++) {
			A[i][j] = read();
			E[N + i].push_back((Edge){N + i, j, C[i] + A[i][j]});
			E[j].push_back((Edge){j, N + i, C[i] + A[i][j]});
		}
	}
	priority_queue<Edge, vector<Edge> > Q;
	for (int i = 0; i < N + K; i ++) {
		for (int j = 0; j < E[i].size(); j++) {
			Q.push(E[i][j]);
		}
	}
	while (!Q.empty()) {
		Edge T = Q.top();
		Q.pop();
		if (!B[T.u] || !B[T.v]) {
			Ans += T.w;
			if (T.u >= N && B[T.u]) Ans -= C[T.u - N];
			if (T.v >= N && B[T.v]) Ans -= C[T.v - N];
			// cout << T.u << "->" << T.v << ":" << T.w << "|" << Ans << endl;
			B[T.u] = true, B[T.v] = true;
		}
		int f = 0;
		for (int i = 0; i < N; i++) if (!B[i]) f = 1;
		if (f == 0) break;
	} 
	cout << Ans;
	return 0;
}
/*
烷基八氮了啊啊啊 
好吧，我败在了如何检查是否连通，说实话我这代码大概也就0.4 ~ 0.5秒极限了，加个检查连通图我也相信是超不了的
可惜了，不过我一开始入门都做不出来才经过3天恶补能写出这么多也算好了吧……？ 
*/
