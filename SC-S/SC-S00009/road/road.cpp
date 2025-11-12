#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
#define inf 1e18
using namespace std;
const int maxn = 1e5 + 100;
inline int read() {
	int x = 0 , f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
inline void write(int x) {
	if(x < 0) x = -x , putchar('-');
	if(x >= 10) write(x / 10);
	putchar(x % 10 + '0');
}
inline void writeh(int x) {
	write(x);
	putchar('\n');
}
inline void writek(int x) {
	write(x);
	putchar(' ');
}
int n , m , k , a[20][100010] , c[20] , dis[maxn] , cnt , ans , tot;
bitset<100000> vis;
bitset<100> vis1;
struct node {
	int val , to;
};
vector<node> t[maxn];
struct pri {
	int val , id;
	friend bool operator < (pri a , pri b) {
		return a.val > b.val;
	}
};
priority_queue<pri> q;
inline int prim() {
	while(!q.empty()) q.pop();
	q.push({0 , 1});
	for(int i = 1; i <= n + k; ++i) dis[i] = inf;
	dis[1] = 0;
	vis = 0;
	int res = 0;
	while(!q.empty()) {
		pri u = q.top();
		q.pop();
		if(vis[u.id]) continue;
		vis[u.id] = 1;
		res += u.val;
		if(res + cnt > ans) return inf;
		if(u.id > n) {
			u.id -= n;
			for(int i = 1; i <= n; ++i) if(dis[i] > a[u.id][i]) dis[i] = a[u.id][i] , q.push({dis[i] , i});
		}else {
			for(auto y:t[u.id]) {
				int v = y.to;
				if(dis[v] > y.val) dis[v] = y.val , q.push({dis[v] , v});
			}
			for(int i = 1; i <= k; ++i) {
				if(!vis1[i]) continue;
				if(dis[i + n] > a[i][u.id]) dis[i + n] = a[i][u.id] , q.push({dis[i + n] , i + n});
			}
		}
	}
	return res;
}
signed main() {
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	n = read();
	m = read();
	k = read();
	for(int i = 1; i <= m; ++i) {
		int u = read() , v = read() , w = read();
		t[u].push_back({w , v});
		t[v].push_back({w , u});
	}
	bool flag = 1;
	for(int i = 1; i <= k; ++i) {
		c[i] = read();
		if(c[i]) flag = 0;
		for(int j = 1; j <= n; ++j) a[i][j] = read();
	}
	ans = inf;
	if(flag) {
		for(int i = 1; i <= k; ++i) vis1[i] = 1;
		writeh(prim());
		return 0;
	}
	for(int i = 0; i < (1 << k); ++i) {
		vis1 = 0;
		cnt = 0;
		for(int j = 0; j < k; ++j) if(i & (1 << j)) vis1[j + 1] = 1 , cnt += c[j + 1];
		if(cnt > ans) continue;
		int sum = prim();
		ans = min(ans , sum + cnt);
	}
	writeh(ans);
	return 0;
}
