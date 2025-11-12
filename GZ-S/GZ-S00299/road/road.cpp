//  GZ-S00299 游景智 毕节梁才学校  
#include<bits/stdc++.h>
//using namespace std; 别写了到时候爆了 
typedef long long ll;
ll ans = 0;
ll mi = 0x3f3f3f3f3f3f3f3f;
const int N = 1e4 + 10;
const int M = 1e6 + 10 + N * 10; 
struct NODE{
	int u, v, w;
}E[M];
bool cmp(NODE a, NODE b){
	return a.w < b.w;
}
int idx;
int n, m, k;
int a[30][N];
int p[N];
int find(int x){
	if(x != p[x]){
		p[x] = find(p[x]);
	}
	return p[x];
}
bool kruskal(){
	std::sort(E + 1, E + idx + 1, cmp);
	int cnt = 0;
	for(int i = 1; i <= idx; i++){
		int x = E[i].u, y = E[i].v;
		int gx = find(x), gy = find(y);
		if(gx != gy){
			if(y >= n)p[gy] = gx;
			else{
				p[gx] = gy;
			}
			ans += 0ll + E[i].w;
			if(gx <= n && gy <= n)
				cnt ++;
			if(cnt == n - 1){
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; i++){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		E[++idx].u = u;
		E[idx].v = v;
		E[idx].w = w;
	}
	for(int i = 0; i < k; i++){ // 注意 
		for(int j = 0; j <= n; j++){
			scanf("%d", &a[i][j]);
		}
	}
	for(int msk = 0; msk < (1 << k); msk++){
//		std::cout << msk << std::endl;
		ans = 0;
		for(int j = 0; j < k; j++){
			if((msk >> j) & 1){
				ans += a[j][0];
				for(int i = 1; i <= n; i++){
					E[++idx].u = j + n + 1;
					E[idx].v = i;
					E[idx].w = a[j][i];
					E[++idx].v = j + n + 1;
					E[idx].u = i;
					E[idx].w = a[j][i];
				}
			}
		}
	
		for(int i = 1; i <= n + k + 1; i++){
			p[i] = i;
		}
		if(kruskal())	mi = std::min(mi, ans);
		idx = n; // 注意
//		printf("%d %lld\n", msk, ans);
	
	}
	printf("%lld\n", mi);
	return 0;
} 
