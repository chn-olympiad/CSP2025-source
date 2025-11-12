#include <bits/stdc++.h>
using namespace std;
const int N = 10015, M = 1100005;
struct road{
	int u, v, w;
}r[M];
bool cmp(road a, road b){
	if (a.w == b.w){
		if (a.u == b.u){
			return a.v < b.v;
		}
		return a.u < b.u;
	}
	return a.w < b.w;
}
int n, m, k, c[15], a[15][N], fa[N];
int find(int x){
	if (fa[x] == x){
		return x;
	}
	return fa[x] = find(fa[x]);
}
void merge(int x, int y){
	x = find(x), y = find(y);
	if (x == y) return;
	fa[x] = y;
}
int read(){
	char ch = getchar();
	int x = 0;
	while(isdigit(ch)){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);	
	n = read();m = read();k = read();
	for (int i = 1; i <= m; ++i){
		r[i].u = read();r[i].v = read();r[i].w = read();
	}
	int cnt = m;
	for (int i = 1; i <= k; ++i){
		c[i] = read();
		int flag = 1, pos;
		for (int j = 1; j <= n; ++j){
			a[i][j] = read();
			if (a[i][j] == 0){
				flag = 0;
				pos = j;
			}
		}
		if (flag == 0 && c[i] == 0){
			for (int j = 1; j <= n; ++j){
				r[++cnt].u = pos;
				r[cnt].v = j;
				r[cnt].w = a[i][j];
			}
			--i;--k;
		}
	}
	m = cnt;
	if (k == 0){//kuscal
		long long ans = 0;
		sort(r + 1, r + m + 1, cmp);
		for (int i = 1; i <= n; ++i){
			fa[i] = i;
		}
		for (int i = 1, ci = 0; i <= m && ci != n - 1; ++i){
			if (find(r[i].u) != find(r[i].v)){
				++ci;
				ans += r[i].w;
				merge(r[i].u, r[i].v);
			}
		}
		cout << ans;
		return 0;
	}
	long long all_ans = 0x3f3f3f3f; 
	for (int i = 0; i <= (1 << k) - 1; ++i){
		long long ans = 0;
		int cnt2 = m, usedd = 0;
		for (int j = 1; j <= k; ++j){
			if ((1 << (j - 1)) & i){
				++usedd;
				ans += c[j];
				for (int l = 1; l <= n; ++l){
					r[++cnt2].u = n + j;//n+jÎª½Úµã 
					r[cnt2].v = l;
					r[cnt2].w = a[j][l];
				}
			}
		}
		if (ans >= all_ans)continue;
		sort(r + 1, r + cnt2 + 1, cmp);
		for (int j = 1; j <= n + k; ++j){
			fa[j] = j;
		}
		for (int j = 1, ci = 0; j <= cnt2 && ci != n - 1 + usedd; ++j){
			if (find(r[j].u) != find(r[j].v)){
				++ci;
				ans += r[j].w;
				merge(r[j].u, r[j].v);
			}
		}
		all_ans = min(all_ans, ans);
	}
	cout << all_ans;
	return 0;
}
