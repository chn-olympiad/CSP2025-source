#include<bits/stdc++.h>
using namespace std;

const int N = 22, M = 110;
int n = 0;
int le[N] = {};
int f[N][N * M][M];
int ans = 0;
int t[N] = {};

void dfs(int x, int sum, int Max, int us, int mb) {
//	if (us == mb) {
//		cout << "/\n";
//		cout << sum << " " << Max << endl;
//		for (int i = 1; i <= us; i++) {
//			cout << t[i] << " ";
//		}
//		cout << endl;
//	}
	if (us == mb && sum > 2 * Max) {
		ans++;
//		cout << "/\n";
//		cout << sum << " " << Max << endl;
//		for (int i = 1; i <= us; i++) {
//			cout << t[i] << " ";
//		}
//		cout << endl;
	}
	if (x > n) {
		return;
	}
	t[us + 1] = le[x];
	dfs(x + 1, sum + le[x], max(Max, le[x]), us + 1, mb);
	t[us + 1] = 0;
	dfs(x + 1, sum, Max, us, mb);
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> le[i];
	}
	for (int i = 3; i <= n; i++) {
		dfs(1, 0, 0, 0, i);
	}
	cout << ans;
	return 0;
}
