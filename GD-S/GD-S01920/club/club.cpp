#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int vis[N];
int T, n, ans, a[N][3], f[205][205][205];
void work1() {
	memset(f, -0x3f, sizeof f);
	f[1][0][0] = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= n/2; j++) {
			for(int k = 0; k <= n/2; k++) {
				f[i+1][j+1][k] = max(f[i+1][j+1][k], f[i][j][k] + a[i][1]);
				f[i+1][j][k+1] = max(f[i+1][j][k+1], f[i][j][k] + a[i][2]);
				f[i+1][j][k] = max(f[i+1][j][k], f[i][j][k] + a[i][3]);
			}
		}
	}
	for(int i = 0; i <= n/2; i++) {
		for(int j = 0; j <= n/2; j++) {
			if(n-i-j > n/2) continue;
			ans = max(ans, f[n+1][i][j]);
		}
	}
}
priority_queue<pair<int, int>> p1, swp;
void clear(priority_queue<pair<int, int>> &p) {
	while(p.size()) p.pop();
}
void work2() {
	int c1, c2, c3;
	int sum = 0;
	clear(p1);
	for(int i = 1; i <= n; i++)
		p1.emplace(a[i][1]-a[i][2], i), vis[i] = 0;
	for(int i = 1; i <= n/2; i++) {
		int id = p1.top().second;
		p1.pop();
		vis[id] = 1;
	} clear(swp);
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) vis[i] = 2;	
		sum += a[i][vis[i]];
		swp.emplace(a[i][3]-a[i][vis[i]], i);
	} 
	c1 = c2 = n/2, c3 = 0;
	while(swp.size() && swp.top().first > 0) {
		sum += swp.top().first;
		int id = swp.top().second;
		swp.pop();
		++c3;
		vis[id] = 3;
		if(c3 == n/2) break;
	} clear(swp);
	
	
	c1 = c2 = c3 = 0;
	for(int i = 1; i <= n; i++) {
		if(vis[i] == 2) {
			c2++;
		}
		if(vis[i] == 3){
			c3++;
		}else c1++;
		if(a[i][2]-a[i][vis[i]] > 0)
		swp.emplace(a[i][2]-a[i][vis[i]], i);
	} 
	while(c2 < n/2 && swp.size() && swp.top().first > 0) {
		sum += swp.top().first;
		int id = swp.top().second;
		swp.pop();
		vis[id] = 2;
	} clear(swp);
	
	c1 = c2 = c3 = 0;
	for(int i = 1; i <= n; i++) {
		if(vis[i] == 2) {
			c2++;
		}
		if(vis[i] == 3){
			c3++;
		}else c1++;
		if(a[i][1]-a[i][vis[i]] > 0)
		swp.emplace(a[i][1]-a[i][vis[i]], i);
	} 
	while(c1 < n/2 && swp.size() && swp.top().first > 0) {
		sum += swp.top().first;
		int id = swp.top().second;
		swp.pop();
		++c1;
		vis[id] = 1;
	} clear(swp);
	
	ans = max(ans, sum);
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin.tie(0), cout.tie(0); 
	ios::sync_with_stdio(0);
	cin >> T;
	while(T--) {
		cin >> n;
		for(int i = 1; i <= n; i++) 
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		ans = 0;
		if(n <= 200) work1();
		else work2();
		cout << ans << '\n';
	}
	return 0;
}
