#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;
int t, n, ans, maxa;
struct node{
	int p1, p2, p3;
}a[N];
struct club{
	int num, p;
}c[5];
void dfs(int step) {
	if (step == n) {
		ans = c[1].p + c[2].p + c[3].p;
		maxa = max(ans, maxa);
		return ;
	}
	
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i].p1 >> a[i].p2 >> a[i].p3;
		dfs(1);
		cout << maxa;
	}
	return 0;
} 
