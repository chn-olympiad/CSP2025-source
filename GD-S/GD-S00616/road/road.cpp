#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
int n,m,k;
int f[10010];
int find(int x){
	if(f[x] == x)return x;
	return f[x] = find(f[x]);
}
struct node{
	int x,y,z;
}g[1000010];
bool cmp(node x,node y){
	return x.z < y.z;
}
int c[10010];
int a[10010][10010];
int ans = 0;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i<=m;i++){
		scanf("%d%d%d",&g[i].x,&g[i].y,&g[i].z);
		if(g[i].x > g[i].y)swap(g[i].x,g[i].y);
	}
	for(int i = 1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j = 1;j<=n;j++){
			scanf("%d",&a[i][j]);
		} 
	}
	sort(g+1,g+1+m,cmp);
	for(int i = 1;i<=n;i++){
		f[i] = i;
	}
	for(int i = m;i>=1;i--){
		if(g[i].x <= k){
			g[i].z = min(g[i].z,c[g[i].x] + a[g[i].x][g[i].y]);
		}
		else if(g[i].y <= k){
			g[i].z = min(g[i].z,c[g[i].y] + a[g[i].x][g[i].y]);
		}
	}
	sort(g+1,g+1+m,cmp);
	for(int i = 1;i<=m;i++){
		int u = find(g[i].x);
		int v = find(g[i].y);
		if(u != v){
			f[g[i].x] = f[g[i].y];
			f[u] = f[v];
			ans += g[i].z;
		}
	}
	printf("%d",ans);
	return 0;
}
