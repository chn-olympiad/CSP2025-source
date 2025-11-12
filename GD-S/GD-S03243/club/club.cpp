#include <bits/stdc++.h>
#define int long long
using namespace std; 

const int N = 4e5 + 50;

int t, n, value, v[5], ans, m, sum[N], vis[N], ss;
struct node {
	int x, id, idx;
}a[N];

void dfs(int x, int s, int k) {
	if(ans > 1e8) return ;
	ans ++;
	if(n == k) {
		value = max(value, s);
		
		return ;
	}
	
	if(ss == n) {
		return ;
	}
	
	for(int i = x; i <= m; ++ i) {
		ans ++;
		if(a[i].x == 0 || sum[m] - sum[i - 1] + s <= value)return ;
		
		if(v[a[i].id] + 1 <= n / 2 && vis[a[i].idx] == 0) {
			v[a[i].id] ++;vis[a[i].idx] = 1;
			if(v[a[i].id] == n / 2) ss ++;
			dfs(i + 1, s + a[i].x, k + 1);
			if(v[a[i].id] == n / 2) ss --;
			v[a[i].id] --;vis[a[i].idx] = 0;
		}
	}
}

bool cmp(node x, node y) {
	ans ++;
	return x.x > y.x;
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin >> t;
	
	while(t --) {
		cin >> n;
		
		for(int i = 1; i <= n; ++ i) {
			cin >> a[++m].x >> a[++m].x >> a[++m].x;
			a[m - 2].id = 1;
			a[m - 1].id = 2;
			a[m].id = 3;
			a[m].idx = a[m - 1].idx = a[m - 2].idx = i;
		}
		
		sort(a + 1, a + 1 + m, cmp);
		
		for(int i = 1; i <= m; ++ i) {
			sum[i] = sum[i - 1] + a[i].x;
		}
		
		dfs(1, 0, 0);
		
		cout << value << "\n";
		value = 0;ans = 0;m = 0;
	} 
	return 0;
}

