#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,u[1000001],v[1000001],w[1000001],sum = 0;
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 0;i < m;++i){
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
		sum += w[i];
	}
	printf("%d",sum);
	return 0;
}
