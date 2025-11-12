#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int, int>
#define debug(x) cerr << #x << ": " << x << "\n"
#define int long long
using namespace std;
struct edge{
	int u, v, w;
	bool operator <(edge b){
		return w < b.w;
	}
}a[1000007];
int n, m, k, c[17], b[17][10007], fa[10007], mb[17][10007];
int find(int x){
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
inline void merge(int x, int y){
	int f1 = find(x), f2 = find(y);
	if(x == y) return;
	fa[f1] = f2;
}
inline void merge1(int x, int y){
	int f1 = find(x), f2 = find(y);
	if(x == y) return;
	fa[f1] = f2;
	for(int j = 1;j <= k;j++)
		mb[j][f2] = min(mb[j][f2], mb[j][f1]);
}
void solve14(){
	sort(a + 1, a + 1 + m);
	int cnt = 0, ans = 0;
	for(int i = 1;i <= m;i++){
		if(find(a[i].u) != find(a[i].v)){
			merge(a[i].u, a[i].v);
			cnt++;
			ans += a[i].w;
		}
		if(cnt == n - 1) break;
	}
	cout << ans;
}
void solvek5(){
	sort(a + 1, a + 1 + m);
	int ans = 0x3f3f3f3f3f3f3f3f;
	for(int st = 0;st <= (1 << k) - 1;st++){
		for(int i = 1;i <= n;i++) fa[i] = i;
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= k;j++)
				mb[j][i] = b[j][i];
		int res = 0, cnt = 0;
		for(int j = 1;j <= k;j++) if(st & (1 << (j - 1))) res += c[j];
		for(int i = 1;i <= m;i++){
			if(find(a[i].u) != find(a[i].v)){
				int ww = a[i].w;
				for(int j = 1;j <= k;j++)
					if(st & (1 << (j - 1))) ww = min(ww, mb[j][find(a[i].u)] + mb[j][find(a[i].v)]);
				res += ww;
				cnt++;
				merge1(a[i].u, a[i].v);
			}
			if(cnt == n - 1 || res > ans) break;
		}
		ans = min(ans, res);
	}
	cout << ans;
}
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++) cin >> a[i].u >> a[i].v >> a[i].w;
	for(int j = 1;j <= k;j++){
		cin >> c[j];
		for(int i = 1;i <= n;i++) cin >> b[j][i];
	}
	for(int i = 1;i <= n;i++) fa[i] = i;
	if(k == 0) solve14();
	else solvek5();
}
