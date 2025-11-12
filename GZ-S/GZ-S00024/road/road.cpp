//GZ-S00024 何彦辰 遵义市第四中学
#include <bits/stdc++.h>
using namespace std;
long long int n,m,k,x,z;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>k;
    int u[m+1],v[m+1],w[m+1],j[k+1][n+2],a[n+1];
    for(int i=1;m<=i;i++){
    	cin>>u[i]>>m[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n){
		if(z[u[i]]<2&&z[v[i]]<2){
			x+=w[i];
		}
	}
	cout<<x;
	fclose(stdin);
	fclose(stdout);
}

