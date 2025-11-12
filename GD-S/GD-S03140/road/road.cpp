#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 5,M = 1e6 + 5,inf = 1e17;
int n,m,k,ct,ans = inf,p[N],tmp,c[N],a[15][N];
struct E{
	int u,v,w,id;
}e[N * 10 + M];

bool cmp1(E a,E b){
	return a.w < b.w;
}
bool cmp2(E a,E b){
	return a.id < b.id;
}

int find(int x) { return p[x] == x ? x : p[x] = find(p[x]);}
int kru(int x){
	for(int i = 1;i <= n + k;i++){
		p[i] = i;
	}
	sort(e + 1,e + 1 + ct,cmp1);
	int cnt = 0,res = 0;
	for(int i = 1;i <= ct;i++){
		int u = e[i].u,v = e[i].v,w = e[i].w;
		if(find(u) == find(v)) continue;
		res += w;
		p[find(u)] = find(v);
		if(++cnt == x - 1){
			sort(e + 1,e + 1 + ct,cmp2);
			return res;
		}
	}
	sort(e + 1,e + 1 + ct,cmp2);
	return res;
}

void dfs(int x,int cnt,int sum){
	if(x == k + 1){
		ans = min(ans,kru(n + cnt) + sum);
		return;
	}
	int tmp = ct;
	for(int i = 1;i <= n;i++){
		e[++ct] = {i,n + x,a[x][i],ct};
	}
	dfs(x + 1,cnt + 1,sum + c[x]);
	ct = tmp;
	dfs(x + 1,cnt,sum);
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1,u,v,w;i <= m;i++){
		cin >> u >> v >> w;
		e[++ct] = {u,v,w,ct};
	}
	for(int i = 1;i <= k;i++){
		cin >> c[i];
		for(int j = 1;j <= n;j++){
			cin >> a[i][j];
		}
	}
	dfs(1,0,0);
	cout << ans;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
