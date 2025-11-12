#include <iostream> // 40pts
#include <algorithm>
#include <numeric>
using namespace std;

template <int N>
struct set_view {
	set_view() { iota(s + 1, s + N + 1, 1); }
	
	int find(int x) {
		while(x != s[x]) x = s[x] = s[s[x]];
		return x;
	}
	
	bool merge(int x, int y) {
		x = find(x), y = find(y);
		if(x == y) return 0;
		return s[y] = x, 1;
	}
	
	public:
		int s[N + 5];
};
set_view <1000015> t;

struct Side {
	int u, v, w;
	friend bool operator < (const Side& a, const Side& b) {
		return a.w < b.w;
	}
} g[10000005];

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	int n, m, k;
	cin>>n>>m>>k;
	for(int i = 1;i <= m;i++) {
		cin>>g[i].u>>g[i].v>>g[i].w;
	}
	for(int i = 1, c;i <= k;i++) {
		cin>>c;
		for(int j = 1, w;j <= n;j++) {
			cin>>w;
			g[++m] = {j, n + i, w};
		}
	}
	sort(g + 1, g + m + 1);
	long long ans = 0;
	for(int i = 1;i <= m;i++) {
		if(t.merge(g[i].u, g[i].v)) {
			ans += g[i].w;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
/*
6 6 1
1 3 1
1 2 2
2 4 3
3 4 1
4 6 3
4 5 4
0 10 10 10 1 1 1

*/