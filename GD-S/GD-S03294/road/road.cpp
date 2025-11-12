#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, j, k) for(int i = j; i <= k; i++)
#define ll long long 
#define rop(i, j, k) for(int i = j; i >= k; i--)
#define big __int128
#define ull unsigned ll 
using namespace std;
const int N = 1e4 + 5, M = 1e6 + 5;
const ll inf = 1e15 + 7;
ll res = inf;
int n, m, k, fa[N], c[N], cnt;
struct edge{
	int u, v;
	ll w;
}a[M << 2], b[M];
struct poi{
	int v, w;
};
vector<poi> g[N];
bool cmp(edge x, edge y){return x.w < y.w;}
int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	rep(i, 1, m){
		int u, v, w;
		cin >> u >> v >> w;
		b[i] = a[i] = {u, v, w};
	}
	rep(i, 1, k){
		cin >> c[i];
		rep(j, 1, n){
			int x;
			cin >> x;
			g[i].push_back({j, x});
		}
	}
	int lim = (1 << k) - 1;
	rep(i, 0, lim){
		cnt = m;
		ll now = 0, cst = 0;
		rep(i, 0, n) fa[i] = i;
		rep(j, 1, m) a[i] = b[i];
		rep(j, 1, k){
			if((i >> j) & 1){
				cst += c[j];
				rep(l, 0, n - 1){
					int v = g[j][l].v, w = g[j][l].w;
					a[++cnt] = {0, v, w};
				}
			}
		}
		stable_sort(a + 1, a + cnt + 1, cmp);
		rep(i, 1, cnt){
			int fx = find(a[i].u), fy = find(a[i].v);
			if(fx == fy) continue;
			now += a[i].w;
			fa[fx] = fy;
		} 
		res = min(res, now + cst);
	}	
	cout << res << "\n";
	return 0;	
} 
