#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
	 } 
	 for(int i=1;i<=k;i++)
	 {
	 	scanf("%d",&c[i]);
	 	for(int i=1;i<=n;j++)
	 	scanf("%d",&a[i][j]);
	 }
	return 0;
} 
