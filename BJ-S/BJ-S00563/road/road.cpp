#include <bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x = 0,f = 1;
	char ch = getchar();
	while (!isdigit(ch)){
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (isdigit(ch)){
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
void write(int x){
	if (x < 0){
		putchar('-');
		write(-x);
		return ;
	}
	if (x < 10){
		putchar(x + '0');
		return ;
	}
	write(x / 10);
	putchar(x % 10 + '0');
}
struct edge {
	int u,v,w;
}e[2000050];
bool cmp(edge x,edge y){
	return x.w < y.w;
}
vector <pair <int,int> > ed[10500],tr[10050];
int n,m,k;
int c[15];
int a[15][10050];
int fa[10050];
void init(int n){
	for (int i = 1;i <= n;i++) fa[i] = i;
}
int find(int x){
	if (x == fa[x]) return x;
	else return fa[x] = find(fa[x]);
}
int flag[15];
int kruskal(){
	int ans = 0,cnt = 0;
	for (int i = 1;i <= m;i++){
		if (cnt == n + k - 1) break;
		int u = e[i].u,v = e[i].v,w = e[i].w;
		int fu = find(u),fv = find(v);
		if (fu == fv) continue;
		fa[fu] = fv;
		ans += w;
		cnt++;
		tr[u].push_back(make_pair(v,w));
		tr[v].push_back(make_pair(u,w));
		if (u > n || v > n){
			int tmp;
			if (u > n) tmp = u - n;
			else tmp = v - n;
			if (flag[tmp]) continue;
			flag[tmp] = 1;
			for (int j = 1;j <= m;j++) if (e[j].u == n + tmp || e[j].v == n + tmp) e[j].w -= c[tmp];
			sort(e + 1,e + m + 1,cmp);
			i = 1;
		}
	}
	return ans;
}
int Fa[10050];
void dfs(int u,int f){
	Fa[u] = f;
	for (int i = 0;i < tr[u].size();i++){
		int v = tr[u][i].first;
		if (v == f) continue;
		dfs(v,u);
	} 
}
int now = 0;
bool cmp2(pair <int,int> x,pair <int,int> y){
	return x.second - a[now][x.first] > y.second - a[now][y.first];
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = read(),m = read(),k = read();
	init(n + k);
	for (int i = 1;i <= m;i++){
		int u,v,w;
		u = read(),v = read(),w = read();
		e[i] = {u,v,w};
	}
	for (int i = 1;i <= k;i++){
		c[i] = read();
		for (int j = 1;j <= n;j++) a[i][j] = read(),e[++m] = {n + i,j,a[i][j] + c[i]};
	}
	sort(e + 1,e + m + 1,cmp);
	int ans = kruskal();
	dfs(1,0);
	for (int i = 1;i <= k;i++){
		int u = i + n;
		if (tr[u].size() == 1){
			int v = Fa[u];
			for (int j = 0;j < tr[v].size();j++){
				if (tr[v][j].first == u){
					ans -= tr[v][j].second;
					ans -= c[u];
					break;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}