#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 25,M = 2e6 + 25;
int n,m,k;
long long ans = 1e16;
typedef pair<int,int> PII;
int a[15],dis[15][N],st[15];
struct Node{
	int u,v,x;
}g[M],g1[M];
bool cmp(Node A,Node B){
	return A.x < B.x;
}
int p[N];
int find(int x){
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}
long long krus(int dian,int bian){
	long long x = 0,c = 0;
	for(int i = 1; i <= dian; i++) p[i] = i;
	sort(g1 + 1,g1 + 1 + bian,cmp);
	for(int i = 1; i <= bian; i++){
		int u = g1[i].u,v = g1[i].v;
		long long w = g1[i].x;
		u = find(u),v = find(v);
		if(u == v) continue;
		p[u] = v;
		x += w;
		c++;
		if(c == dian) break;
	}
	return x;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		int u,v,w;
		cin >> u >> v >> w;
		g[i] = {u,v,w};
	}
	for(int i = 1; i <= k; i++){
		cin >> a[i];
		for(int j = 1; j <= n; j++){
			cin >> dis[i][j];
		}
	}
	for(int i = 1; i <= k; i++){
		if(st[i]) continue;
		for(int j = i + 1; j <= k; j++){
			if(st[j]) continue;
			int res = a[i] - a[j];
			for(int l = 1; l <= n; l++){
				res = res + dis[i][l] - dis[j][l];
			}
			if(a[i] >= a[j]) st[i] = 1;
		}
	}
	int top1 = 0,b1[15] = {0};
	for(int i = 1; i <= n; i++){
		if(!st[i]){
			b1[++top1] = a[i];
			memcpy(dis[top1],dis[i],sizeof dis[top1]);
		}
	}
	memcpy(a,b1,sizeof b1);
	k = top1;
	long long res = 0;
	int cnt = n,top = m;
	for(int i = 0; i < (1 << k); i++){
		memcpy(g1,g,sizeof g);
		res = 0,cnt = n,top = m;
		for(int j = 0; j < k; j++){
			if((i >> j & 1) == 0) continue;
			res += a[j + 1];
			cnt++;
			for(int l = 1; l <= n; l++){
				g1[++top] = {cnt,l,dis[j + 1][l]};
			}
		}
		res += krus(cnt,top);
		ans = min(ans,res);
		if((double)clock() / CLOCKS_PER_SEC >= 0.9) break;
	}
	cout << ans;
	return 0;
} 
