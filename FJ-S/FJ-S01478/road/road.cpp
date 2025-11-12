#include<bits/stdc++.h>
#define ll long long

using namespace std;
const ll N = 1e4 + 15;
const ll M = 1e6 + 15; 

int n,m,k;

struct node{
	int u,v,w;
}G[M + 10 * N];

struct edge{
	int c,a[N];
}Q[15];

int fa[N];

int Gfa(int u){
	if(fa[u] == u) return u;
	fa[u] = Gfa(fa[u]);
	return fa[u];
}

int cmp(node x,node y){
	return x.w < y.w;
}

void subtask1(){
	ll ans = 0;
	sort(G + 1,G + 1 + m,cmp);
	int now = 0;
	for(int i = 1; i <= m; i++){
		int uu = G[i].u,vv = G[i].v;
		int au = Gfa(uu),av = Gfa(vv);
		if(au == av)continue;
		now ++;
		fa[au] = av,fa[au] = Gfa(av); 
		ans += G[i].w;
		if(now == n - 1) break;
	}
	cout << ans << "\n";
}

void subtask2(){
	for(int i = 1; i <= k; i++)
		for(int j = 1; j <= n; j++)
			G[m + (i - 1) * n + j].u = j,G[m + (i - 1) * n + j].v = n + i,G[m + (i - 1) * n + j].w = Q[i].a[j]; 
			
	sort(G + 1,G + 1 + m + n * k,cmp);
	int now = 0;
	ll ans = 0;
	for(int i = 1; i <= m + n * k; i++){
		int uu = G[i].u,vv = G[i].v;
		int au = Gfa(uu),av = Gfa(vv);
		if(au == av)continue;
		now ++;
		fa[au] = av,fa[au] = Gfa(av); 
		ans += G[i].w;
		if(now == n + k - 1) break;
	}
	cout << ans << "\n";
}

ll subtask3(ll kkk){
	for(int i = 1; i <= kkk; i++)
		for(int j = 1; j <= n; j++)
			G[m + (i - 1) * n + j].u = j,G[m + (i - 1) * n + j].v = n + i,G[m + (i - 1) * n + j].w = Q[i].a[j]; 
			
	sort(G + 1,G + 1 + m + n * kkk,cmp);
	int now = 0;
	ll ans = 0;
	for(int i = 1; i <= m + n * kkk; i++){
		int uu = G[i].u,vv = G[i].v;
		int au = Gfa(uu),av = Gfa(vv);
		if(au == av)continue;
		now ++;
		fa[au] = av,fa[au] = Gfa(av); 
		ans += G[i].w;
		if(now == n + kkk - 1) break;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= n + k; i++) fa[i] = i;
	for(int i = 1; i <= m; i++){
		int u,v,w;
		cin >> u >> v >> w;
		if(u > v) swap(u,v);
		G[i].u = u,G[i].v = v,G[i].w = w;
	}
	bool can = 1;
	for(int i = 1; i <= k; i++){
		cin >> Q[i].c;
		if(Q[i].c) can = 0; 
		for(int j = 1; j <= n; j++){
			cin >> Q[i].a[j];
		}
	}
	if(k == 0) subtask1();
	else if(can) subtask2();
	else{
		ll ans = 999999999999;
		for(int i = 0; i <= k; i++){
			for(int j = 1; j <= n + k; j++) fa[j] = j;
			ll out = subtask3(i);
			for(int j = 1; j <= i; j++) out += Q[i].c;
			ans = min(ans,out); 
		}
		cout << ans << "\n";
	}
	return 0;
}
/*
6 7 0
2 1 2
3 2 4
3 1 3
1 4 100
4 5 5
5 6 100
4 6 100

4 4 2
4 1 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

4 4 1
4 1 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4

5 6 0
1 2 2
1 3 10
1 4 9
2 4 3
2 5 5
4 5 3

4 4 2
1 4 8
2 3 7
4 2 5
4 3 4
0 9 2 7 9
0 7 4 9 10
*/
