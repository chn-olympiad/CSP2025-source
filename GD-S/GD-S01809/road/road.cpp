#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[1005][1005],inf=1000000009,c[1005],a1[1005][1005],max1,max2;
int main(){	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=inf;
			if(i==j){
				a[i][j]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		long long v,u,w;
		scanf("%lld%lld%lld",&v,&u,&w);
		a[v][u]=w;
		a[u][v]=w;
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a1[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int z=1;z<=n;z++){
			if(a[i][z]!=inf){
				for(int j=1;j<=n;j++){
					if(a[z][j]!=inf){
						a[i][j]=min(a[i][j],a[i][z]+a[z][j]);
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int z=1;z<=k;z++){
			for(int j=1;j<=n;j++){
				if(a1[z][j]+a1[z][i]+c[z]<=a[i][j]&&i!=j){
					a[i][j]=a1[z][j]+a1[z][i]+c[z];
					a1[z][j]=0,a1[z][i]=0,c[z]=0;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			max1+=a[i][j];
		}
	}
	cout<<max1;
	return 0;
}
