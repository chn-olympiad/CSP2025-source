#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u[1000000],v[1000000],w[1000000];
int c[10],a[10][10000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
	}for(int i=0;i<k;i++){
		scanf("%d",&c[i]);
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	return 0;
}
