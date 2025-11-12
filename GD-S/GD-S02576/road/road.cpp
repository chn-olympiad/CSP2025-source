# include <bits/stdc++.h>
using namespace std;
int n,m,k,u[1000005],v[1000005],w[1000005],c[15],a[15][10005],b[1000005][1000005],k[1000005][1000005],tot=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i<=m;i++){
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
		b[u[i]][v[i]]=1;
		b[v[i]][u[i]]=1;
		k[u[i]][v[i]]=w[i];
		k[v[i]][u[i]]=w[i];
		tot+=w[i];
	}
	for(int i = 1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j = 1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	cout<<tot;
	return 0;
}
