#include <bits/stdc++.h>
using namespace std;
 
int c[5000005][5000000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//ÊäÈë¹ý³Ì 
	int n,m,k;
	cin>>n>>m>>k;
	long long u[5000005],v[5000005],w[5000005];
	for(int i=1;i<=m;i++)cin>>u[i]>>v[i]>>w[i];
	
	for(int j=1;j<=k;j++){
		for(int a=1;a<=n+1;a++) cin>>c[j][a];
	}
	
	return 0;
} 
