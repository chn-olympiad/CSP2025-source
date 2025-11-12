#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
int f[10300][10300];
int a[10030][10030];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		a[u][v]=w;
		a[v][u]=w;
		if(a[u][v]!=0){
			a[u][v]=a[v][u]=min(a[u][v],w);
		}
	}
	for(int i=1;i<=k;i++){
		int c;
		scanf("%lld",&c);
		int x[10030];
		for(int j=1;j<=n;j++){
			scanf("%lld",&x[j]);
		}
		for(int j=1;j<=n;j++){
			for(int t=j+1;t<=n;t++){
				if(a[j][t]==0){
					a[j][t]=2147483647;
				}
				a[j][t]=a[t][j]=min(a[t][j],x[j]+x[t]);
			}
		}
	}
	for(int kk=1;kk<=n;kk++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][kk]+f[kk][j]);
			}
		}
	}
	int ans=0;
	for(int i=1;i<n;i++){
		ans+=f[i][i+1];
	}
	printf("%lld",ans);
	return 0;
}
