#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
const int M = 1e6+10;
int n,m,k;
int fa[N];
long long ans;
struct node{
	int x,y;
	long long v;
}edge[M];
bool cmp(node a,node b){
	return a.v < b.v;
}
struct t{
	int to;
	long long v;
};
t c[15][N];
vector<t> tree[N];
bool compare(t a,t b){
	return a.v<b.v;
}
int mi[N][N];
int use_pos[15];
void init(){
	memset(mi,-0x3f,sizeof mi);
	for(int i=1;i<=n;i++) fa[i]=i;
}
int find(int x){
	return (fa[x]==x?x:(fa[x]=find(fa[x])));
}
void krush(){
	sort(edge+1,edge+1+m,cmp);
	int com = 0;
	for(int i=1;i<=m;i++){
		if(com==n-1) return ;
		int x = edge[i].x, y = edge[i].y;
//		cout << x << " " << y << endl;
//		cout << "a" << ans << endl;
//		cout << "xy" << x << " " << y << endl;
//		cout << fa[x] << "----" << fa[y] << endl;
		int fx = find(x), fy = find(y);
//		cout << "ff " << fx << " " << fy << endl;
		if(fx!=fy){
			fa[x] = fa[y];
			tree[x].push_back({y,edge[i].v});
			tree[y].push_back({x,edge[i].v});
//			cout << edge[i].v <<"===="<< endl;
			ans += edge[i].v;
			com ++ ;
		}
	}
}
void dfs(int u,int f){
	for(t x:tree[u]){
		if(x.to!=f){
			if(tree[x.to].size()==1){
				mi[u][x.to] = mi[x.to][u] = x.v;
				return ;
			}
			dfs(x.to,u);
			for(int i=1;i<=n;i++){
				if(i==u) continue;
				if(mi[x.to][i]!=-0x3f3f3f3f) {
					mi[u][i]=mi[i][u]=max(x.v,mi[x.to][i]*1ll);
				}
			}
		}
	}
}
struct e{
	int x,y,v,pos;
};
bool ccmp(e a,e b){
	return a.v<b.v;
}
void mountain(int x,int y){
	dfs(x,y);
	dfs(y,x);
}
void ans_pos(){
	for(int i=1;i<=k;i++){
		sort(c[i]+1,c[i]+1+n,compare);
	}
	while(1){
		vector<e> m;
		for(int i=1;i<=k;i++){
			if(use_pos[i]==n) continue;
//			cout << "pppp" << endl;
			m.push_back({c[i][use_pos[i]].to,c[i][use_pos[i]+1].to,
			c[i][use_pos[i]].v+c[i][use_pos[i]+1].v+c[i][0].v-mi[c[i][use_pos[i]].to][c[i][use_pos[i]+1].to],
			i});
		}
		sort(m.begin(),m.end(),ccmp);
		if(m.empty()||m[0].v > 0) break;
		else ans += m[0].v,use_pos[m[0].pos]++/*,mountain(m[0].x,m[0].y)*/;
//		cout << m[0].x << " " << m[0].y << " " << m[0].v << endl;;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
//	cout << "m" << m << endl;
	init();
	for(int i=1;i<=m;i++){
		scanf("%d %d %lld",&edge[i].x,&edge[i].y,&edge[i].v);
//		cout << edge[i].v << endl;
	}
	for(int i=1;i<=k;i++){
		use_pos[i]=1;
		scanf("%lld",&c[i][0].v);
		for(int j=1;j<=n;j++) scanf("%lld",&c[i][j].v),
		c[i][j].to = j;
	}
	krush();
//	cout << ans << endl;
	if(k==0){
		cout << ans;
		return 0;
	}
	dfs(1,0);
	ans_pos();
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
