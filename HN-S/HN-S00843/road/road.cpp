#include <bits/stdc++.h>
#define cin fin
#define cout fout
#define endl '\n'
using namespace std;
ifstream fin("road.in");
ofstream fout("road.out");
int fa[10030],rnk[10030];
int query(int u){
	int rt = u;
	while (fa[rt] != rt)
		rt = fa[rt];
	while (fa[u] != u){
		int tmp = fa[u];
		fa[u] = rt;
		u = tmp;
	}
	return rt;
}
void modify(int u,int v){
	int fu = query(u),fv = query(v);
	if (rnk[fu] < rnk[fv])
		swap(fu,fv);
	fa[fv] = fu;
	if (rnk[fu] == rnk[fv])
		rnk[fu]++;
}
tuple<int,int,int> e[2000010];
int tot = 1;
long long kruskal(){
	sort(e + 1,e + tot);
	long long res = 0;
	for (int i = 1;i < tot;i++)
		if (query(get<1>(e[i])) != query(get<2>(e[i]))){
			modify(get<1>(e[i]),get<2>(e[i]));
			res += get<0>(e[i]);
		} 
	return res;
}
bool flag[20];
int n,m,k,c[10010],a[20][10010];
long long ans = LLONG_MAX;
void solve(){
	long long sum = 0;
	for (int i = 1;i <= k;i++)
		if (flag[i]){
			sum += c[i];
			for (int j = 1;j <= n;j++)
				for (int l = 1;l <= n;l++)
					if (j != i)
						e[tot++] = make_tuple(a[i][j] + a[i][l],j,l);
		}
	for (int i = 1;i <= n;i++)
		fa[i] = i,rnk[i] = 1;
	ans = min(ans,sum + kruskal());
	for (int i = 1;i <= k;i++)
		if (flag[i])
			for (int j = 1;j <= n;j++)
				for (int l = 1;l <= n;l++)
					if (j != i)
						tot--;
}
void dfs(int pos){
	if (pos > k){
		solve();
		return;
	}
	dfs(pos + 1);
	flag[pos] = true;
	dfs(pos + 1);
	flag[pos] = false;
}
int main(){
	cin >> n >> m >> k;
	while (m--){
		int u,v,w;
		cin >> u >> v >> w;
		e[tot++] = make_tuple(w,u,v);
	}
	for (int i = 1;i <= k;i++){
		cin >> c[i];
		for (int j = 1;j <= n;j++)
			cin >> a[i][j];
	}
	dfs(1);
	cout << ans << endl;
	return 0;
}
