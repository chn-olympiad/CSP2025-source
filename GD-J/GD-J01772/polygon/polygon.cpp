#include <bits/stdc++.h>

using namespace std;

int n, k = 3, sticks[5010], res;
bool visited[5010];

void dfs(int mxv, int sum, int ns, int curr) {  // mxv: max value, sum: sum, ns: number of sticks chosen 
	if (ns == k) {
		if (sum > mxv * 2) {
	//		cout << ns << ' ' << mxv << ' ' << sum << endl;
//			for (int i = 0; i < n; i++) {
//				cout << visited[i] << ' ';
//			}
//			cout << endl;
			res = ((res + 1) % 998244353); 
		}
		return;
	}
//	if (ns == k && sum > mxv * 2) {
////		cout << ns << ' ' << mxv << ' ' << sum << endl;
//		for (int i = 0; i < n; i++) {
//			cout << visited[i] << ' ';
//		}
//		cout << endl;
//		res++;
//		return;
//	}
//	if (ns == n) {
//		return;
//	}
	for (int i = curr + 1; i < n; i++) {
		if (visited[i]) {
			continue;
		}
		visited[i] = true;
		dfs(max(mxv, sticks[i]), sum + sticks[i], ns + 1, i);
//		dfs(mxv, sum, ns, i);
		visited[i] = false;
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> sticks[i];
		visited[i] = false;  // why did I write this line
	}
	res = 0;
	for (int i = 3; i <= n; i++) {
		k = i;
		dfs(0, 0, 0, -1);
	}
//	for (int i = 0; i < n; i++) {
//		visited[i] = true;
//		dfs(sticks[i], sticks[i], 1);
//		visited[i] = false;
//	}
	cout << res << endl;
	return 0;
}
