#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int p[20];
int c[20], s[20];
int n, m;
bool check() {
	//for(int i = 1; i <= n; i++) {
	//	printf("%d%c", p[i], " \n"[i == n]);
	//}
	int givup = 0, ac = 0;
	for(int i = 1; i <= n; i++) {
		int tod = p[i];
		if(c[tod] <= givup) {givup++; continue;}
		if(s[i] == 0) {givup++; continue;}
		ac++;
		//printf("%d %d %d %d\n", givup, ac, c[tod], s[i]);
	}
	//printf("%d %d\n", givup, ac);
	return ac >= m;
}
int ans = 0;
bool vis[20];
void dfs(int dep) {
	if(dep == n) ans += check();
	else {
		for(int i = 1; i <= n; i++) {
			if(vis[i]) continue;
			vis[i] = 1; p[dep + 1] = i;
			dfs(dep + 1);
			vis[i] = 0;
		}
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		char cc;
		cin >> cc;
		s[i] = cc - '0';
	}
	for(int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	dfs(0);
	cout << ans << endl;
	return 0;
}
