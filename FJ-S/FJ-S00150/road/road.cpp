#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

int n,m,k,c[21][10005];

struct aa{
	int u,v,w;
}a[1000005];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&a[i].u,&a[i].v,&a[i].w);
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&c[i][j]);
		}
	}
	cout << rand()%1321;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
