#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10,M = 1e6 + 10;
struct edge{
	int u,v,w;
} e[15][M],et[M+N];
int n,m,k,c[15],sum,len,fa[N],ans = 0x3f3f3f3f;

int find(int x)
{
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

bool cmp(edge x,edge y)
{
	return x.w < y.w;
}

void kru()
{
	int cnt = 0;
	for(int i = 1; i <= len; i++){
		int u = et[i].u,v = et[i].v,w = et[i].w;
		int fu = find(u),fv = find(v);
		if(fu == fv) continue;
		fa[fv] = fu;
		cnt++;
//		cout << w << "\n";
		sum += w;
		if(cnt > n) return;
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1,u,v,w; i <= m; i++){
		scanf("%d%d%d",&u,&v,&w);
		e[0][i] = {u,v,w};
	}
	for(int i = 1; i <= k; i++){
		scanf("%d",&c[i]);
		for(int j = 1,w; j <= n; j++){
			scanf("%d",&w);
			e[i][j] = {n + k,j,w};
		}
	}
	for(int i = 1; i <= 2 * n; i++) fa[i] = i;
	for(int i = 1; i <= m; i++) et[i] = e[0][i];
	sort(et + 1,et + 1 + m,cmp);len = m;
//	for(int i = 1; i <= m; i++) printf("%d %d %d\n",et[i].u,et[i].v,et[i].w);
	kru();
//	printf("%d\n",sum);
	ans = min(ans,sum);
	for(int i = 1; i <= k; i++){
		len = m;sum = c[i];
		for(int j = 1; j <= 2 * n; j++) fa[j] = j;
		for(int j = 1; j <= n; j++){
			et[++len] = e[i][j];
		}
		sort(et + 1,et + 1 + len,cmp);
		kru();
		ans = min(ans,sum);
	}
	printf("%d\n",ans);
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
