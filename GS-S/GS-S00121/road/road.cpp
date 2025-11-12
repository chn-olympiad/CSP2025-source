#include <bits/stdc++.h>
using namespace std;
struct node{
	int u,v,w;
}a[1000015];
long long ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i <= m;i++){
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
		ans += a[i].w;
	}
	for(int i = 1,x;i <= k;i++){
		scanf("%d",&x);
		for(int j = 1;j <= n;j++){
			a[j+m].u = x;
			scanf("%d",&a[j+m].w);
			a[j+m].v = j;
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
