#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read () {
	ll X = 0;bool O = false;char C = getchar();
	while (!(C >= '0' && C <= '9')) O ^= (C=='-'), C = getchar();
	while (C >= '0' && C <= '9') X = (X << 3) + (X << 1) + (C - '0'), C = getchar();
	if (O) X = -X;
	return X;
}
const int MAXN = 5e3 + 10;
const int Mod = 998244353;
int A[MAXN], N;
bool vis[MAXN];
ll Ans;
set<string> SP;
void dfs(int k, int o, int S, int M) {
	if (o >= k) {
		if (S > 2 * M) {
			string S;
			for (int i = 0; i < N; i++) {
				S = S + char(vis[i] + '0');
			}
			SP.insert(S);
		}
	} else {
		for (int i = 0; i < N; i++) {
			if (!vis[i]) {
				vis[i] = true;
				dfs(k, o + 1, S + A[i], M = max(M, A[i]));
				vis[i] = false;
			}
		}
	}
}
int main () {
	std::cin.tie(nullptr) -> sync_with_stdio(false);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int S = 0;
	N = read();
	for (int i = 0; i < N; i++) {
		A[i] = read();
		S += A[i];
	}
	sort(A, A + N, less<int>());
	if (S <= 2 * A[N - 1]) {
		cout << 0;
		return 0;
	}
	for (int k = 3; k <= N; k++) {
		dfs(k, 0, 0, 0);
	}
	cout << SP.size() % Mod;
	return 0;
}
/*
ËãÁË,dfs±©Á¦ÍÆ°É 
*/
