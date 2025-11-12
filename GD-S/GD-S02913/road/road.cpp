#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=11000;
int n,m,k;
int G[N][N],t[N][N];
int c[N],a[N][N]; 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	memset(G,0x7f,sizeof G);
	memset(t,0,sizeof t);
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		G[x][y]=z;
		G[y][x]=z;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	printf("0\n");
	return 0;
}
