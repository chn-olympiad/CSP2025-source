#include <bits/stdc++.h>
#define ll long long
#define Blackdream1853 return
#define code 0
using namespace std;
const int N=1e4+1, K=11;
const ll INF=1e18+1;
int n, m, k, c[K], f[N+K];
ll ans=INF;
bool vis[11];
struct edge {
	int x, y; ll z;
	bool operator < (const edge &w) const {return z<w.z;}
};
vector <edge> v;
void init(int x) {for (int i=1;i<=x;i++) f[i]=i;}
int found(int now) {
	if (f[now]==now) return now;
	return f[now]=found(f[now]);
}
void merge(int x,int y) {f[x=found(x)]=f[y=found(y)];}
signed main(void) {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i=1;i<=m;i++) {
		int x, y, z;
		cin >> x >> y >> z;
		v.push_back({x,y,z});
	}
	for (int i=1;i<=k;i++) {
		cin >> c[i];
		for (int j=1;j<=n;j++) {
			int x; cin >> x;
			v.push_back({n+i,j,x});
		}
	}
	sort(v.begin(),v.end());
	int start=0;
	if (*max_element(c+1,c+k+1)==0) start=(1<<k)-1;
	for (int state=start;state<(1<<k);state++) {
		ll res=0; int cnt=0, num=0; init(n+k);
		for (int i=1, tmp=state;i<=k;i++, tmp>>=1)
			vis[i]=tmp&1, res+=c[i]*vis[i], num+=vis[i];
		for (auto ed:v) {
			if (cnt>=n+num) break;
			if (res>ans) break;
			int x=ed.x, y=ed.y, z=ed.z;
			if (x>n&&!vis[x-n]) continue;
			if (y>n&&!vis[y-n]) continue;
			if (found(x)==found(y)) continue;
			merge(y,x), res+=z;
			if (x<=n&&y<=n) cnt++;
		}
		ans=min(ans,res);
	}
	cout << ans << '\n';
	Blackdream1853 code;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
----13
*/
