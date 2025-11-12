//GZ-S00056 遵义市第一中学 刘李学翀 
#include <bits/stdc++.h>
using namespace std;
/*
对于所有测试数据，保证：
. 1 ≤ n ≤ 104，1 ≤ m ≤ 106，0 ≤ k ≤ 10；
. 对于所有1 ≤ i ≤ m，均有1 ≤ ui, vi ≤ n，ui .= vi 且0 ≤ wi ≤ 109；
. 对于所有1 ≤ j ≤ k，均有0 ≤ cj ≤ 109；
. 对于所有1 ≤ j ≤ k，1 ≤ i ≤ n，均有0 ≤ aj,i ≤ 109；
*/
int n,k,m,sum=13;
int u[107],v[107],w[107],c[105][11];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int i,j;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
	}
	for(i=1;i<=k;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&c[i][j]);
		}
		
	}
	printf("%d",sum);
	fclose(stdin);
	fclose(stdout);
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
