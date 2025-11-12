#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,k,fx,fy,cnt,fa[10005],c[15],a[15][10005];
long long ans;
bool task,flag;
struct edge{
	int u,v;
	long long w;
}e[2000005];
bool cmp(edge &a,edge &b){
	return a.w < b.w;
}
int find(int a){
	if(fa[a] == a) return a;
	return fa[a] = find(fa[a]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i <= n;i++) fa[i] = i;
	while(m--){
		cnt ++;
		scanf("%d%d%lld",&e[cnt].u,&e[cnt].v,&e[cnt].w);
	}
	for(int i = 1;i <= k;i++){
		scanf("%d",&c[i]);
		task = false;
		if(c[i] != 0) flag = false;
		else flag = true;
		for(int j = 1;j <= n;j++){
			scanf("%lld",&a[i][j]);
			if(a[i][j] == 0){
				task = true;
			}
		}
	}
	if(flag && task){
		for(int i = 1;i <= k;i++){
			for(int j = 1;j <= n;j++){
				if(a[i][j] == 0){
					for(int k = 1;k <= n;k++){
						e[++cnt] = {j,k,a[i][k]};
					}
				}
			}
		}
	}
	sort(e+1,e+cnt+1,cmp);
	for(int i = 1;i <= cnt;i++){
		fx = find(e[i].u);
		fy = find(e[i].v);
		if(fx != fy){
			fa[fy] = fx;
			ans += e[i].w;
		}
	}
	printf("%lld",ans);
	return 0;
}
