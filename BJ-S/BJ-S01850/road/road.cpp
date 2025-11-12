// 道路修复
/*
 
 *  思路： 写个最小生成树 拿个部分分？
	
		加了路  乡镇的路代价 不好处理  因为 要选路就要激活乡村  
		* 
		但是应该是生成树问题
		* 
		有特殊性质 乡村道路免费
	
	
		先最小生成树  然后把免费的路都加进来
		
		
4 3 0
1 2 1
1 3 2
2 3 100





 */
#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10, M = 2e6 + 10;
typedef long long ll;
int n, m , k, flaka;
int  c[20], a[20][N], fa[N];
struct edge{
	int u, v, w;
}e[M];
bool cmp(edge a, edge b){
	return a.w < b.w;
}
int find(int u){
	if(fa[u] == u) return u;
	else {
		int tmp = find(fa[u]);
		fa[u] = tmp;
		return tmp;
	}
}
int merge(int u, int v){
	
	if(find(u) != find(v)){  //不在同一集合
		
		fa[v] = u;
		return 1;
	}
	return 0;
}
int main(){
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	scanf("%d %d %d", &n, &m, &k);
	
	for(int i = 1; i <= n; i++) fa[i] = i;
	
	for(int i = 1; i <= m; i++) scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w); //输入边
	
	sort(e+1, e+1+m, cmp); //边排序
	
	for(int i = 1; i <= k; i++ ){
		cin >> c[i];
		flaka += c[i];
		for(int j = 1; j <= n; j++) scanf("%d", &a[i][j]), flaka += a[i][j];
	}
	if(k==0 ){  // 没有乡镇 跑mst
		ll ans = 0;
		for(int i = 1; i <= m; i++){
			if(merge(e[i].u, e[i].v)) ans += e[i].w;
		}
		cout << ans;
	
	}
	else if(flaka) { // 有性质A 把边加近来 做MST
	
		ll ans = 0;
		cout << ans;
		return 0;
	}
	
	
	
	return 0;
}


	
