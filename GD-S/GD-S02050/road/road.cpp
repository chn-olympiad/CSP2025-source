#include<bits/stdc++.h>
#define int unsigned long long
#define getchar() getchar_unlocked()
const int N = 1e4 + 6;
void read(int& x){
	x = 0; int f = 1; char ch = getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch == '-') f = -1;
	for(;isdigit(ch);ch=getchar()) x = (x << 3) + (x << 1) + (ch ^ 48);
	x *= f; 
}
void print(int x){
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) print(x / 10);
	putchar(x%10+48);
}
int n,m,k,add[11][N],ans;
struct edge{
	int from,to,val;
};
std::vector<edge> graph;
struct bingchaji{
	int fa[N],siz[N];
int find(int u){
	return (fa[u] == u) ? u : fa[u] = find(fa[u]);
}
void Union(int x,int y){
	int nx = find(x), ny = find(y);
	if(nx == ny) return;
	if(siz[nx] > siz[ny]) fa[ny] = nx, siz[nx] += siz[ny];
	else fa[nx] = ny, siz[ny] += siz[nx];
}
}bcj;
signed main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	read(n); read(m); read(k);
	for(int i=1;i<=n;i++) bcj.fa[i] = i, bcj.siz[i] = 1;
	for(int i=1;i<=m;i++){
		int u, v, w;
		read(u); read(v); read(w);
		graph.push_back((edge){u, v, w});
	}
	for(int i=1;i<=k;i++)
		for(int j=0;j<=n;j++)
			read(add[i][j]);
			
	// add edges
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int kk=1;kk<=k;kk++)
				if(i == j) continue;
				else graph.push_back((edge){i, j, add[kk][0] + add[kk][i] + add[kk][j]});
			
	std::sort(graph.begin(), graph.end(), [](edge a,edge b){
		return a.val < b.val;
	});
	
	int cnt = 1;
	for(edge cur:graph){
		if(cnt == n) break;
		if(bcj.find(cur.from) == bcj.find(cur.to)) continue;
		bcj.Union(cur.from, cur.to); cnt++; ans += cur.val;
	}
	print(ans);
	
	return 0;
}
