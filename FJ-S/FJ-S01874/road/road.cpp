#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[10005],v[10005],w[10005],k[10005];
struct ro{
	int x,y,prime;
}roaist[10005];
bool rot[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&roaist[i].x,&roaist[i].y,&roaist[i].prime);
	}
	return 0;
}
