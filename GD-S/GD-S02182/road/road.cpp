#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10,M = 1e6 + 10;
typedef long long LL;

int n,m,k;
struct edge{
	int u,v,w;
}a[M]; 
int c[11],r[11][N];
int fa[N];
LL ans = 0;

bool cmp(edge e1,edge e2){
	return e1.w < e2.w;
}

int find(int x){
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void merge(int x,int y){
	int fx = find(x);
	int fy = find(y);
	if(fx != fy) fa[fx] = fy;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	
	for(int i = 1;i <= m;i++) scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	sort(a + 1,a + m + 1,cmp);

	for(int i = 1;i <= k;i++){
		scanf("%d",&c[i]);
		for(int j = 1;j <= n;j++){
			scanf("%d",&r[i][j]);
		}
	}
	
	for(int i = 1;i <= n;i++) fa[i] = i;

	int cnt = 0;
	for(int i = 1;i <= m;i++){
		if(cnt == n - 1) break;
		if(find(a[i].u) != find(a[i].v)){
			cnt++;
			merge(a[i].u,a[i].v);
			ans += a[i].w;
		}
	}
	printf("%d",ans);	
	
	return 0;
}

