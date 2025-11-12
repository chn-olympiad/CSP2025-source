#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e4 + 5,M = 1e6 + 5;
int n,m,k,fa[N],ans,c[15],a[15][N],siz;
struct edge{
	int u,v,w;
} E[M],E2[M],E3[M];
bool cmp(edge f1,edge f2){
	return f1.w < f2.w;
}
vector <pair<int,int> > e[N];
int find(int x){
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}
void kruskal(){
	sort(E + 1,E + m + 1,cmp);
	int cnt = 0;
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= m; i++){
		int find1 = find(E[i].u),find2 = find(E[i].v); 
		if(find1 != find2){
			fa[find1] = find2;
			E2[++cnt].u = E[i].u;
			E2[cnt].v = E[i].v;
			E2[cnt].w = E[i].w;
			ans += E[i].w;
			if(cnt == n - 1) break;
		}
	}
}
int kruskal2(int cont){
	sort(E3 + 1,E3 + siz + 1,cmp);
	int fcnt = 0,res = 0;
	for(int i = 1; i <= n + k; i++) fa[i] = i;
	for(int i = 1; i <= siz; i++){
		int find1 = find(E3[i].u),find2 = find(E3[i].v);
		if(find1 != find2){
			fa[find1] = find2;
			++fcnt;
			res += E3[i].w;
			if(fcnt == cont - 1) break;
		}
	}
	return res;
}
int solve(int x){
	int fres = 0,cont = 0;
	for(int i = 1; i < n; i++) E3[i] = E2[i];
	siz = n - 1;
	for(int i = 0; i < k; i++){
		if((x >> i) & 1){
			++cont;
			fres += c[i + 1];
			for(int j = 1; j <= n; j++){
				E3[++siz].u = n + i + 1;
				E3[siz].v = j;
				E3[siz].w = a[i + 1][j];
			}
		}
	}
	return fres + kruskal2(cont + n);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) cin >> E[i].u >> E[i].v >> E[i].w;
	kruskal();
	if(k == 0){
		cout << ans << '\n';
		return 0;
	}
	for(int i = 1; i <= k; i++){
		cin >> c[i];
		for(int j = 1; j <= n; j++) cin >> a[i][j];
	}
	for(int i = 1; i < (1 << k); i++){
		ans = min(ans,solve(i));
	}
	cout << ans;
	return 0;
}
