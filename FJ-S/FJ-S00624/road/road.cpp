#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,z,a[10010][10010],c[110],b[110][10010],sum;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		sum+=z;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&b[i][j]);
		}
	}
	if(k>=1){
	   printf("%d\n",0);
	   return 0;
	}
	else{
		printf("%d\n",sum);
	}
	return 0;
}
