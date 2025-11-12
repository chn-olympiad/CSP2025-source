#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10010;
const int MAXM = 1000010;
struct node{
	int u, v, w;
}e[2 * MAXM], e1[2 * MAXN];
int n, m, k, ans;
int fa[MAXN];
bool vis[MAXN];
int c[15][MAXN];
int find(int x){
	if(fa[x] == x){
		return x;
	}
	return fa[x] = find(fa[x]);
}
bool cmp(node x, node y){
	return x.w < y.w;
}
void dfs(int x){
	if(x > k){
		int tn = n, tm = m, sum = 0;
		for(int i = 1; i <= m; i++){
			e1[i] = e[i];
		}
		for(int i = 1; i <= k; i++){
			if(vis[i] == 1){
				sum += c[i][0];
				tn++;
				for(int j = 1; j <= n; j++){
					tm++;
					e1[tm].u = tn;
					e1[tm].v = j;
					e1[tm].w = c[i][j];
				}
			}
		}
		for(int i = 1; i <= tn; i++){
			fa[i] = i;
		}
		sort(e1 + 1, e1 + tm + 1, cmp);
		int i = 0, t = tn;
		while(t > 1){
			i++;
			int u = e1[i].u;
			int v = e1[i].v;
			int w = e1[i].w;
			if(find(u) != find(v)){
				fa[find(u)] = fa[find(v)];
				sum += w;
				t--;
			}
		}
		ans = min(ans, sum);
		return;
	}
	dfs(x + 1);
	vis[x] = 1;
	dfs(x + 1);
	vis[x] = 0;
	return;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	bool flag = true;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= m; i++){
		scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
	}
	for(int i = 1; i <= k; i++){
		for(int j = 0; j <= n; j++){
			scanf("%d", &c[i][j]);
		}
		if(c[i][0] != 0){
			flag = false;
		}
	}
	if(k == 0){
		for(int i = 1; i <= n; i++){
			fa[i] = i;
		}
		sort(e + 1, e + m + 1, cmp);
		int i = 0, t = n;
		ans = 0;
		while(t > 1){
			i++;
			int u = e[i].u;
			int v = e[i].v;
			int w = e[i].w;
			if(find(u) != find(v)){
				fa[find(u)] = fa[find(v)];
				ans += w;
				t--;
			}
		}
		printf("%d\n", ans);
	}
	else{
		ans = 1e9;
		if(flag){
				int tn = n, tm = m, sum = 0;
				for(int i = 1; i <= k; i++){
					vis[i] = 1;
				}
				for(int i = 1; i <= m; i++){
					e1[i] = e[i];
				}
				for(int i = 1; i <= k; i++){
					if(vis[i] == 1){
						tn++;
						for(int j = 1; j <= n; j++){
							tm++;
							e1[tm].u = tn;
							e1[tm].v = j;
							e1[tm].w = c[i][j];
						}
					}
				}
				for(int i = 1; i <= tn; i++){
					fa[i] = i;
				}
				sort(e1 + 1, e1 + tm + 1, cmp);
				int i = 0, t = tn;
				while(t > 1){
					i++;
					int u = e1[i].u;
					int v = e1[i].v;
					int w = e1[i].w;
					if(find(u) != find(v)){
						fa[find(u)] = fa[find(v)];
						sum += w;
						t--;
					}
				}
				ans = sum;
				printf("%d\n", ans);
		}
		else{
			dfs(1);
			printf("%d\n", ans);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/

/*
6 9 1
1 3 1
1 2 5
2 3 3
3 4 2
2 4 6
2 5 1
5 6 2
5 4 3
4 6 4
0 1 1 1 1 1 1
*/