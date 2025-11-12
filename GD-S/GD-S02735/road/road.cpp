#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
#define int long long
#define MAXN 22005
#define MAXM 4000005

struct EDGE{
	int u, v, w;
};
int n, m, k, ans;
int fa[MAXN], c[50];
vector<EDGE> e;
bool cmp(EDGE A, EDGE B){
	return A.w < B.w;
}
int find(int x){
	if(fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}
void merge(int x, int y){
	x = find(x), y = find(y);
	if(x != y)
		fa[y] = x;
}
void solve1(){
	int tot = 0;
	sort(e.begin(), e.end(), cmp);
	for(int i = 0; i < e.size() && tot < n - 1; i++){
		int u = e[i].u, v = e[i].v, w = e[i].w;
		if(find(u) != find(v)){
			merge(u, v);
			ans += w;
			tot++;
		}
	}
	printf("%lld", ans);
}

/*
9 12 0
1 2 3
1 4 2
1 3 5
3 5 1
3 6 10
5 6 12
2 4 6
4 8 4
8 9 7
4 9 1
4 7 1
3 7 9
*/

void solve2(){
	int tot = 0;
	for(int i = 0; i < e.size() && tot < n + k - 1; i++){
		int u = e[i].u, v = e[i].v, w = e[i].w;
		if(find(u) != find(v)){
			merge(u, v);
			ans += w;
			tot++;
		}
	}
	printf("%lld", ans);
}
bool DXL[20];
int solve3(int ST){
	int res = 0, used = 0;
	for(int i = 1; i <= n + 100; i++)
		fa[i] = i;
	memset(DXL, 0, sizeof(DXL));
	for(int j = 0; j < 10; j++){
		if((ST >> j) & 1){
			DXL[j] = true;//选择了第i个村子 
			res += c[j];
			used++;
		}
	}
	int tot = 0;
	for(int i = 0; i < e.size() && tot < n + k - 1; i++){
		int u = e[i].u, v = e[i].v, w = e[i].w;
		if(u > n && DXL[u - n] == 0)
			continue;
		if(v > n && DXL[v - n] == 0)
			continue;
		if(find(u) != find(v)){
			merge(u, v);
			res += w;
			tot++;
		}
	}
	return res;
}
signed main(void){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	scanf("%lld%lld%lld", &n, &m, &k);
	for(int i = 1; i <= n + 10 * k; i++)
		fa[i] = i;
	for(int i = 1; i <= m; i++){
		int u, v, w;
		scanf("%lld%lld%lld", &u, &v, &w);
		e.push_back({u, v, w});
	}
	if(k == 0){
		solve1();
		return 0;
	}
	bool flag = false, xzA = true;
	for(int i = 1; i <= k; i++){
		scanf("%lld", c + i);
		for(int j = 1; j <= n; j++){
			int w;
			scanf("%lld", &w);
			if(!w)
				flag = true;//flag记录是否出现a=0 
			e.push_back({n + i, j, w});//第i个村子的编号是n+i 
		}
		if(!flag){//存在没有a=0的情况，不满足性质A 
			xzA = false;
		}
	}
	sort(e.begin(), e.end(), cmp);
	if(xzA){
		solve2();
		return 0;
	}
	else{
		int outp = 1e15;
		for(int i = 0; i < (1 << k); i++){
			outp = min(solve3(i), outp);
			//printf("%lld\n", outp);
		}
		printf("%lld", outp);
	}
	return 0;
}

/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
