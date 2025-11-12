#include<bits/stdc++.h>
#define N 10010
#define M 2000010 
using namespace std;
int n, m, k;
int cost[N], v[N], fa[N], d[N];
int cnt, ini[N];
struct edg{
	int x, y, z;
	int id;
	bool operator<(const edg &a)const{
		return z < a.z;
	}
}edge[M], edg1[M];
void add(int x, int y, int z, int tpy){
	edge[++cnt].x = x;
	edge[cnt].y = y;
	edge[cnt].z = z;
	edge[cnt].id = tpy;
}
edg build(int x, int y, int z, int id){
	edg temp;
	temp.x = x;
	temp.y = y;
	temp.z = z;
	temp.id = id;
	return temp;
}
int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]); 
}
long long kruskal(){
	memset(v, 0, sizeof(v));
	for(int i = 1; i <= n; i++) fa[i] = i;
	sort(edge + 1, edge + cnt + 1);
	long long res = 0, cnt_n = 0;
	for(int i = 1; i <= cnt; i++){
		int fx = find(edge[i].x), fy = find(edge[i].y);
		if(fx != fy){
			if(edge[i].id){
				if(ini[edge[i].id] == edge[i].z - cost[edge[i].id] || v[edge[i].id] == 1){
					v[edge[i].id] = 1;
				}
				else{
					continue;
				}
			}
			fa[fy] = fx;
			res += edge[i].z;
			cnt_n++;
		}
		if(cnt_n == n - 1) break;
	}
	return res;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	memset(ini, 0, sizeof(ini));
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= m; i++){
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		add(x, y, z, 0);
	}
	for(int i = 1; i <= k; i++){
		scanf("%d", &cost[i]);
		memset(d, 0, sizeof(d));
		for(int j = 1; j <= n; j++)scanf("%d", &d[j]);
		int cnt1 = 0;
		for(int j = 1; j <= n; j++){
			for(int k = j + 1; k <= n; k++){
				edg1[++cnt1] = build(j, k, d[j] + d[k], i);
			}
		}
		sort(edg1 + 1, edg1 + cnt1 + 1);
		for(int j = 1; j <= cnt1; j++){
			if(j == 1){
				add(edg1[j].x, edg1[j].y, edg1[j].z + cost[i], edg1[j].id);
				ini[i] = edg1[j].z;
			} 
			else if(edg1[j].z == ini[i]) add(edg1[j].x, edg1[j].y, edg1[j].z + cost[i], edg1[j].id); 
			else add(edg1[j].x, edg1[j].y, edg1[j].z, edg1[j].id); 
		}
	}
	printf("%lld", kruskal());
	return 0;
}



 
