#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
const int K = 15;
struct edge{
	int u,v,w;
	bool operator < (const edge &t)const{
		return w < t.w;
	}
}e[N];
int fa[N];
int n,m,k; 
int ans = 0,cnt = 0;
int find(int x){
	if(fa[x] == x){
		return x;
	}return fa[x] = find(fa[x]);
}
bool kruskal(){
	sort(e, e + m);
	for(int i = 1;i<=n;i++){fa[i] = i;}
	for(int i = 1;i<m;i++){
		int x = find(e[i].u);
		int y = find(e[i].v);
		if(x != y){
			fa[x] = y;
			ans += e[i].w;
			cnt++;
		}
	}return cnt == n - 1;
}
//int n,m,k;
int c[K][N];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i<=m;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	}//超级原点
	for(int i = 1;i<=k;i++){
		scanf("%d",&c[i][0]);
		for(int j = 1;j<=n;j++){
			scanf("%d",&c[i][j]);
		}
	}
	bool flag = kruskal();
	if(flag){
		printf("%d",ans);
	}
	return 0;
}