#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10, M = 1e6 + 10, INF = 1e9 + 7;
int f[N + 10],c[15],val[15][N];
int n,m,k; 
long long ans;
struct pt{
	int u,v,w;
}e[M + N * 10];
bool cmp(pt a,pt b){
	return a.w < b.w;
}
int find(int x){
	return f[x] == x ? f[x] : f[x] = find(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	sort(e + 1,e + m + 1,cmp);
	for(int i = 1;i <= n;i++)
		f[i] = i;
	int cnt = 0;
	for(int i = 1;i <= m;i++){
		int cu = e[i].u, cv = e[i].v, cw = e[i].w;
		int fu = find(cu), fv = find(cv);
		if(fu != fv){
			f[fu] = fv; 
			ans += cw;
		}
	}
	for(int i = 1;i <= k;i++){
		cin >> c[i];
		for(int j = 1;j <= n;j++){
			cin >> val[i][j];
		}
	} 
	cout << ans << '\n';
	return 0;
}
