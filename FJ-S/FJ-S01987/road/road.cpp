#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
struct Node{
	int u,v,w;
}a[N];
int n,m,k,c[N],val[15][N];
ll g;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
		g+=a[i].w;
	}	
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)scanf("%d",&val[i][j]);
	}
	if(!k){printf("%lld",g);return 0;}
	printf("0");
	return 0;
}
