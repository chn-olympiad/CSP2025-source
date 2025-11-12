#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int n,m,k;
int pre[maxn],cou,ans;
struct edge{
	int u,v,w;
}vec[2 * maxn];
int c[15],a[15][maxn];
int t = 1;
bool cmp(edge x,edge y) {
	return x.w < y.w;
}
int find(int x) {
	if(x == pre[x]) {
		return x;
	}
	x = find(pre[x]);
	return x;
}
void kru(int s) {
	sort(vec + 1,vec + t + 1,cmp);
	for(int i = 1;i <= t;i++) {
		int f1 = find(vec[i].u);
		int f2 = find(vec[i].v);
		if(f1 == f2) continue;
		else {
			cou++;
			pre[f1] = f2;
			ans += vec[i].w;
			if(cou == n - 1) break;
		}
	}
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i <= m;i++) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		vec[t].u = u;
		vec[t].v = v;
		vec[t].w = w;
		t++;
		vec[t].u = v;
		vec[t].v = u;
		vec[t].w = w;
	}
	for(int i = 1;i <= k;i++) {
		scanf("%d",&c[i]);
		for(int j = 1;j <= n;j++) {
			scanf("%d",&a[i][j]);
		}
	}
	for(int i = 1;i <= n;i++) {
		pre[i] = i;
	}
	kru(1);
	printf("%d",ans);
	return 0;
}
