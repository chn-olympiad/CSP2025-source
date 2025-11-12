#include<bits/stdc++.h>
#define int long long

using namespace std;
const int N = 1e4 + 10;

struct node{
	int u, v, w;
}edge[3000005];

int n, m ,k;
int u, v, w, fa[N], w2[N], cnt;

bool cmp(node a, node b){
	return a.w < b.w;
}

int find(int x){
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%lld %lld %lld", &n, &m, &k);
	for(int i = 1; i <= m; i++){
		scanf("%lld %lld %lld", &u, &v, &w);
		edge[++cnt].u = u;
		edge[cnt].v = v;
		edge[cnt].w = w;
	}
	for(int i = 1; i <= k; i++){
		cin >> w;
		for(int j = 1; j <= n; j++) cin >> w2[j];
		for(int j = 1; j <= n; j++){
			for(int k = j + 1; k <= n; k++){
				edge[++cnt].u = j;
				edge[cnt].v = k;
				edge[cnt].w = w + w2[k] + w2[j];	
			}
		}
	}
	sort(edge + 1, edge + cnt + 1, cmp);
	for(int i = 1; i <= n; i++) fa[i] = i;
	int cnt1 = 0, ans = 0;
	for(int i = 1; ; i++){
		u = edge[i].u;
		v = edge[i].v;
		int x = find(u), y = find(v);
		if(x != y){
			ans += edge[i].w;
			cnt1++;
			fa[x] = y;
		}
		if(cnt1 == n - 1) break;
	}
	printf("%lld", ans);
	return 0;
}
/*
Ren5Jie4Di4Ling5%
5211673674
*/
