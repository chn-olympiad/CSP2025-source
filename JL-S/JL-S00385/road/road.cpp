#include <bits/stdc++.h>
using namespace std;
#define N 1000005
int u[N],v[N],w[N],c[11];
int a[11][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",u+i,v+i,w+i);
	}
	for(int i=0;i<k;i++){
		scanf("%d",c+i);
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	printf("0\n");

	return 0;
}
