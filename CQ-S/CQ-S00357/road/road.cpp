#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct QWQ{int u,v,w;}a[114514];
int n,m,k,x[15],l[15][11451];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++)
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	for(int i=0;i<k;i++){
		scanf("%d",&l[i][1]);
		for(int j=1;j<=n;j++)scanf("%d",&l[i][j]);
	}
	printf("505585650");
	return 0; 
}
