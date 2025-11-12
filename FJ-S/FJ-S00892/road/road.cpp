/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 3 1 2 4
*/
#include <cstdio>
#include <algorithm>
using namespace std;
int a[10005],cnt;
bool b[10005][10005];
struct edge{
	int u,v,w;
}e[4000005];
void add_edge(int u,int v,int w) {
	e[++cnt].u = u;
	e[cnt].v = v;
	e[cnt].w = w;
	e[++cnt].u = v;
	e[cnt].v = v;
	e[cnt].w = w;
	return;
}
bool cmp(edge e1,edge e2) {
	return e1.w < e2.w;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,u,v,w,t;
	long long sum = 0;
	scanf("%d%d%d",&n,&m,&k);
	for (int i = 1;i <= n;i++) {
		scanf("%d%d%d",&u,&v,&w);
		add_edge(u,v,w);
	}
	for (int i = 1;i <= k;i++) {
		scanf("%d",&t);
		for (int j = 1;j <= n;j++) {
			scanf("%d",&a[j]);
		}
		for (int j = 1;j <= n;j++) {
			for (int k = 1;k <= n;k++) {
				add_edge(i,k,a[j]+t+a[k]);
			}
		}
	}
	sort(e+1,e+cnt+1,cmp);
	for (int i = 1;i <= cnt;i++) {
		if (!b[e[i].u][e[i].v] && e[i].u != e[i].v) {
			sum += e[i].w;
			b[e[i].u][e[i].v] = true;
			b[e[i].v][e[i].u] = true;
			for (int j = 1;j <= n;j++) {
				if (b[j][e[i].u]) {
					b[j][e[i].v] = true;
					b[e[i].v][j] = true;
				}
				else if (b[j][e[i].v]) {
					b[j][e[i].u] = true;
					b[e[i].u][j] = true;
				}
			}
		}
	}
	printf("%lld",sum);
	return 0;
}
