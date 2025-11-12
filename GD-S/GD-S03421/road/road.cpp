#include<bits/stdc++.h>
using namespace std;

struct RD{
	int u, v, w;
} rd[1300086];

int cnt = 0;

vector<int> rod[10086];

int c[15];
int cw[15][10086];
int colnum[10086];
int col[10086];
long long ans;

bool cmp(RD x, RD y){
	if(x.w != y.w) return x.w < y.w;
	if(x.u != y.u) return x.u < y.u;
	return x.v < y.v;
}

void paint(int fa, int nw, int cl){
	colnum[col[nw]] --;
	colnum[col[cl]] ++;
	col[nw] = cl;
	for(auto i : rod[nw]){
		if(i != fa){
			paint(nw, i, cl);
		}
	}
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	int u, v, w;
	
	for(int i = 1; i <= m; i++){
		scanf("%d%d%d", &u, &v, &w);
		if(u > v) swap(u, v);
		cnt++;
		rd[cnt] = {u, v, w};
	}
	
	for(int i = 1; i <= k; i++){
		scanf("%d", &c[i]);
		for(int j = 1; j <= n; j++){
			scanf("%d", &cw[i][j]);
			u = i + n; v = j; w = cw[i][j];
			if(u > v) swap(u, v);
			cnt++;
			rd[cnt] = {u, v, w};
		}
	}
	
	sort(rd+1, rd+1+cnt, cmp);
	
	for(int i = 1; i <= n; i++){
		col[i] = i;
		colnum[i] = 1;
	}
	int ccnt = 0;
	for(int i = 1; i <= cnt; i++){
		if(ccnt == n + k - 1) break;
		RD t = rd[i];
		if(col[t.u] == col[t.v]) continue;
		if(colnum[t.u] < colnum[t.v]) swap(t.u, t.v);
		paint(t.v, t.v, col[t.u]);
		rod[t.u].push_back(t.v);
		rod[t.v].push_back(t.u);
		ans += t.w;
		ccnt++;
	}
	
	printf("%lld", ans);
	return 0;
}
