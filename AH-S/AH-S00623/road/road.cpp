#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans=INT_MAX;
struct node{
	int u,v,w;
}a[1000015];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	}
	for(int i=1;i<=k;i++){
		int c;
		scanf("%d",&c);
		for(int j=1;j<=n;j++){
			int t;
			scanf("%d",&t);
			a[i+m].u=n+i;
			a[i+m].v=j;
			a[i+m].w=t+c;
		}
		ans=min(ans,a[i+m].w);
	}
	printf("%d",ans);
	return 0;
}
