#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxm = 1100010;
const int maxn = 10100;
struct edge{
	int u,v;
	long long w;
}b[maxm],d[maxm];
long long c[maxn],a[15][maxn];
int p[maxn];
int n,m,k,n1;
long long ans = 1e18,now;
int find(int x){
	if(x == p[x]) return x;
	return p[x] = find(p[x]);
}
bool cmp(edge x,edge y){
	return x.w < y.w;
}
void Kruskal(){
	for(int i=1;i<=n1;i++) p[i] = i;
	for(int i=1;i<=m;i++) d[i] = b[i];
	sort(d+1,d+m+1,cmp);
	for(int i=1;i<=m;i++){
		int x = find(d[i].u), y = find(d[i].v);
		if(x != y){
			p[x] = y;
			now += d[i].w;
		}
	}
}
void dfs(int cur,long long sum){
	if(sum >= ans) return;
	if(cur > k){
		now = 0;
		Kruskal();
		ans = min(ans,now+sum);
		return;
	}
	dfs(cur+1,sum);
	for(int i=1;i<=n;i++){
		b[++m].u = i,b[m].v = cur+n;
		b[m].w = a[cur][i];
	}
	n1++;
	dfs(cur+1,sum+c[cur]);
	n1--;
	m -= n;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	n1 = n;
	for(int i=1;i<=m;i++){
		scanf("%d%d%lld",&b[i].u,&b[i].v,&b[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	if(k == 0){
		Kruskal();
		printf("%lld",now);
		return 0;
	}
	if(k <= 5){
		dfs(1,0);
		printf("%lld",ans); 
		return 0;
	}
	bool ok = true;
	for(int i=1;i<=k;i++){
		if(c[i] != 0) ok = false;
	}
	if(ok){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				b[++m].u = i+n,b[m].v = j;
				b[m].w = a[i][j];
			}
		}
		n1 += k;
		Kruskal();
		printf("%lld",now);
		return 0;
	}
	return 0;
}
