#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){
	int cnt = 0, sign = 1;
	char c = getchar();
	while(!isdigit(c)){
		if(c == '-')	sign = -1;
		c = getchar();
	}
	while(isdigit(c)){
		cnt = (cnt << 1) + (cnt << 3) + (c ^ 48);
		c = getchar();
	}
	return cnt * sign;
}
const int N = 1e4 + 10;
int fa[N];
int find(int u){
	return fa[u] == u ? u : fa[u] = find(fa[u]);
}
void merge(int u, int v){
	int fu = find(u), fv = find(v);
	if(fu != fv){
		fa[fu] = fv;
	}
}
struct edge{
	int u, v, w;
}mapp[N];
int sk[20], wk[20][N];
priority_queue <edge> q;
bool operator < (const edge& a, const edge& b){
	return a.w > b.w;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	
	int n = read(), m = read(), k = read();
	for(int i = 1; i <= m; i++){
		int u = read(), v = read(), w = read();
		q.push({u, v, w});
	}
	for(int i = 1; i <= n; i++)	fa[i] = i;
	for(int i = 1; i <= k; i++){
		sk[i] = read();
		for(int j = 1; j <= n; j++){
			wk[i][j] = read();
		}
	}
	int cnt = 1;
	ll ans = 0;

	while(cnt < n){
		edge tp = q.top();
		q.pop();
		int fu = find(tp.u), fv = find(tp.v);
		if(fu != fv){
			fa[fu] = fv;
			int minn = tp.w;
			for(int i = 1; i <= k; i++){
				minn = min(minn, wk[i][tp.u] + wk[i][tp.v]);
			}
			ans += minn;
//			printf(">>%d\n", minn);
			cnt++;
		}
	}
	printf("%lld", ans);
	return 0;
}
/*
5 6 0
1 2 1
1 3 5
1 5 2
2 3 4
3 5 3
5 4 7
*/
//20pts
