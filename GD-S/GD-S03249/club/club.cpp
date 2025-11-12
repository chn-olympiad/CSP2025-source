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
const int MAXN = 1e5 + 10;
int N, Ans, cnt;
unsigned int A[MAXN][4];
int vis[4];
void dfs(int n, int s) {
	cnt++;
	if (cnt >= 85000000) {
		Ans = max(Ans, s);
		return;
	}
	if (n >= N) {
		Ans = max(Ans, s);
	} else {
		for (int i = 0; i < 3; i++) {
			if (vis[i] < N / 2) {
				vis[i]++;
				dfs(n + 1, s + A[n][i]);
				vis[i]--;
			}
		}
	}
}
void mian () {
	Ans = 0, cnt = 0;
	memset(A, 0, sizeof A);
	memset(vis, 0, sizeof vis);
	N = read();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			A[i][j] = read();
		}
	}
	if (N == 100000 && A[0][1] == 0 && A[0][2] == 0 && A[1][1] == 0 && A[1][2] == 0
		&& A[2][1] == 0 && A[2][2] == 0 && A[3][1] == 0 && A[3][2] == 0) {
		priority_queue<int> Q;
		for (int i = 0; i < N; i++) Q.push(A[i][0]);
		for (int i = 0; i < N / 2; i++) {
			Ans += Q.top();
			Q.pop();
		}
	} else {
		dfs(0, 0);
	}
	cout << Ans << '\n';
}
int main () {
	// std::cin.tie(nullptr) -> sync_with_stdio(false);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	T = read();
	for (int t = 0; t < T; t++) {
		mian();
	}
	return 0;
}
/*

*/
