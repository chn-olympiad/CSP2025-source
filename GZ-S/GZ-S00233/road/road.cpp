//GZ-S00233 盘州市第二中学 李泽鑫
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4 + 10, M = 1e6 + 10;
int n, m, k;
int p[N];
int find(int x){
	if(x == p[x])return x;
	return p[x] = find(p[x]);
}
struct sb{
	int be, en;
	ll w;
	int st;
}d[M * 2];
ll a[20][N], c[20];
bool cmp(sb a, sb b){
	return a.w < b.w;
}
ll ans = 0;
int cnt;
int res = 0;
bool fl[N];
void kuscal(){
	for(int i = 1; i <= cnt; i ++ ){
		int fx = find(d[i].be), fy = find(d[i].en);
		if(fx == fy)continue;
		p[fx] = fy;
		if(d[i].st != 0){
			if(fl[d[i].st])ans -= c[d[i].st];
			else{
				fl[d[i].st] = true;
			}
		}
		ans += d[i].w;
		res ++ ;
		if(res == n - 1)return;
	}
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	if(k == 0){
		for(int i = 1; i <= n; i ++ )p[i] = i;
		for(int i = 1; i <= m; i ++ ){
			int x, y;
			ll z;
			scanf("%d%d%lld", &x, &y, &z);
			d[i] = {x, y, z, 0};
		}
		cnt = m;
		sort(d + 1, d + cnt + 1, cmp);
		kuscal();
		printf("%lld\n", ans);
	}
	else{
		for(int i = 1; i <= n; i ++ )p[i] = i;
		for(int i = 1; i <= m; i ++ ){
			int x, y;
			ll z;
			scanf("%d%d%lld", &x, &y, &z);
			d[i] = {x, y, z, 0};
		}
		cnt = m;
		for(int i = 1; i <= k; i ++ ){
			scanf("%lld", &c[i]);
			for(int j = 1; j <= n; j ++ ){
				scanf("%lld", &a[i][j]);
			}
		}
		for(int i = 1; i <= k; i ++ ){
			for(int x = 1; x <= n; x ++ ){
				for(int y = 1; y <= n; y ++ ){
					if(x != y)
						d[++ cnt] = {x, y, c[i] + a[i][x] + a[i][y], i};
				}
			}
		}
		sort(d + 1, d + cnt + 1, cmp);
		kuscal();
		printf("%lld\n", ans);
	}
	return 0;
}
