// Calm down.
// Think TWICE, code ONCE.
#include<bits/stdc++.h>
#define pb push_back
#define popcnt __builtin_popcountll
#define debug printf("Passed line %d\n", __LINE__)

using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int, int> PII;
typedef pair<int, PII> edge;

template<typename T> inline void read(T &x){
	x = 0; char c = getchar();
	for (;!isdigit(c);c = getchar());
	for (;isdigit(c);c = getchar()) x = x*10+(c^48);
}

template<typename T1, typename ...T2> inline void read(T1 &x, T2 &...y){read(x), read(y...);}

template<typename T> inline void checkmax(T &x, const T &y){if (x<y) x = y;}

template<typename T> inline void checkmin(T &x, const T &y){if (x>y) x = y;}

const int N = 1e4+5, M = 1e6+5, K = 12;
const ll INF = 1e12;
int pos[N], fa[N], a[N], val[K], n, m, k;
priority_queue<ll> q;
edge c[K][N], e[M];
ll ans;

inline void dsu_init(){for (int i = 1;i<=n;i++) fa[i] = i;}

int get_fa(int x){return fa[x] == x ? x : fa[x] = get_fa(fa[x]);}

inline bool merge(int x, int y){
	x = get_fa(x), y = get_fa(y);
	if (x == y) return 0;
	fa[x] = y; return 1;
}

inline void init(){
	read(n, m, k); int u, v, w;
	for (int i = 1;i<=m;i++) read(u, v, w), e[i] = {w, {u, v}};
	sort(e+1, e+m+1); int top = 0; dsu_init();
	for (int i = 1;i<=m;i++){
		if (merge(e[i].second.first, e[i].second.second)){
			ans += e[i].first;
			c[0][++top] = e[i];
		}
	}
	int pos;
	for (int i = 1;i<=k;i++){
		pos = 1; read(val[i]), top = 0;
		for (int j = 1;j<=n;j++){
			read(a[j]);
			if (a[j]<a[pos]) pos = j;
		}
		val[i] += a[pos];
		for (int j = 1;j<=n;j++){
			if (j!=pos) c[i][++top] = {a[j], {j, pos}};
		}
		sort(c[i]+1, c[i]+n);
	}
}

int main(){
	// freopen("input.txt", "r", stdin); cerr << "----------------------------------- Program output -----------------------------------\n";
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	init(); ll sum; int cnt, p; edge z;
	for (int i = 3;i<(2<<k);i += 2){
		sum = cnt = 0; while (q.size()) q.pop();
		for (int j = 0;j<=k;j++){
			pos[j] = 1;
			if ((1<<j)&i) q.push(INF-16ll*c[j][1].first+j), sum += val[j];
		}
		dsu_init();
		while (cnt!=n-1 && !q.empty()){
			p = q.top()&15, q.pop();
			z = c[p][pos[p]]; pos[p]++;
			if (fa[z.second.first]!=fa[z.second.second] && merge(z.second.first, z.second.second)) sum += z.first, cnt++;
			if (sum>ans) break;
			if (pos[p]<n) q.push(INF-16ll*c[p][pos[p]].first+p);
		}
		checkmin(ans, sum);
	}
	printf("%lld\n", ans);
	return 0;
}
/*
self check:
1. freopen
2. long long
3. size of array
4. code for testing
*/