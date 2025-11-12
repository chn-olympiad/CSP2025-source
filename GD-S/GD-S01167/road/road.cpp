#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,c,w[1000001];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w[i]);
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++) scanf("%d",&c);
	}
	sort(w+1,w+m+1);
	c=0;
	for(int i=1;i<=m-k;i++){
		c+=w[i];
	}
	printf("%d\n",c);
	return 0;
}
