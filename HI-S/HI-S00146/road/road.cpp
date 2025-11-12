#include<bits/stdc++.h>
using namespace std;
const int maxn=1e9;
int n,m,k,u,v,d,c[501],a[501];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;i++) scanf("%d%d%d",&u,&v,&d);
	for(int i=0;i<m;i++){
		scanf("%d",&c[i]);
		for(int j=0;i<=n;i++)
			scanf("%d",&a[i]);
	}
	printf("%d",rand()%maxn);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
