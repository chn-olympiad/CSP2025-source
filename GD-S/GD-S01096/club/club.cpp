#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int T, n, it;
bool vis[3*N];
struct node {
	int va, id, st;
} a[N*3];
bool cmp(node x, node y) {
	return x.va > y.va;
}
bool checkA() {
	for(int i=1; i<=3*n; i++) {
		if(i%3==2&&a[i]!=0) return 0;
		if(i%3==0&&a[i]!=0) return 0; 
	}
	return 1;
}
void solve() {
	cin >> n; 
	int ans = 0, A = n/2, B = n/2, C = n/2;
	for(int i=1; i<=3*n; i++) {
		cin >> a[i].va;
		if(i%3==0) a[i].id = i/3, a[i].st = 3;
		else a[i].id = i/3+1, a[i].st = i%3;
	}
	if(checkA()) {
		int cnt = 0;
		for(int i=1; i<=3*n; i++)
			if(cnt<=n/2&&i%3==1) ans += a[i].va;
		cout << ans << endl;
		return ;
	}
	sort(a+1, a+3*n+1, cmp);
	for(int i=1; i<=3*n; i++) {
		if(vis[a[i].id]) continue;
		if(a[i].st==1&&A>=1) ans += a[i].va, vis[a[i].id] = 1, A--;
		if(a[i].st==2&&B>=1) ans += a[i].va, vis[a[i].id] = 1, B--;
		if(a[i].st==3&&C>=1) ans += a[i].va, vis[a[i].id] = 1, C--; 
	}
	cout << ans << endl;
	memset(vis, 0, sizeof(vis));
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--) solve();
	return 0;
} 
