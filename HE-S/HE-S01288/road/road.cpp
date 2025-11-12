#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e4 + 10;
const int M = 1e6 + 10;
int n, m, k, cnt;
ll ans, mix, c[N], v[20][N];
inline ll read() {
	ll x = 0;
	char c = getchar();
	while(c < '0' || c > '9') c = getchar();
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x;
}
struct Data{
	ll val;
	int from, to;
	bool operator < (const Data& tmp) const {
		return val > tmp.val;
	}
}a[N << 1], edge[M];
int fa[N << 1];
priority_queue<Data> q;
int findf(int a) {
	return fa[a] = fa[a] == a ? fa[a] : findf(fa[a]);
}
void merge(int a, int b) {
	fa[findf(a)] = b;
}
void clear(int n) {
	ans = 0;
	for(int i = 1; i <= n; i ++) {
		fa[i] = i;		
	}
}
void krus_first() {
	clear(n);
	for(int i = 1; i <= m; i ++) {
		q.push({edge[i]});
	}
	int num = n - 1;
	while(!q.empty()) {
		ll val = q.top().val;
		int u = q.top().from, v = q.top().to;
		q.pop();
		if(findf(u) == findf(v)) continue;
		merge(u, v);
		ans += val;
		a[++ cnt].val = val;
		a[cnt].from = u;
		a[cnt].to = v;
		num --;
		if(num == 0) break;
	}
	mix = ans;
}
void krus(int s) {
	int num = __builtin_popcount(s) + n;
	ll cost = 0;
	clear(num);
	for(int i = 1; i <= cnt; i ++) {
		q.push({a[i]});
	}
	int d = n;
	for(int i = 1; i <= 10; i ++) {
		if(((s >> (i - 1)) & 1) == 0) continue;
		if((s >> (i - 1)) & 1) {
			++ d;
			cost += c[i];
			for(int j = 1; j <= n; j ++) {
				Data tmp;
				tmp.val = v[i][j], tmp.from = d, tmp.to = j;
				q.push({tmp});
			}
		}
	}
	num --;
	while(!q.empty()) {
		ll val = q.top().val;
		int u = q.top().from, v = q.top().to;
		q.pop();
		if(findf(u) == findf(v)) continue;
		merge(u, v);
		ans += val;
		num --;
		if(num == 0) break;
		if(ans + cost >= mix) {
			break;
		}
	}
	mix = min(mix, ans + cost);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i ++) {
		cin >> edge[i].from >> edge[i].to >> edge[i].val;
	}
	for(int i = 1; i <= k; i ++) {
		cin >> c[i];
		for(int j = 1; j <= n; j ++) {
			cin >> v[i][j];
		}
	}
	krus_first();
	for(int i = 1; i < (1 << k); i ++) {
		krus(i);
	}
	cout << mix << '\n';
	return 0;
}

