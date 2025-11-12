#include<bits/stdc++.h>
#define FILE(x) freopen(#x".in","r",stdin), freopen(#x".out","w",stdout)
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 2e4 + 24, km = 2e6 + 26;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int n, m, K;
ll b[15], a[15][kn];
class Edge{
	public:
	int x, y;
	ll w, sp = -1;
	int i = -1;
	Edge(){ sp = i = -1; }
	bool operator < (const Edge &v) const {
		return (max(w, sp) == max(v.w, v.sp)) ? w < v.w : max(w, sp) < max(v.w, v.sp);
	}
}e[km];

int ct = 0, fu[kn], cnt[15];
ll lst[15];
int find(int x){ return fu[x] == x ? x : fu[x] = find(fu[x]); }
inline ll kruskal(){
	ll ans = 0;
	for(int i=1; i<=n+K; ++i) fu[i] = i;
	sort(e + 1, e + ct + 1);
	for(int i=1; i<=ct; ++i){
		int x = e[i].x, y = e[i].y;
		if(find(x) != find(y)){
			fu[find(y)] = find(x);
			ans += e[i].w;
			if(e[i].i != -1){
				++cnt[e[i].i];
				lst[e[i].i] = e[i].w;
			}
		}
	}
	for(int i=1; i<=K; ++i){
		if(cnt[i] > 1) ans += b[i];
		else if(cnt[i] == 1) ans -= lst[i];
	}
	return ans;
}

signed main(){
//	freopen("road4.in","r",stdin);
	FILE(road);
	cin.tie(0)->ios::sync_with_stdio(false);
	cin >> n >> m >> K;
	for(int i=1; i<=m; ++i){
		++ct;
		cin >> e[ct].x >> e[ct].y >> e[ct].w;
	}
	for(int i=1; i<=K; ++i){
		cin >> b[i];
		ll mini = inf;
		for(int j=1; j<=n; ++j){
			cin >> a[i][j];
			mini = min(mini, a[i][j]);
		}
		for(int j=1; j<=n; ++j){
			e[++ct].x = n + i;
			e[ct].y = j;
			e[ct].w = a[i][j];
			e[ct].sp = mini + b[i];
			e[ct].i = i;
		}
	}
	printf("%lld\n", kruskal());
	return 0;
}
