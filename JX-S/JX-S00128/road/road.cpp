#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10,M = 1e6 + 10;
struct edge{
	int u,v,w,oo;
}r[20000000];
int n,m,k,idx,c[20],a[20][N],fa[N];
long long cost;
bool vis[20];
int find(int x){
	if(fa[x] == x) return fa[x];
	return fa[x] = find(fa[x]);
}
bool cmp(edge A,edge B){
	return A.w < B.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1 ; i <= m ; i ++)
		cin >> r[i].u >> r[i].v >> r[i].w,r[i].oo = 0;
	idx = m;
	for(int i = 1 ; i <= k ; i ++){
		cin >> c[i];
		for(int j = 1 ; j <= n ; j ++) cin >> a[i][j];
	}
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= n ; j ++)
			for(int q = 1 ; q <= k ; q ++)
				r[++ idx] = {i,j,c[q] + a[q][i] + a[q][j],q};
	sort(r + 1,r + idx + 1,cmp);
	for(int i = 1 ; i <= n ; i ++) fa[i] = i;
	for(int i = 1 ; i <= idx ; i ++){
		int uu = r[i].u,vv = r[i].v,ww = r[i].w;
		int p = find(uu),q = find(vv);
		if(p == q) continue;
		fa[p] = q,cost += ww;
		if(r[i].oo != 0){
			if(vis[r[i].oo]) cost -= c[r[i].oo];
			else vis[r[i].oo] = 1;
		}
	}
	cout << cost;
	return 0;
}
