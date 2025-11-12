#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u,v;long long w,sum=0;
long long a[1005][1005];
long long c[10],b[10][1005];
bool x[1005][1005]={ };
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	memset(a,127,sizeof(a));
	for(int i=1;i<=n;i++){
		a[i][i]=0;
	}
	for(int i=0;i<n;i++){
		scanf("%d %d %lld",&u,&v,&w);
		a[u][v]=min(a[u][v],w);
		a[v][u]=min(a[v][u],w);
	}
	for(int i=0;i<k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&b[i][j]);
		}
		for(int j=1;j<=n;j++){
			for(int p=1;p<=n;p++){
				a[j][p]=min(a[j][p],c[i]+b[i][j]+b[i][p]);
			}
		}
	}
	for(int t=1;t<=n;t++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				a[i][j]=min(a[i][j],a[i][t]+a[t][j]);
			}
		}
	}
	sum=a[1][n];
	printf("%lld",&sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
