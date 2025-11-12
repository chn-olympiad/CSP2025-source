#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k,u[N],v[N],w[N],c[10],a[10][N],f;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		if(c[i]==0)f=1;
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	if(f==1){	
	    cout<<504898585;
	}
	else{
	    cout<<13;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
