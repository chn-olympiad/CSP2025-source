// 10000*10*1000=1e8
// 肯定是枚举k的二进制 
// 不对这边数有点 
// 先跑一边MST，大量边是无效的，只记录有效边 
// 怎么还卡O(nk2^klognk)
// 要不是样例4比样例3快我就被骗了 
// 先看T3吧 
// 当前80pts，样例全过，正确性未知 
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define find I_think_this_is_chong_fu_de_ying_wen_bu_hui_da
#define int long long
using namespace std;
// pipilong2024，我喜欢你！
struct edge{
	int x, y, len;
	bool operator < (const edge &b) const{
		return len < b.len;
	}
}edges[2000005], realedge[20005], edges2[200005];
int a[15][20005], b[15];
int father[20005];
int siz[20005];
int find(int n){
	return (father[n] == n ? n : father[n] = find(father[n]));
}
bool merge(int x, int y){
	int n = find(x), m = find(y);
	if(n == m) return 0;
	if(siz[n] > siz[m]) swap(n, m);
	father[n] = m;
	siz[m] += siz[n];
	return 1;
}

int n, m, k;
int solve2(int cur){
	int ans = 0, ct = 0;
	for(int i = 1; i <= n + k; i++){
		father[i] = i;
		siz[i] = 1;
	}
	for(int i = 1; i < n; i++){
		edges2[++ct] = realedge[i];
	}
	for(int i = 0; i < k; i++){
		if(~cur >> i & 1) continue;
		ans += b[i];
		for(int j = 1; j <= n; j++){
			edges2[++ct] = {n + i + 1, j, a[i][j]};
		}
	}
	sort(edges2 + 1, edges2 + ct + 1);
	for(int i = 1; i <= ct; i++){
		int x = edges2[i].x, y = edges2[i].y, z = edges2[i].len;
		if(merge(x, y)) ans += z;
	}
	return ans;
}
void solve(){
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++){
		father[i] = i;
		siz[i] = 1;
	}
	for(int i = 1; i <= m; i++){
		int x, y, z;
		cin >> x >> y >> z;
		edges[i] = {x, y, z};
	}
	for(int i = 0; i < k; i++){
		cin >> b[i];
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	sort(edges + 1, edges + m + 1);
	int ct = 0;
	for(int i = 1; i <= m; i++){
		int x = edges[i].x, y = edges[i].y;
		if(merge(x, y)){
			realedge[++ct] = edges[i];
		}
	}
	int ans = 0x3f3f3f3f3f3f3f3fll;
	for(int i = 0; i < (1 << k); i++){
		ans = min(ans, solve2(i));
	}
	cout << ans << '\n';
}
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T = 1;
	while(T--) solve();
	
	cout.flush();
	
	return 0;
}

