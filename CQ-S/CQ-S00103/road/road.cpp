#include<bits/stdc++.h>
#define ll long long
#define pii pair<int , int>
using namespace std;
const int MAXN = 2e6 + 5;
int n , m , k , c[MAXN] , fa[MAXN] , siz[MAXN];
bitset<MAXN> vis;
struct node{
	int u , v , w;
	friend bool operator<(node x , node y) {return x.w < y.w;}
}e[MAXN] , e2[MAXN];
inline int FindSet(int x) {return (fa[x] == x ? x : fa[x] = FindSet(fa[x]));}
inline bool UnionSet(int u , int v) {
	u = FindSet(u) , v = FindSet(v);
	if (u == v) return 0;
	if (siz[u] > siz[v]) swap(u , v);
	fa[u] = v , siz[v] += siz[u]; 
	return 1;
}
int main() {
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr) , cout.tie(nullptr);
	cin >> n >> m >> k;
	for (int i = 1 ; i <= m ; i ++) cin >> e[i].u >> e[i].v >> e[i].w;
	sort(e + 1 , e + m + 1);
	int len = 0;
	for (int i = 1 ; i <= n ; i ++) fa[i] = i , siz[i] = 1;
	for (int i = 1 ; i <= m ; i ++) {
		if (UnionSet(e[i].u , e[i].v)) e2[++ len] = e[i];
	}
	for (int i = 1 ; i <= k ; i ++) {
		cin >> c[i];
		for (int j = 1 , w ; j <= n ; j ++) {
			cin >> w;
			e2[++ len].u = n + i , e2[len].v = j , e2[len].w = w;
		}
	}
	sort(e2 + 1 , e2 + len + 1);
	ll ans = 1e18;
	for (int i = 0 ; i < (1 << k) ; i = -~i) {
		for (int j = 1 ; j <= n + k ; j = -~j) vis[j] = 0 , fa[j] = j , siz[j] = 1;
		ll MST = 0;
		for (int j = 1 ; j <= k ; j = -~j) {
			if ((1 << (j - 1)) & i) MST += c[j];
			else vis[n + j] = 1;
		}
		for (int j = 1 ; j <= len ; j = -~j) {
			if (vis[e2[j].u] || vis[e2[j].v]) continue;
			if (UnionSet(e2[j].u , e2[j].v)) MST += e2[j].w;
		}
		ans = min(ans , MST);
	}
	cout << ans;
	return 0;
}

