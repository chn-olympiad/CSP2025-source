#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node{ll u, v, w;}a[2000010];
int n, m, k, fa[100020]; 
ll c[20], d[20][10010];
bool cmp(node a, node b){return a.w < b.w;}

int find(int x){
	if(x == fa[x]) return x;
	return x = find(fa[x]);
}

void merge(int x, int y){
	int fx = find(x), fy = find(y);
	if(fx == fy) return;
	fa[x] = y;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i ++){
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	for(int i = 1; i <= k; i ++){
		cin >> c[i];
		for(int j = 1; j <= n; j ++)
			cin >> d[i][j];
	}
	ll ans = 9e18;
	for(int i = 0; i < (1 << k); i ++){
		for(int j = 1; j <= n + k; j ++)
			fa[j] = j;
		ll cnt1 = 1, sum = 0, tmp = i, now = m, cnt2 = 0;
		while(tmp){
			if(tmp % 2 == 1){
				cnt2 ++;
				sum += c[cnt1];
				for(int j = 1; j <= n; j ++)
					a[++now] = {cnt1 + n, j, d[cnt1][j]};
			}
			cnt1 ++; tmp /= 2;
		}
		sort(a + 1, a + now + 1, cmp);
		ll cnt = 0;
		for(int i = 1; i <= now; i ++){
			if(find(a[i].u) == find(a[i].v)) continue;
			merge(a[i].u, a[i].v);
			cnt ++, sum += a[i].w;
			if(cnt == n + cnt2 - 1) break;
		}
		if(cnt == n + cnt2 - 1) ans = min(ans, sum);
	}
	cout << ans;
	return 0;
}
